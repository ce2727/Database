#include "LinkedList.h"


typedef struct HashTable
{
  LinkedList** Buckets;
} HashTable;


//Creates new hashtable
HashTable* HashTable_new();

//Hashes and adds a new entry
void HashTable_add(HashTable* Table, int data);
