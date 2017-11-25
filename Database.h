#include "Relations.h"
#include <stdlib.h>

#define TABLESIZE 100
#define QUERY_RETURN_SIZE 20

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

//Lookup Variations
SNAP** lookup_SNAP(Database* D, SNAP* toLookup);

CSG** lookup_CSG(Database* D, CSG* toLookup);

CP** lookup_CP(Database* D, CP* toLookup);

CDH** lookup_CDH(Database* D, CDH* toLookup);

CR** lookup_CR(Database* D, CR* toLookup);



//Insert Variations
void insert_SNAP(Database* D, SNAP* toInsert);
void insert_CSG(Database* D, CSG* toInsert);
void insert_CP(Database* D, CP* toInsert);
void insert_CDH(Database* D, CDH* toInsert);
void insert_CR(Database* D, CR* toInsert);

//Delete Variations
void delete_SNAP(Database* D, SNAP* toDelete);
void delete_CSG(Database* D, CSG* toDelete);
void delete_CP(Database* D, CP* toDelete);
void delete_CDH(Database* D, CDH* toDelete);
void delete_CR(Database* D, CR* toDelete);
