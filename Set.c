#include "Set.h"

inline int Set_contains(Set *list, int data) {
  for (SetNode *node=list->first; node != NULL; node=node->next) {
	   if (node->data == data) {
	    return 1;
	}
    }
    return 0;
}

/**
 * Allocate, initialize and return a new (empty) Set.
 */
inline Set* Set_new() {
    Set *list = (Set*)malloc(sizeof(Set));
    list->first = list->last = NULL;
    return list;
}

inline SetNode * SetNode_new(int d) {
    SetNode *node = (SetNode*)malloc(sizeof(SetNode));
    if (node == NULL) {
	abort();
    }
    node->data = d;
    node->next = node->prev = NULL;
    return node;
}

inline void Set_free(Set *list) {
    // Free the elements
    SetNode *elt = list->first;
    while (elt != NULL) {
	SetNode *next = elt->next;
	free(elt);
	elt = next;
    }
    // Free the list itself
    free(list);
}

/**
 * Return true if the given Set is empty.
 */
inline int Set_is_empty(const Set *list) {
    return list->first == NULL;
}


inline void Set_add_at_end(Set *list, int data) {
  if (Set_contains(list, data)) {
    printf("Set already contains %d\n", data);
    return;
    }
    SetNode *node = SetNode_new(data);
    node->prev = list->last;
    if (list->last != NULL) {
	list->last->next = node;
    }
    list->last = node;
    if (list->first == NULL) {
	list->first = node;
    }
}

//Union Set operation
//simply adds elements to set 1 that are contained uniquely in set2
inline void Set_Union(Set* s1, Set* s2){
  for (SetNode *node=s2->first; node != NULL; node=node->next){
    if (Set_contains(s1,node->data) == 0) {
      Set_add_at_end(s1,node->data);
    }
  }
}

inline void Set_print_set(Set *list) {
    for (SetNode *node=list->first; node != NULL; node=node->next) {
       printf("%d", node->data);
	     if (node->next != NULL) {
	        printf(" ");
	       }
       }
    printf("\n");
}
