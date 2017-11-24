#include "Relations.h"

/*
  Equals Methods
*/
int equal_SNAP(SNAP* s1, SNAP* s2)
{
  if (!(s1->StudentId == s2->StudentId)) return 0;
  if (!(strcmp(s1->Name,s2->Name) == 0)) return 0;
  if (!(strcmp(s1->Address,s2->Address) == 0)) return 0;
  if (!(strcmp(s1->Phone, s2->Phone) == 0)) return 0;
  return 1;//All are the same! Success
}

int equal_CSG(CSG* c1, CSG* c2)
{
  if (!(c1->StudentId == c2->StudentId)) return 0;
  if (!(strcmp(c1->Course,c2->Course) == 0)) return 0;
  if (!(strcmp(c1->Grade,c2->Grade) == 0)) return 0;
  return 1;//All are the same! Success
}

int equal_CP(CP* c1, CP* c2)
{
  if (!(strcmp(c1->Course,c2->Course) == 0)) return 0;
  if (!(strcmp(c1->Prerequisite,c2->Prerequisite) == 0)) return 0;
  return 1;//All are the same! Success
}

int equal_CDH(CDH* c1, CDH* c2)
{
  if (!(strcmp(c1->Course,c2->Course) == 0)) return 0;
  if (!(strcmp(c1->Day,c2->Day) == 0)) return 0;
  if (!(strcmp(c1->Hour,c2->Hour) == 0)) return 0;
  return 1;//All are the same! Success
}

int equal_CR(CR* c1, CR* c2)
{
  if (!(strcmp(c1->Course,c2->Course) == 0)) return 0;
  if (!(strcmp(c1->Room,c2->Room) == 0)) return 0;
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

CSG* CSG_new(char* Course, int StudentId, char* Grade)
{
  CSG* new = (CSG*)malloc(sizeof(CSG));
  new->StudentId = StudentId;
  strcpy(new->Course, Course);
  strcpy(new->Grade, Grade);
  return new;
}

CP* CP_new(char* Course, char* Prerequisite)
{
  CP* new = (CP*)malloc(sizeof(CP));
  strcpy(new->Course, Course);
  strcpy(new->Prerequisite, Prerequisite);
  return new;
}

CDH* CDH_new(char* Course, char* Day, char* Hour)
{
  CDH* new = (CDH*)malloc(sizeof(CDH));
  strcpy(new->Course, Course);
  strcpy(new->Day, Day);
  strcpy(new->Hour, Hour);
  return new;
}

CR* CR_new(char* Course, char* Room)
{
  CR* new = (CR*)malloc(sizeof(CR));
  strcpy(new->Course, Course);
  strcpy(new->Room, Room);
  return new;
}
