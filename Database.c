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

int stringToInt(char* string)
{
  int pile = 0;

  for(int i = 0; i < 6; i++)
  {
    pile += (int)string[i];
  }
}

/*
  Lookup Functions -------------------------------------------
*/

//SNAP Lookup----------------------------------
SNAP** lookup_SNAP(Database* D, SNAP* toLookup)
{
  int index = hash(stringToInt(toLookup->StudentId));
  SNAP** retList = (SNAP**)calloc(QUERY_RETURN_SIZE,sizeof(SNAP*));

  int i = 0;//Helps to index pointers in double pointer
  for (SNAP* iter = D->SNAPTable[index]; iter != NULL; iter = iter->next)
  {
    if (equal_SNAP(toLookup, iter))//If we've found the matching entry as iter
    {
      retList[i] = iter;
      //printf("Found match, adding %s to list!\n",iter->Address);
      i++;
    }
  }
  if (retList[0] == NULL) return NULL;//If list is empty, return null directly
  return retList;
}//--------------------------------------------

//CSG Lookup
CSG** lookup_CSG(Database* D, CSG* toLookup)
{
  int index = hash(stringToInt(toLookup->StudentId));
  CSG** retList = (CSG**)calloc(QUERY_RETURN_SIZE,sizeof(CSG*));

  int i = 0;//Helps to index pointers in double pointer
  for (CSG* iter = D->CSGTable[index]; iter != NULL; iter = iter->next)
  {
    if (equal_CSG(toLookup, iter))//If we've found the matching entry as iter's next
    {
      retList[i] = iter;
      i++;
    }
  }
  if (retList[0] == NULL) return NULL;//If list is empty, return null directly
  return retList;
}


//CP Lookup
CP** lookup_CP(Database* D, CP* toLookup)
{
  int index = hash(stringToInt(toLookup->Course));
  CP** retList = (CP**)calloc(QUERY_RETURN_SIZE,sizeof(CP*));

  int i = 0;//Helps to index pointers in double pointer
  for (CP* iter = D->CPTable[index]; iter != NULL; iter = iter->next)
  {
    if (equal_CP(toLookup, iter))//If we've found the matching entry as iter's next
    {
      retList[i] = iter;
      i++;
    }
  }
  if (retList[0] == NULL) return NULL;//If list is empty, return null directly
  return retList;
}

//CDH Lookup
CDH** lookup_CDH(Database* D, CDH* toLookup)
{
  int index = hash(stringToInt(toLookup->Course));
  CDH** retList = (CDH**)calloc(QUERY_RETURN_SIZE,sizeof(CDH*));

  int i = 0;//Helps to index pointers in double pointer
  for (CDH* iter = D->CDHTable[index]; iter != NULL; iter = iter->next)
  {
    if (equal_CDH(toLookup, iter))//If we've found the matching entry as iter's next
    {
      retList[i] = iter;
      i++;
    }
  }
  if (retList[0] == NULL) return NULL;//If list is empty, return null directly
  return retList;
}

//CR Lookup
CR** lookup_CR(Database* D, CR* toLookup)
{
  int index = hash(stringToInt(toLookup->Course));
  CR** retList = (CR**)calloc(QUERY_RETURN_SIZE,sizeof(CR*));

  int i = 0;//Helps to index pointers in double pointer
  for (CR* iter = D->CRTable[index]; iter != NULL; iter = iter->next)
  {
    if (equal_CR(toLookup, iter))//If we've found the matching entry as iter's next
    {
      retList[i] = iter;
      i++;
    }
  }
  if (retList[0] == NULL) return NULL;//If list is empty, return null directly
  return retList;
}

/*
  Insert Functions -------------------------------------------
*/

void insert_SNAP(Database* D, SNAP* toInsert)
{
  //Which Bucket? Hashes on inserted SNAP's StudentId
  int index = hash(stringToInt(toInsert->StudentId));

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
  int index = hash(stringToInt(toInsert->StudentId));

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
  int courseAsInt = stringToInt(toInsert->Course);
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
  int courseAsInt = stringToInt(toInsert->Course);
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
  int courseAsInt = stringToInt(toInsert->Course);
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
  int index = hash(stringToInt(toDelete->StudentId));

  if (D->SNAPTable[index] == NULL) return; //Not found

  if (equal_SNAP(D->SNAPTable[index], toDelete))//If it's the first in bucket before cycling through
  {
    SNAP* toFree = D->SNAPTable[index];
    D->SNAPTable[index] = D->SNAPTable[index]->next;
    free(toFree);
  } else {//Not in first bucket

    for (SNAP* iter = D->SNAPTable[index]; iter != NULL && iter->next != NULL; iter = iter->next)
    {
      if (equal_SNAP(toDelete, iter->next))//If we've found the matching entry as iter's next
      {
        SNAP* toFree = iter->next;
        iter->next = iter->next->next;//Create a new link in the list that bypasses the deleted node

        free(toFree);//Free the deleted data
      }
    }
  }
}


void delete_CSG(Database* D, CSG* toDelete)
{
  int index = hash(stringToInt(toDelete->StudentId));

  if (D->CSGTable[index] == NULL) return; //Not found

  if (equal_CSG(D->CSGTable[index], toDelete))//If it's the first in bucket before cycling through
  {
    CSG* toFree = D->CSGTable[index];
    D->CSGTable[index] = D->CSGTable[index]->next;
    free(toFree);
  } else {//Not in first bucket

    for (CSG* iter = D->CSGTable[index]; iter != NULL && iter->next != NULL; iter = iter->next)
    {
      if (equal_CSG(toDelete, iter->next))//If we've found the matching entry as iter's next
      {
        CSG* toFree = iter->next;
        iter->next = iter->next->next;//Create a new link in the list that bypasses the deleted node

        free(toFree);//Free the deleted data
      }
    }
  }
}


void delete_CP(Database* D, CP* toDelete)
{
  int index = hash(stringToInt(toDelete->Course));

  if (D->CPTable[index] == NULL) return; //Not found

  if (equal_CP(D->CPTable[index], toDelete))//If it's the first in bucket before cycling through
  {
    CP* toFree = D->CPTable[index];
    D->CPTable[index] = D->CPTable[index]->next;
    free(toFree);
  } else {//Not in first bucket

    for (CP* iter = D->CPTable[index]; iter != NULL && iter->next != NULL; iter = iter->next)
    {
      if (equal_CP(toDelete, iter->next))//If we've found the matching entry as iter's next
      {
        CP* toFree = iter->next;
        iter->next = iter->next->next;//Create a new link in the list that bypasses the deleted node

        free(toFree);//Free the deleted data
      }
    }
  }
}


void delete_CDH(Database* D, CDH* toDelete)
{
  int index = hash(stringToInt(toDelete->Course));

  if (D->CDHTable[index] == NULL) return; //Not found

  if (equal_CDH(D->CDHTable[index], toDelete))//If it's the first in bucket before cycling through
  {
    CDH* toFree = D->CDHTable[index];
    D->CDHTable[index] = D->CDHTable[index]->next;
    free(toFree);
  } else {//Not in first bucket

    for (CDH* iter = D->CDHTable[index]; iter != NULL && iter->next != NULL; iter = iter->next)
    {
      if (equal_CDH(toDelete, iter->next))//If we've found the matching entry as iter's next
      {
        CDH* toFree = iter->next;
        iter->next = iter->next->next;//Create a new link in the list that bypasses the deleted node

        free(toFree);//Free the deleted data
      }
    }
  }
}

void delete_CR(Database* D, CR* toDelete)
{
  int index = hash(stringToInt(toDelete->Course));

  if (D->CRTable[index] == NULL) return; //Not found

  if (equal_CR(D->CRTable[index], toDelete))//If it's the first in bucket before cycling through
  {
    CR* toFree = D->CRTable[index];
    D->CRTable[index] = D->CRTable[index]->next;
    free(toFree);
  } else {//Not in first bucket

    for (CR* iter = D->CRTable[index]; iter != NULL && iter->next != NULL; iter = iter->next)
    {
      if (equal_CR(toDelete, iter->next))//If we've found the matching entry as iter's next
      {
        CR* toFree = iter->next;
        iter->next = iter->next->next;//Create a new link in the list that bypasses the deleted node

        free(toFree);//Free the deleted data
      }
    }
  }
}
