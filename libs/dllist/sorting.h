#ifndef WT_DLLIST_SORTING
#define WT_DLLIST_SORTING

#include <stdlib.h>

void quick_sort(void *items, int (*cmp)(const void *, const void *));
void insertion_sort(void *items, int (*cmp)(const void *, const void *));
void selection_sort(void *items, int (*cmp)(const void *, const void *));
void merge_sort(void *items, int (*cmp)(const void *, const void *));

#endif
