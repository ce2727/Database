#include "Relations.h"


int equal_SNAP(SNAP* s1, SNAP* s2)
{
  if (!(s1->StudentId == s2->StudentId)) return 0;
  if (!(strcmp(s1->Name,s2->Name))) return 0;
  if (!(strcmp(s1->Address,s2->Address))) return 0;
  if (!(strcmp(s1->Phone,s2->Phone))) return 0;
  return 1;//All are the same! Success
}

/*
  New Tuples
*/

SNAP* SNAP_new(int StudentId, char* Name, char* Address, char* Phone)
{
  SNAP* new = (SNAP*)malloc(sizeof(SNAP));
  new->StudentId = StudentId;
  strcpy(new->Name, Name);
  strcpy(new->Address, Address);
  strcpy(new->Phone, Phone);
  return new;
}
