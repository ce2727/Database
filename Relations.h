//Course-StudentId-Grade
typedef struct CSG
{
  char* Course;
  int StudentId;
  char* Grade;
}CSG;

//StudentId-Name-Address-Phone
typedef struct SNAP
{
  int StudentId;
  char* Name;
  char* Address;
  int Phone;
}SNAP;

//Course=Prerequisite
typedef struct CP
{
  char* Course;
  char* Prerequisite;
}CP;

//Course-Day-Hour
typedef struct CDH
{
  char* Course;
  char* Day;
  char* Hour;
}CDH;

//Course-Room
typedef struct CR
{
  char* Course;
  char* Room;
}CR;
