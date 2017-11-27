#include "Algebra.h"

//Relational Algebra: Select function for ID's on CSG structs
CSG** select_CSG(Database* D, char* ID)
{
  CSG** flatCSG = (CSG**)calloc(200, sizeof(CSG*));
  int CSGIndex = 0;
  for(int p = 0; p < TABLESIZE; p++){
    for (CSG* iter = D->CSGTable[p]; iter != NULL; iter = iter->next)
    {
      if(strcmp(iter->StudentId,ID)==0){
        flatCSG[CSGIndex] = iter;
        CSGIndex++;
      }
    }
  }
  return flatCSG;
}


//Relational Algebra: Join function between CR and CDH
CRDH** join_CR_CDH(CR** CRS, CDH** CDHS)
{
  int rIndex = 0;
  CRDH** retVal = (CRDH**)calloc(500, sizeof(CRDH*));
  for (int r = 0; r < TABLESIZE; r++)
  {
    if (CRS[r] != NULL)
    {
      for (int t = 0; t < TABLESIZE; t++)
      {
        if (CDHS[t] != NULL)
        {
          //For every matchup of entries (that aren't null)
          //If the course matches
          if (strcmp(CRS[r]->Course,CDHS[t]->Course)==0)
          {
            //Create a CRDH and check if it already exists in the list
            CRDH* toAdd = CRDH_new(CRS[r]->Course, CRS[r]->Room, CDHS[t]->Day, CDHS[t]->Hour);

            int found = 0;
            for (int i = 0; i < 500 && found == 0; i++)
            {
              //If we found that the entry that already exists
              if (retVal[i] != NULL && equal_CRDH(retVal[i],toAdd))
              {
                found = 1;
              }
            }

            if (!found)
            {
              retVal[rIndex] = toAdd;
              rIndex++;

            } else free(toAdd);
          }
        }
      }
    }
  }
  if (retVal == NULL) return NULL;
  return retVal;
}


//Relational Algebra: Join function between CSG and CRDH
CSGRDH** join_CSG_CRDH(CSG** CSGS, CRDH** CRDHS)
{
  int rIndex = 0;
  CSGRDH** retVal = (CSGRDH**)calloc(500, sizeof(CSGRDH*));
  for (int r = 0; r < TABLESIZE; r++)
  {
    if (CSGS[r] != NULL)
    {
      for (int t = 0; t < TABLESIZE; t++)
      {
        if (CRDHS[t] != NULL)
        {
          //For every matchup of entries (that aren't null)
          //If the course matches
          if (strcmp(CSGS[r]->Course,CRDHS[t]->Course)==0)
          {
            //Create a CRDH and check if it already exists in the list
            CSGRDH* toAdd = CSGRDH_new(CSGS[r]->Course, CSGS[r]->StudentId, CSGS[r]->Grade, CRDHS[r]->Room, CRDHS[t]->Day, CRDHS[t]->Hour);

            int found = 0;
            for (int i = 0; i < 500 && found == 0; i++)
            {
              //If we found that the entry that already exists
              if (retVal[i] != NULL && equal_CSGRDH(retVal[i],toAdd))
              {
                found = 1;
              }
            }

            if (!found)
            {
              retVal[rIndex] = toAdd;
              rIndex++;
            }
          }
        }
      }
    }
  }
  if (retVal == NULL) return NULL;
  return retVal;
}
