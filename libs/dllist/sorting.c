#include "sorting.h"
#include "../tpcontato/tpcontato.h"

void dllist_insertion_sort(dl_node *llist, int (*cmp)(const void *, const void*))
{
  dl_node *p, *i;

  if (llist == NULL || llist->next == NULL) return;

  /* Iterates the llist */
  for (i = llist; i != NULL; i = i->next) {
    for (p = i; p->prev != NULL && cmp(p->item, p->prev->item) < 0; p = p->prev)
      dllist_swap_nodes(p, p->prev);
  }
}

void dllist_selection_sort(dl_node *items, int (*cmp)(const void *, const void *))
{
  dl_node *i, *p, *key;

  for (i = items; i != NULL; i = i->next) {
    key  = i;
    
    for (p = i->next; p != NULL; p = p->next)
      if (cmp(p->item, key->item) < 0) key = p;
    
    if (key != i) dllist_swap_nodes(i, key);
  }
}

dl_node* dllist_qs_partition(dl_node *beg, dl_node *end, int (*cmp)(const void *, const void *))
{
  dl_node *pivot = end, *swap = beg, *p;

  for (p = beg; p != end && p != NULL; p = p->next) {
    if (cmp(p->item, pivot->item) < 0) {
      dllist_swap_nodes(p, swap);
      swap = swap->next;
    }
  }
  
  dllist_swap_nodes(swap, pivot);

  return swap;
}

void dllist_quick_sort_req(dl_node *beg, dl_node *end, int (*cmp)(const void *, const void *))
{
  dl_node *p;  
  
  if (beg != end && (beg != NULL || end != NULL) && beg != end->next) {
    p = dllist_qs_partition(beg, end, cmp);

    if (p != NULL && p->prev != NULL)
      dllist_quick_sort_req(beg, p->prev, cmp);

    if (p != NULL && p->next != NULL)
      dllist_quick_sort_req(p->next, end, cmp);
  } 
}

void dllist_quick_sort(dl_node *llist, int (*cmp)(const void *, const void *))
{
  dl_node *end;
  
  for (end = llist; end->next != NULL; end = end->next);
  dllist_quick_sort_req(llist, end, cmp);
}

dl_node *dllist_merge_sort(dl_node **llist, int(*cmp)(const void *, const void *))
{
  dl_node *m, *left = NULL, *right = NULL, *next = NULL;
  int i, size;

  // Base-case
  if (*llist == NULL || (*llist)->next == NULL) return *llist;

  // Count until the end
  for (size = 0, m = *llist; m != NULL; size++, m = m->next);
  
  // Split items
  for (i = 0, m = *llist; m != NULL; i++, m = next) {
    next = m->next;
    
    if (i < (size) / 2) {
      dllist_append(&left, m);
    } else {
      dllist_append(&right, m);
    }
  }

  left  = dllist_merge_sort(&left, cmp);
  right = dllist_merge_sort(&right, cmp);

  return dllist_merge_merge(left, right, cmp);
}


dl_node *dllist_merge_merge(dl_node *left, dl_node *right, int(*cmp)(const void *, const void *))
{
  dl_node *result = NULL, *next = NULL;

  while (left != NULL && right != NULL) {
    if (cmp(left->item, right->item) < 0) {
      next = left->next;
      dllist_append(&result, left);
      left = next;
    } else {
      next = right->next;
      dllist_append(&result, right);
      right = next;
    }
  }

  while (left != NULL) {
    next = left->next;
    dllist_append(&result, left);
    left = next;
  }

  while (right != NULL) {
    next = right->next;
    dllist_append(&result, right);
    right = next;
  }
  
  return result;
}
