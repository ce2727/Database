#include "Query.h"

int main()
{
  Database* test = Database_new();
  //SNAP test data
  insert_SNAP(test, SNAP_new("12345", "John", "21 Rocky Rd.", "911-911-9911"));
  insert_SNAP(test, SNAP_new("12346", "Joe", "90 Rocky Rd.", "912-911-9911"));
  insert_SNAP(test, SNAP_new("12347", "Peter", "4051 Rip Rd.", "123-455-6789"));
  insert_SNAP(test, SNAP_new("12348", "Bobby", "4 Rip Rd.", "823-455-6789"));

  //CSG Test Data
  insert_CSG(test, CSG_new("CSC101", "12345", "B+"));
  //insert_CSG(test, CSG_new("CSC101", "12345", "F")); <--- Uncomment to test multi-entry queries
  insert_CSG(test, CSG_new("CSC101", "12346", "B-"));
  insert_CSG(test, CSG_new("CSC103", "12347", "B"));
//  insert_CSG(test, CSG_new("CSC103", "12347", "A"));

  //CP Test Data
  insert_CP(test, CP_new("CSC101", "CSC050"));
  insert_CP(test, CP_new("CSC101", "CSC100"));
  insert_CP(test, CP_new("CSC102", "CSC101"));
  insert_CP(test, CP_new("CSC103", "CSC102"));

  //CDH Test Data
  insert_CDH(test, CDH_new("CSC050", "M", "8am"));
  insert_CDH(test, CDH_new("CSC050", "W", "8am"));
  insert_CDH(test, CDH_new("CSC101", "M", "12am"));
  insert_CDH(test, CDH_new("CSC101", "W", "12am"));
  insert_CDH(test, CDH_new("CSC102", "T", "8am"));
  insert_CDH(test, CDH_new("CSC103", "T", "7pm"));//R == thursday
  insert_CDH(test, CDH_new("CSC103", "R", "7pm"));

  //CR Test Data
  insert_CR(test, CR_new("CSC050", "Tesla Lab."));
  insert_CR(test, CR_new("CSC101", "Halting Aud."));
  insert_CR(test, CR_new("CSC102", "Bruckner S8"));
  insert_CR(test, CR_new("CSC103", "Turing 173"));



  /*
    Enter Queries Here:
  */
  /*Query(test,"What grade did John get in CSC101?");
  Query(test,"What grade did Peter get in CSC103?");
  Query(test,"What grade did Joe get in CSC101?");
  */
  Query(test,"Where is Peter at 7pm on T?");

}
