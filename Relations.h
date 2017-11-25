#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define IDLENGTH 7
#define NAMELENGTH 30
#define ADDRESSLENGTH 30
#define PHONELENGTH 13
#define COURSELENGTH 7 //Allocated as 1 extra to auto include null terminator - had accidental concatenation issues
#define HOURLENGTH 5
#define DAYLENGTH 2
#define GRADELENGTH 3
#define ROOMLENGTH 30

//StudentId-Name-Address-Grade
typedef struct SNAP
{
  char StudentId[IDLENGTH];
  char Name[NAMELENGTH];
  char Address[ADDRESSLENGTH];
  char Phone[PHONELENGTH];
  struct SNAP* next;
}SNAP;

//Course-StudentId-Grade
typedef struct CSG
{
  char Course[COURSELENGTH];
  char StudentId[IDLENGTH];
  char Grade[GRADELENGTH];
  struct CSG* next;
}CSG;

//Course=Prerequisite
typedef struct CP
{
  char Course[COURSELENGTH];
  char Prerequisite[COURSELENGTH];
  struct CP* next;
}CP;

//Course-Day-Hour
typedef struct CDH
{
  char Course[COURSELENGTH];
  char Day[DAYLENGTH];
  char Hour[HOURLENGTH];
  struct CDH* next;
}CDH;

//Course-Room
typedef struct CR
{
  char Course[COURSELENGTH];
  char Room[ROOMLENGTH];
  struct CR* next;
}CR;

/*
  Tuple comparision fn's
*/

int equal_SNAP(SNAP* s1, SNAP* s2);

int equal_CSG(CSG* c1, CSG* c2);

int equal_CP(CP* c1, CP* c2);

int equal_CDH(CDH* c1, CDH* c2);

int equal_CR(CR* c1, CR* c2);
/*
  Tuple creation fn's
*/

SNAP* SNAP_new(char* StudentId, char* Name, char* Address, char* Phone);

CSG* CSG_new(char* Course, char* StudentId, char* Grade);

CP* CP_new(char* Course, char* Prerequisite);

CDH* CDH_new(char* Course, char* Day, char* Hour);

CR* CR_new(char* Course, char* Room);
