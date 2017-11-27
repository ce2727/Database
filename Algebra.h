#include "Database.h"

//Relational Algebra: Select function for ID's on CSG structs
CSG** select_CSG(Database* D, char* ID);

//Relational Algebra: Join function between CR and CDH
CRDH** join_CR_CDH(CR** CRS, CDH** CDHS);

//Relational Algebra: Join function between CSG and CRDH
CSGRDH** join_CSG_CRDH(CSG** CSGS, CRDH** CRDHS);
