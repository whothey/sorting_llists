#ifndef WT_DLLIST_SORTING
#define WT_DLLIST_SORTING

#include <stdlib.h>
#include "dllist.h"

/**
 * Quick Sort Functions
 */
dl_node *dllist_qs_partition(dl_node *beg, dl_node *end, int (*cmp)(const void *, const void *));
void dllist_quick_sort_rec(dl_node *beg, dl_node* end, int (*cmp)(const void *, const void *));
void dllist_quick_sort(dl_node *llist, int (*cmp)(const void *, const void *));

/**
 * Merge Sort Functions
 */
dl_node *dllist_merge_sort(dl_node **llist, int(*cmp)(const void *, const void *));
dl_node *dllist_merge_merge(dl_node *left, dl_node *right, int(*cmp)(const void *, const void *));

void dllist_insertion_sort(dl_node *items, int (*cmp)(const void *, const void *));
void dllist_selection_sort(dl_node *items, int (*cmp)(const void *, const void *));

#endif
