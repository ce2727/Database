//StudentId-Name-Address-Grade
typedef struct SNAP *SNAPLIST;
typedef SNAPLIST SNAP_HASHTABLE[1009];

struct SNAP
{
  int StudentId;
  char Name[30];
  char Address[50];
  char Phone[8];
  SNAPLIST next;
};

typedef struct CSG *CSGLIST;
typedef CSGLIST CSG_HASHTABLE[1009];

//Course-StudentId-Grade
struct CSG
{
  char* Course[6];
  int StudentId[5];
  char* Grade[2];
}CSG;

typedef struct CP *CPLIST;
typedef CPLIST CP_HASHTABLE[1009];

//Course=Prerequisite
struct CP
{
  char* Course[6];
  char* Prerequisite[6];
}CP;

typedef struct CDH *CDHLIST;
typedef CDHLIST CDH_HASHTABLE[1009];

//Course-Day-Hour
struct CDH
{
  char* Course[6];
  char* Day[1];
  char* Hour[3];
}CDH;

typedef struct CR *CRLIST;
typedef CRLIST CR_HASHTABLE[1009];

//Course-Room
struct CR
{
  char* Course[6];
  char* Room[20];
}CR;
