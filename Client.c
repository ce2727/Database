#include "Database.h"

int main()
{
  Database* test = Database_new();
  //SNAP test data
  insert_SNAP(test, SNAP_new(12345, "John S.", "21 Rocky Rd.", "911-911-9911"));
  insert_SNAP(test, SNAP_new(12345, "Peter E.", "4051 Rip Rd.", "123-455-6789"));
  insert_SNAP(test, SNAP_new(12345, "Bobby G.", "4 Rip Rd.", "823-455-6789"));
  printf("%s\n",lookup_SNAP(test,SNAP_new(12345, "Bobby G.", "4 Rip Rd.", "823-455-6789"))->Name);

  delete_SNAP(test, SNAP_new(12345, "John S.", "21 Rocky Rd.", "911-911-9911"));

  //CSG Test Data
  insert_CSG(test, CSG_new("CSC101", 12345, "B+"));
  insert_CSG(test, CSG_new("CSC102", 12345, "B-"));
  insert_CSG(test, CSG_new("CSC103", 12345, "B+"));
  printf("%s\n",lookup_CSG(test,CSG_new("CSC103", 12345, "B+")));

  delete_CSG(test, CSG_new("CSC102", 12345, "B-"));

  //CP Test Data
  insert_CP(test, CP_new("CSC101", "CSC100"));
  insert_CP(test, CP_new("CSC102", "CSC101"));
  insert_CP(test, CP_new("CSC103", "CSC102"));
  printf("%s\n",lookup_CP(test, CP_new("CSC101", "CSC100"))->Course);
  delete_CP(test, CP_new("CSC103", "CSC102"));

  //CDH Test Data
  insert_CDH(test, CDH_new("CSC101", "M", "12am"));
  insert_CDH(test, CDH_new("CSC102", "T", "10am"));
  insert_CDH(test, CDH_new("CSC103", "R", "7pm"));//R == thursday
  printf("%s\n",lookup_CDH(test,CDH_new("CSC102", "T", "10am")));

  delete_CDH(test, CDH_new("CSC102", "T", "10am"));

  //CR Test Data
  insert_CR(test, CR_new("CSC101", "Halting Aud."));
  insert_CR(test, CR_new("CSC102", "Bruckner S8"));
  insert_CR(test, CR_new("CSC103", "Turing 173"));
  printf("%s\n",lookup_CR(test, CR_new("CSC101", "Halting Aud.")));

  delete_CP(test, CP_new("CSC102", "Bruckner S8"));
}
