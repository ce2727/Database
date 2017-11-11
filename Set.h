#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct SetNode {
    int data;
    struct SetNode *next;
    struct SetNode *prev;
} SetNode;

typedef struct  {
    struct SetNode *first;
    struct SetNode *last;
}Set;

/*
*Checks to see if the Set contains a piece of data
*/
extern int Set_contains(Set *list, int data);
/*
*Allocates and returns a new Set pointer
*/
extern Set* Set_new();
/*
*Allocates and returns a new Setnode pointer
*/
extern SetNode * SetNode_new(int d);
/*
*Frees the Set from memory
*/
extern void Set_free(Set *list);
/**
 * Return true if the given Set is empty.
 */
extern int Set_is_empty(const Set *list);
/*
*Adds a new node at the end
*/
extern void Set_add_at_end(Set *list, int data);
/*
*Union Set operation simply adds elements to set 1 that are contained uniquely in set2
*/
extern void Set_Union(Set* s1, Set* s2);
/*
*Allocates and returns a new Set pointer
*/
extern void Set_print_set(Set *list);
/*
*Creates a linked set iterator
*/
