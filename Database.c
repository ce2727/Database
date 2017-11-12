#include "Database.h"


Database* Database_new()
{
  Database* new = (Database*)calloc(1,sizeof(Database));//Allocating one database
  return new;
}


/*
  Helper fn's ------------------------------------------------
*/

int hash(int input)
{
  return input % 1009;
}

int courseToInt(char* Course)
{
  int pile = 0;

  for(int i = 0; i < 6; i++)
  {
    pile += (int)Course[i];
  }
}

/*
  Insert Functions -------------------------------------------
*/

void insert_SNAP(Database* D, SNAP* toInsert)
{
  //Which Bucket? Hashes on inserted SNAP's StudentId
  int index = hash(toInsert->StudentId);

  if (D->SNAPTable[index] == NULL)
  {
    //Fresh, empty Bucket
    D->SNAPTable[index] = toInsert;
  } else
  {
    //Already a member(s) in bucket
    SNAP* currentHead = D->SNAPTable[index];
    toInsert->next = currentHead;
    D->SNAPTable[index] = toInsert;
  }
}

void insert_CSG(Database* D, CSG* toInsert)
{
  //Which Bucket? Hashes on inserted CSG's StudentId
  int index = hash(toInsert->StudentId);

  if (D->CSGTable[index] == NULL)
  {
    //Fresh, empty Bucket
    D->CSGTable[index] = toInsert;
  } else
  {
    //Already a member(s) in bucket
    CSG* currentHead = D->CSGTable[index];
    toInsert->next = currentHead;
    D->CSGTable[index] = toInsert;
  }
}

void insert_CP(Database* D, CP* toInsert)
{
  //Which Bucket? Hashes on inserted CP's StudentId
  int courseAsInt = courseToInt(toInsert->Course);
  int index = hash(courseAsInt);

  if (D->CPTable[index] == NULL)
  {
    //Fresh, empty Bucket
    D->CPTable[index] = toInsert;
  } else
  {
    //Already a member(s) in bucket
    CP* currentHead = D->CPTable[index];
    toInsert->next = currentHead;
    D->CPTable[index] = toInsert;
  }
}

void insert_CDH(Database* D, CDH* toInsert)
{
  //Which Bucket? Hashes on inserted CDH's StudentId
  int courseAsInt = courseToInt(toInsert->Course);
  int index = hash(courseAsInt);

  if (D->CDHTable[index] == NULL)
  {
    //Fresh, empty Bucket
    D->CDHTable[index] = toInsert;
  } else
  {
    //Already a member(s) in bucket
    CDH* currentHead = D->CDHTable[index];
    toInsert->next = currentHead;
    D->CDHTable[index] = toInsert;
  }
}

void insert_CR(Database* D, CR* toInsert)
{
  //Which Bucket? Hashes on inserted CR's StudentId
  int courseAsInt = courseToInt(toInsert->Course);
  int index = hash(courseAsInt);

  if (D->CRTable[index] == NULL)
  {
    //Fresh, empty Bucket
    D->CRTable[index] = toInsert;
  } else
  {
    //Already a member(s) in bucket
    CR* currentHead = D->CRTable[index];
    toInsert->next = currentHead;
    D->CRTable[index] = toInsert;
  }
}

/*
  Delete Functions -------------------------------------------
*/

void delete_SNAP(Database* D, SNAP* toDelete)
{
  int index = hash(toDelete->StudentId);

  if (D->SNAPTable[index] == NULL) return; //Not found

  if (equal_SNAP(D->SNAPTable[index], toDelete))//If it's the first in bucket
  {
    SNAP* toFree = D->SNAPTable[index];
    D->SNAPTable[index] = D->SNAPTable[index]->next;
    //CHECK HERE IF GETTING CRASHES!!!!!!!!!//TODO
    free(toFree);
  }

  //Time to check through the list
  //For each SNAP in the bucket
  for (SNAP* iter = D->SNAPTable[index]; iter->next != NULL; iter = iter->next)
  {
    if (equal_SNAP(toDelete, iter->next))//If we've found the matching entry as iter's next
    {
      SNAP* toFree = iter->next;
      iter->next = iter->next->next;//Create a new link in the list that bypasses the deleted node
      free(toFree);//Free the deleted data
    }
  }
}
