#include "Relations.h"
#include <stdlib.h>

#define TABLESIZE 100

typedef struct Database
{
    //Primary structures
    SNAP* SNAPTable[TABLESIZE];
    CSG*  CSGTable[TABLESIZE];
    CP*   CPTable[TABLESIZE];
    CDH*  CDHTable[TABLESIZE];
    CR*   CRTable[TABLESIZE];
    //Secondary Structures TODO add these
} Database;

//Creates new database and returns pointer
Database* Database_new();

//Simple hashing function
int hash(int input);

int courseToInt(char* Course);

//Insert Variations
void insert_SNAP(Database* D, SNAP* toInsert);
