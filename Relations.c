#include "Relations.h"

/*
  Equals Methods
*/
int equal_SNAP(SNAP* s1, SNAP* s2)
{
  if (s1 == NULL || s2 == NULL) return 0;//TODO change studentID to string
  if (!(strcmp(s1->StudentId,s2->StudentId) == 0) && !((strcmp(s1->StudentId,"*") == 0) || (strcmp(s2->StudentId,"*") == 0))) return 0;
  if (!(strcmp(s1->Name,s2->Name) == 0) && !((strcmp(s1->Name,"*") == 0) || (strcmp(s2->Name,"*") == 0))) return 0;
  if (!(strcmp(s1->Address,s2->Address) == 0) && !((strcmp(s1->Address,"*") == 0) || (strcmp(s2->Address,"*") == 0))) return 0;
  if (!(strcmp(s1->Phone, s2->Phone) == 0) && !((strcmp(s1->Phone,"*") == 0) || (strcmp(s2->Phone,"*") == 0))) return 0;
  return 1;//All are the same! Success
}

int equal_CSG(CSG* c1, CSG* c2)
{
  if (c1 == NULL || c2 == NULL) return 0;
  if (!(strcmp(c1->StudentId,c2->StudentId) == 0) && !((strcmp(c1->StudentId,"*") == 0) || (strcmp(c2->StudentId,"*") == 0))) return 0;
  if (!(strcmp(c1->Course,c2->Course) == 0) && !((strcmp(c1->Course,"*") == 0) || (strcmp(c2->Course,"*") == 0))) return 0;
  if (!(strcmp(c1->Grade,c2->Grade) == 0) && !((strcmp(c1->Grade,"*") == 0) || (strcmp(c2->Grade,"*") == 0))) return 0;

  return 1;//All are the same! Success
}

int equal_CP(CP* c1, CP* c2)
{
  if (c1 == NULL || c2 == NULL) return 0;
  if (!(strcmp(c1->Course,c2->Course) == 0) && !((strcmp(c1->Course,"*") == 0) || (strcmp(c2->Course,"*") == 0))) return 0;
  if (!(strcmp(c1->Prerequisite,c2->Prerequisite) == 0) && !((strcmp(c1->Prerequisite,"*") == 0) || (strcmp(c2->Prerequisite,"*") == 0))) return 0;
  return 1;//All are the same! Success
}

int equal_CDH(CDH* c1, CDH* c2)
{
  if (c1 == NULL || c2 == NULL) return 0;
  if (!(strcmp(c1->Course,c2->Course) == 0) && !((strcmp(c1->Course,"*") == 0) || (strcmp(c2->Course,"*") == 0))) return 0;
  if (!(strcmp(c1->Day,c2->Day) == 0) && !((strcmp(c1->Day,"*") == 0) || (strcmp(c2->Day,"*") == 0))) return 0;
  if (!(strcmp(c1->Hour,c2->Hour) == 0) && !((strcmp(c1->Hour,"*") == 0) || (strcmp(c2->Hour,"*") == 0))) return 0;
  return 1;//All are the same! Success
}

int equal_CR(CR* c1, CR* c2)
{
  if (c1 == NULL || c2 == NULL) return 0;
  if (!(strcmp(c1->Course,c2->Course) == 0) && !((strcmp(c1->Course,"*") == 0) || (strcmp(c2->Course,"*") == 0))) return 0;
  if (!(strcmp(c1->Room,c2->Room) == 0) && !((strcmp(c1->Room,"*") == 0) || (strcmp(c2->Room,"*") == 0))) return 0;
  return 1;//All are the same! Success
}

int equal_CRDH(CRDH* c1, CRDH* c2)
{
  if (c1 == NULL || c2 == NULL) return 0;
  if (!(strcmp(c1->Course,c2->Course) == 0) && !((strcmp(c1->Course,"*") == 0) || (strcmp(c2->Course,"*") == 0))) return 0;
  if (!(strcmp(c1->Room,c2->Room) == 0) && !((strcmp(c1->Room,"*") == 0) || (strcmp(c2->Room,"*") == 0))) return 0;
  if (!(strcmp(c1->Day,c2->Day) == 0) && !((strcmp(c1->Day,"*") == 0) || (strcmp(c2->Day,"*") == 0))) return 0;
  if (!(strcmp(c1->Hour,c2->Hour) == 0) && !((strcmp(c1->Hour,"*") == 0) || (strcmp(c2->Hour,"*") == 0))) return 0;
  return 1;//All are the same! Success
}

int equal_CSGRDH(CSGRDH* c1, CSGRDH* c2)
{
  if (c1 == NULL || c2 == NULL) return 0;
  if (!(strcmp(c1->Course,c2->Course) == 0) && !((strcmp(c1->Course,"*") == 0) || (strcmp(c2->Course,"*") == 0))) return 0;
  if (!(strcmp(c1->StudentId,c2->StudentId) == 0) && !((strcmp(c1->StudentId,"*") == 0) || (strcmp(c2->StudentId,"*") == 0))) return 0;
  if (!(strcmp(c1->Grade,c2->Grade) == 0) && !((strcmp(c1->Grade,"*") == 0) || (strcmp(c2->Grade,"*") == 0))) return 0;
  if (!(strcmp(c1->Room,c2->Room) == 0) && !((strcmp(c1->Room,"*") == 0) || (strcmp(c2->Room,"*") == 0))) return 0;
  if (!(strcmp(c1->Day,c2->Day) == 0) && !((strcmp(c1->Day,"*") == 0) || (strcmp(c2->Day,"*") == 0))) return 0;
  if (!(strcmp(c1->Hour,c2->Hour) == 0) && !((strcmp(c1->Hour,"*") == 0) || (strcmp(c2->Hour,"*") == 0))) return 0;
  return 1;//All are the same! Success
}
/*
  New Tuples
*/

SNAP* SNAP_new(char* StudentId, char* Name, char* Address, char* Phone)
{
  SNAP* new = (SNAP*)calloc(1,sizeof(SNAP));
  strcpy(new->StudentId, StudentId);
  strcpy(new->Name, Name);
  strcpy(new->Address, Address);
  strcpy(new->Phone, Phone);
  return new;
}

CSG* CSG_new(char* Course, char* StudentId, char* Grade)
{
  CSG* new = (CSG*)calloc(1,sizeof(CSG));
  strcpy(new->StudentId, StudentId);
  strcpy(new->Course, Course);
  strcpy(new->Grade, Grade);
  return new;
}

CP* CP_new(char* Course, char* Prerequisite)
{
  CP* new = (CP*)calloc(1,sizeof(CP));
  strcpy(new->Course, Course);
  strcpy(new->Prerequisite, Prerequisite);
  return new;
}

CDH* CDH_new(char* Course, char* Day, char* Hour)
{
  CDH* new = (CDH*)calloc(1,sizeof(CDH));
  strcpy(new->Course, Course);
  strcpy(new->Day, Day);
  strcpy(new->Hour, Hour);
  return new;
}

CR* CR_new(char* Course, char* Room)
{
  CR* new = (CR*)calloc(1,sizeof(CR));
  strcpy(new->Course, Course);
  strcpy(new->Room, Room);
  return new;
}

CRDH* CRDH_new(char* Course, char* Room, char* Day, char* Hour)
{
  CRDH* new = (CRDH*)calloc(1,sizeof(CRDH));
  strcpy(new->Course, Course);
  strcpy(new->Room, Room);
  strcpy(new->Day, Day);
  strcpy(new->Hour, Hour);
  return new;
}

CSGRDH* CSGRDH_new(char* Course, char* StudentId, char* Grade, char* Room, char* Day, char* Hour)
{
  CSGRDH* new = (CSGRDH*)calloc(1,sizeof(CSGRDH));
  strcpy(new->Course, Course);
  strcpy(new->StudentId, StudentId);
  strcpy(new->Grade, Grade);
  strcpy(new->Room, Room);
  strcpy(new->Day, Day);
  strcpy(new->Hour, Hour);
  return new;
}
