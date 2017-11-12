#include <string.h>
#include <stdlib.h>

#define NAMELENGTH 30
#define ADDRESSLENGTH 20
#define PHONELENGTH 10
#define COURSELENGTH 6
#define HOURLENGTH 4
#define DAYLENGTH 1
#define GRADELENGTH 2
#define ROOMLENGTH 20

//StudentId-Name-Address-Grade
typedef struct SNAP
{
  int StudentId;
  char Name[NAMELENGTH];
  char Address[ADDRESSLENGTH];
  char Phone[PHONELENGTH];
  struct SNAP* next;
}SNAP;

//Course-StudentId-Grade
typedef struct CSG
{
  char Course[COURSELENGTH];
  int StudentId;
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


/*
  Tuple creation fn's
*/

SNAP* SNAP_new(int StudentId, char* Name, char* Address, char* Phone);
