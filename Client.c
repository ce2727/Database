#include "Database.h"
#include <stdio.h>

int main()
{
  Database* test = Database_new();

  insert_SNAP(test, SNAP_new(12345, "John S.", "21 Rocky Rd.", "9119119911"));
  printf("%d",test->SNAPTable[hash(12345)]->StudentId);
}
