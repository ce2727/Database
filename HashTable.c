#include "HashTable.h"

HashTable* HashTable_new()
{
  HashTable* newTable = (HashTable*)malloc(sizeof(HashTable));
  newTable->Buckets = malloc(1009 * sizeof(LinkedList*));

  //Create linked lists
  for (int i = 0; i < 1009; i++)
  {
    newTable->Buckets[i] = &(LinkedList_new());
  }

  return newTable;
}

void HashTable_add(HashTable* Table, int data)
{
  int index = data % 1009;

  //Get bucket to hash to
  LinkedList* BucketHead = &(Table->Buckets[index]);
  //Hash it iiinnnn real good
  LinkedList_add_at_end(BucketHead, data);

}
