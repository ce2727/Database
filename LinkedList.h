#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LinkedListNode {
    int data;
    struct LinkedListNode *next;
    struct LinkedListNode *prev;
} LinkedListNode;

typedef struct LinkedList {
    struct LinkedListNode *first;
    struct LinkedListNode *last;
}LinkedList;

/*
*Checks to see if the LinkedList contains a piece of data
*/
extern int LinkedList_contains(LinkedList *list, int data);
/*
*Allocates and returns a new LinkedList pointer
*/
extern LinkedList* LinkedList_new();
/*
*Allocates and returns a new LinkedListnode pointer
*/
extern LinkedListNode * LinkedListNode_new(int d);
/*
*Frees the LinkedList from memory
*/
extern void LinkedList_free(LinkedList *list);
/**
 * Return true if the given LinkedList is empty.
 */
extern int LinkedList_is_empty(const LinkedList *list);
/*
*Adds a new node at the end
*/
extern void LinkedList_add_at_end(LinkedList *list, int data);
/*
*Union Set operation simply adds elements to set 1 that are contained uniquely in set2
*/
extern void LinkedList_print_list(LinkedList *list);
