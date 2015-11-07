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

dl_node* dllist_copy(dl_node *llist)
{
  dl_node *p = NULL, *new_list = NULL;

  for (p = llist; p != NULL; p = p->next)
    dllist_insert_tail(&new_list, p->item, p->item_size);

  return new_list;
}

void dllist_free_all(dl_node **llist, void (freefn)(void **))
{
  dl_node *p;

  for (p = *llist; p != NULL; p = p->next) {
    dllist_free(&(p->prev), freefn);
    
    if (p->next == NULL) dllist_free(&(&p), freefn);
  }

  *llist = NULL;
}

void dllist_free(dl_node **llist, void (freefn)(void **))
{
  printf("freeing %p (from %p)\n", *llist, llist);
  if (*llist != NULL) {
    freefn(& (*llist)->item);
    free(*llist);
    *llist = NULL;
  }
}

void dllist_print_record(dl_node *node, void printfn(void *item)) { printfn(node->item); }

void dllist_print_all_records(dl_node *llist, void printfn(void *item))
{
  dl_node *p;

  for (p = llist; p != NULL; p = p->next)
    dllist_print_record(p, printfn);
}
