/**
 * dllist
 * The double-linked list lib
 */

#ifndef WT_DLLIST
#define WT_DLLIST

#include <stdlib.h>

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
 * Remove *node from its list and put it at end of llist
 */
void dllist_append(dl_node **list, dl_node *node);

/**
 * Swap two nodes position
 */
void dllist_swap_nodes(dl_node *node1, dl_node *node2);

/**
 * Find an item on llist
 * search form *item on *cmp()
 * TODO: BETTER DOCUMENTATION
 */
dl_node* dllist_find(dl_node *llist, const void *item, int (*cmp)(const void *, const void *));

/**
 * Creates a copy of the list, a clone-item function is needed
 * as we don't know what we are handling
 */
dl_node* dllist_copy(dl_node *llist, void *(clonefn(void *)));

/**
 * Creates a copy of the list until "to" element was found; A
 * clone-item function is needed as we don't know what we are handling
 */
dl_node* dllist_copy_until(dl_node *from, dl_node* to, void *(clonefn(void *)));

/**
 * Count the number of nodes in list
 */
unsigned int dllist_size(dl_node *);

/**
 * Prints the value of the node item using an auxiliar function
 */
void dllist_print_record(dl_node *node, void printfn(void *));

/**
 * Prints all the values of the list
 */
void dllist_print_all_records(dl_node *llist, void printfn(void *));

/**
 * Auxiliar function to not free items on dllist_free
 */
void keep_item(void **);

void dllist_free_all(dl_node **llist, void (freefn)(void **));
void dllist_free(dl_node *llist, void (freefn)(void **));

#endif
