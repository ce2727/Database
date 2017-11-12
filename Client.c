#include "Database.h"

int main()
{
  int tester = equal_SNAP(SNAP_new(12345, "John S.", "21 Rocky Rd.", "9119119911"),SNAP_new(12345, "John S.", "21 Rocky Rd.", "9119119911"));
  printf("%d\n",tester );




  Database* test = Database_new();

  insert_SNAP(test, SNAP_new(12345, "John S.", "21 Rocky Rd.", "9119119911"));
  printf("%d",test->SNAPTable[hash(12345)]->StudentId);

  delete_SNAP(test, SNAP_new(12345, "John S.", "21 Rocky Rd.", "9119119911"));
  printf("%d",test->SNAPTable[hash(12345)]->StudentId);
  printf("%d\n",NULL );
}
