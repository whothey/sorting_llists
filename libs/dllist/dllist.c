#include <stdio.h>
#include "dllist.h"

void dllist_create(dl_node **list) { *list = NULL; }

void dllist_init_node(dl_node **node)
{
  *node = (dl_node *)malloc(sizeof(dl_node));
  (*node)->item      = NULL;
  (*node)->item_size = sizeof(NULL);
  (*node)->prev      = NULL;
  (*node)->next      = NULL;
}

void dllist_set_item(dl_node **node, void *item, size_t size)
{
  (*node)->item      = item;
  (*node)->item_size = size;
}

void dllist_insert_tail(dl_node **llist, void *item, size_t item_size)
{
  dl_node *p = NULL, *new = NULL;

  dllist_init_node(&new);
  dllist_set_item(&new, item, item_size);

  for (p = *llist; p != NULL && p->next != NULL; p = p->next);

  if (p == NULL) {
    *llist = new;

    return;
  }

  new->prev = p;
  p->next   = new;
}

dl_node* dllist_copy(dl_node *llist, void *(clonefn(void *)))
{
  return dllist_copy_until(llist, NULL, clonefn);
}

dl_node* dllist_copy_until(dl_node *from, dl_node* to, void *(clonefn(void *)))
{
  void *new_item = NULL;
  dl_node *p = NULL, *new_list = NULL;

  for (p = from; p != to || p != NULL; p = p->next) {
    new_item = clonefn(p->item);
    dllist_insert_tail(&new_list, new_item, sizeof(new_item));
  }

  return new_list;
}

void dllist_append(dl_node **llist, dl_node *node)
{
  dl_node *p;
  
  // Re-link *node original list
  if (node->prev != NULL)
    node->prev->next = node->next;

  if (node->next != NULL)
    node->next->prev = node->prev;
  
  if (*llist == NULL) {
    node->prev = NULL;
    node->next = NULL;
    *llist = node;

    return;
  }

  for (p = *llist; p->next != NULL; p = p->next);
  p->next    = node;
  node->prev = p;
  node->next = NULL;
}

void dllist_free_all(dl_node **llist, void (freefn)(void **))
{
  dl_node *p;

  while (*llist != NULL) {
    p      = *llist;
    *llist = (*llist)->next;
    
    dllist_free(p, freefn);
  }
  
  *llist = NULL;
}

void dllist_swap_nodes(dl_node *node1, dl_node *node2)
{
  void *aux = NULL;
  
  aux         = node1->item;
  node1->item = node2->item;
  node2->item = aux;
}

unsigned int dllist_size(dl_node *llist)
{
  unsigned int count = 0;
  dl_node *p;

  for (p = llist; p != NULL; p = p->next) count++;

  return count;
}

void keep_item(void **item) { return; }

void dllist_free(dl_node *llist, void (freefn)(void **))
{
  if (llist != NULL) {
    freefn(& llist->item);
    free(llist);
    llist = NULL;
  }
}

void dllist_print_record(dl_node *node, void printfn(void *item)) { printfn(node->item); }

void dllist_print_all_records(dl_node *llist, void printfn(void *item))
{
  dl_node *p;

  for (p = llist; p != NULL; p = p->next)
    dllist_print_record(p, printfn);
}
