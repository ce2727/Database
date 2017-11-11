#include "LinkedList.h"

inline int LinkedList_contains(LinkedList *list, int data) {
  for (LinkedListNode *node=list->first; node != NULL; node=node->next) {
	   if (node->data == data) {
	    return 1;
	}
    }
    return 0;
}

/**
 * Allocate, initialize and return a new (empty) LinkedList.
 */
inline LinkedList* LinkedList_new() {
    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
    list->first = list->last = NULL;
    return list;
}

inline LinkedListNode * LinkedListNode_new(int d) {
    LinkedListNode *node = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    if (node == NULL) {
	abort();
    }
    node->data = d;
    node->next = node->prev = NULL;
    return node;
}

inline void LinkedList_free(LinkedList *list) {
    // Free the elements
    LinkedListNode *elt = list->first;
    while (elt != NULL) {
	LinkedListNode *next = elt->next;
	free(elt);
	elt = next;
    }
    // Free the list itself
    free(list);
}

/**
 * Return true if the given LinkedList is empty.
 */
inline int LinkedList_is_empty(const LinkedList *list) {
    return list->first == NULL;
}


inline void LinkedList_add_at_end(LinkedList *list, int data) {
    LinkedListNode *node = LinkedListNode_new(data);
    node->prev = list->last;
    if (list->last != NULL) {
	list->last->next = node;
    }
    list->last = node;
    if (list->first == NULL) {
	list->first = node;
    }
}

inline void LinkedList_print_list(LinkedList *list) {
    for (LinkedListNode *node=list->first; node != NULL; node=node->next) {
       printf("%d", node->data);
	     if (node->next != NULL) {
	        printf(" ");
	       }
       }
    printf("\n");
}
