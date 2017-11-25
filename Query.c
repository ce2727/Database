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
    CSG** eCourses = lookup_CSG(D, CSG_new("*",ID,"*"));

    //Get the Course Rooms of all enrolled courses
      CDH** tCourses = (CDH**)calloc(TABLESIZE,sizeof(CDH*));
      int cdhIndex = 0; //Current index of the CDH list
      for (int e = 0; e < QUERY_RETURN_SIZE; e++)
      {
        if (eCourses[e] != NULL)//Check for empty entry
        {
          //For each CDH bucket
          for (int b = 0; b < TABLESIZE; b++)
          {
            //Check list
            for (CDH* iter = D->CDHTable[b]; iter != NULL; iter = iter->next)
            {
              if (strcmp(iter->Course,eCourses[e]->Course) == 0)//If there's a course match
              {
                tCourses[cdhIndex] = iter;//Add it to the list
                cdhIndex++;
              }
            }
          }
        }
      }

    //Get the Course Rooms of all enrolled courses
    CR** rCourses = (CR**)calloc(TABLESIZE,sizeof(CR*));
    int crIndex = 0; //Current index of the CR list
    for (int e = 0; e < QUERY_RETURN_SIZE; e++)
    {
      if (tCourses[e] != NULL)//Check for empty entry
      {
        //For each course room bucket
        for (int b = 0; b < TABLESIZE; b++)
        {
          //Check list
          for (CR* iter = D->CRTable[b]; iter != NULL; iter = iter->next)
          {
            if (strcmp(iter->Course,tCourses[e]->Course) == 0)//If there's a course match
            {
              rCourses[crIndex] = iter;//Add it to the list
              crIndex++;
            }
          }
        }
      }
    }
    printf("------------------------------------------\n");
    char* Location = rCourses[0]->Room;
    printf("| %s is at %s on %s at %s\n",nameptr, Location, dayptr, hourptr);
    printf("------------------------------------------\n");
  }
}
