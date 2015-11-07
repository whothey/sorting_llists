/**
 * dllist
 * The double-linked list lib
 */

#ifndef WT_DLLIST
#define WT_DLLIST

#include <stdlib.h>
#include "sorting.h"

typedef struct _dllist_node {
  void *item;
  size_t item_size;
  struct _dllist_node *prev;
  struct _dllist_node *next;
} dl_node;

/**
 * Creates a new instance of the linked-list
 */
void dllist_create(dl_node **list);

/**
 * Initializes a node of dllist
 */
void dllist_init_node(dl_node **node);

/**
 * Sets an item to list node
 */
void dllist_set_item(dl_node **node, void *item, size_t size);

void dllist_insert_head(dl_node **llist, void *item);

void dllist_insert_tail(dl_node **node, void *item, size_t size);

/**
 * Find an item on llist
 * search form *item on *cmp()
 * TODO: BETTER DOCUMENTATION
 */
dl_node* dllist_find(dl_node *llist, const void *item, int (*cmp)(const void *, const void *));

/**
 * Creates a copy of the list
 */
dl_node* dllist_copy(dl_node *llist);

/**
 * Prints the value of the node item using an auxiliar function
 */
void dllist_print_record(dl_node *node, void printfn(void *item));

/**
 * Prints all the values of the list
 */
void dllist_print_all_records(dl_node *llist, void printfn(void *item));

void dllist_free_all(dl_node **llist, void (freefn)(void **));
void dllist_free(dl_node **llist, void (freefn)(void **));

#endif
