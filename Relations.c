#include "Relations.h"


int equal_SNAP(SNAP* s1, SNAP* s2)
{
  if (!(s1->StudentId == s2->StudentId)) return 0;
  printf("Same SID\n");
  if (!(strcmp(s1->Name,s2->Name) == 0)) return 0;
  printf("Same Name\n");
  if (!(strcmp(s1->Address,s2->Address) == 0)) return 0;
  printf("Same Addr\n");
  if (!(strcmp(s1->Phone,s2->Phone) == 0)) return 0;
  printf("Same Phone\n");
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
