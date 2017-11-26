#include "Database.h"

CSG** select_CSG(Database* D, char* ID);

CRDH** join_CR_CDH(CR** CRS, CDH** CDHS);

CSGRDH** join_CSG_CRDH(CSG** CSGS, CRDH** CRDHS);
