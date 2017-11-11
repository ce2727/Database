#include "LinkedList.h"
#include "Set.h"

int main()
{
  LinkedList* TestLst = LinkedList_new();
  LinkedList_add_at_end(TestLst, 4);
  LinkedList_add_at_end(TestLst, 3);
  LinkedList_add_at_end(TestLst, 1);
  LinkedList_add_at_end(TestLst, 1);

  LinkedList_print_list(TestLst);

  Set* TestSt = Set_new();
  Set_add_at_end(TestSt, 4);
  Set_add_at_end(TestSt, 3);
  Set_add_at_end(TestSt, 3);
  Set_add_at_end(TestSt, 2);

  Set_print_set(TestSt);
  
}
