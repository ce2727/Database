#include "Query.h"

char* Query(Database* D, char* input)
{
  char* whatStart = "What";
  char* whereStart = "Wher";

  //Output to be filled
  char NAME[7];
  char COURSE[7];
  char HOUR[5];
  char DAY[2];

  //Provide space for input to be segmented to
  char str[200];
  strcpy(str, input);//Copy it in for strtok


  if (strncmp(input,whatStart,4) == 0)//"What grade?" Query
  {
    char* split;
    split = strtok(str," ");
    char* nameptr = (char*)malloc(7*sizeof(char));
    char* courseptr = (char*)malloc(7*sizeof(char));
    int i = 0;
    while (split != NULL)
    {
      if (i == 3) strcpy(nameptr,split);
      if (i == 6) strcpy(courseptr,split);
      split = strtok (NULL, " ");//Pass NULL to pick up where it left off in split
      i++;
    }

    courseptr[strlen(courseptr)-1] = '\0';//Remove '?' from the course

    //Get ID from SNAP first
    char* ID = (lookup_SNAP(D,SNAP_new("*",nameptr,"*","*"))[0]->StudentId);

    //Use ID to get Grades in the class
    CSG** Results = lookup_CSG(D, CSG_new(courseptr,ID,"*"));

    printf("------------------------------------------\n");
    for (int i = 0; i < QUERY_RETURN_SIZE; i++)
    {
      if (Results[i] != NULL)
      {
          printf("| %s recieved: %s in %s\n",nameptr,Results[i]->Grade,courseptr);
      }
    }
    printf("------------------------------------------\n");

  } else if (strncmp(input,whereStart,4) == 0)//Where is 'student name' at 'time' on 'day'? Query

  {

    char* split;
    split = strtok(str," ");
    char* nameptr = (char*)malloc(NAMELENGTH*sizeof(char));
    char* hourptr = (char*)malloc(HOURLENGTH*sizeof(char));
    char* dayptr = (char*)malloc(DAYLENGTH*sizeof(char));

    int i = 0;
    while (split != NULL)
    {
      if (i == 2) strcpy(nameptr,split);
      if (i == 4) strcpy(hourptr,split);
      if (i == 6) strcpy(dayptr,split);
      split = strtok (NULL, " ");//Pass NULL to pick up where it left off in split
      i++;
    }

    dayptr[strlen(dayptr)-1] = '\0';//Remove '?' from the day

    //Get studentID from SNAP
    char* ID = (lookup_SNAP(D,SNAP_new("*",nameptr,"*","*"))[0]->StudentId);

    //Get student's enrolled courses from CSG
    CSG** eCourses = select_CSG(D, ID);

    for (int i = 0; i < TABLESIZE; i++)
    {
      if (eCourses[i] != NULL)
      {
        //printf("%s\n", eCourses[i]->Course);
      }
    }

    //Make flat lists for CSG and CDH's so join doesn't have to deal with buckets
    CSG** flatCSG = (CSG**)calloc(200, sizeof(CSG*));
    int CSGIndex = 0;
    for(int p = 0; p < TABLESIZE; p++){
      for (CSG* iter = D->CSGTable[p]; iter != NULL; iter = iter->next)
      {
        flatCSG[CSGIndex] = iter;
        CSGIndex++;
      }
    }


    //Make flat lists for CR and CDH's so join doesn't have to deal with buckets
    CR** flatCR = (CR**)calloc(200, sizeof(CR*));
    int crIndex = 0;
    for(int p = 0; p < TABLESIZE; p++){
      for (CR* iter = D->CRTable[p]; iter != NULL; iter = iter->next)
      {
        flatCR[crIndex] = iter;
        crIndex++;
      }
    }

    //Make flat lists for CR and CDH's so join doesn't have to deal with buckets
    CDH** flatCDH = (CDH**)calloc(200, sizeof(CDH*));
    int cdhIndex = 0;
    for(int p = 0; p < TABLESIZE; p++){
      for (CDH* iter = D->CDHTable[p]; iter != NULL; iter = iter->next)
      {
        flatCDH[cdhIndex] = iter;
        cdhIndex++;
      }
    }

      CRDH** CRDHList = join_CR_CDH(flatCR, flatCDH);
      CSGRDH** CSGRDHList = join_CSG_CRDH(eCourses, CRDHList);
      for (int i = 0; i < 500; i++)
      {
        if (CSGRDHList[i] != NULL)
        {
          if(strcmp(CSGRDHList[i]->Day,dayptr)== 0 && strcmp(CSGRDHList[i]->Hour,hourptr)==0)
          {
            printf("----------------------------------------\n");
            printf("| %s is at %s on %s at %s \n", nameptr,CSGRDHList[i]->Room,dayptr,hourptr);
            printf("----------------------------------------\n");
          }
        }
      }
  }
}
