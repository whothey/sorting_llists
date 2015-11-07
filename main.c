#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "libs/tpcontato/tpcontato.h"
#include "libs/dllist/dllist.h"

void display_menu()
{
  printf("1) Criar Lista\n");
  printf("2) Insertion Sort\n");
  printf("3) Selection Sort\n");
  printf("4) Quick Sort\n");
  printf("5) Merge Sort\n");
  printf("6) Sair\n");
}

int main()
{
  int list_size, i;
  dl_node *list = NULL, *copy = NULL;
  char temp_name[MAX_NOME], temp_phone[MAX_FONE];

  printf("Insira o tamanho total da lista: ");
  scanf("%d", &list_size);

  srand(time(NULL));

  dllist_create(&list);

  // Populate with fake data
  for (i = 0; i < list_size; i++) {
    sprintf(temp_name, "Fulano %d", i);
    sprintf(temp_phone, "(%02d) %04d-%04d", rand() % 99, rand() % 9999, rand() % 9999);

    dllist_insert_tail(&list, tpc_create(temp_name, temp_phone), sizeof(TpContato));
  }

  dllist_print_all_records(list, tpc_generic_print);

  printf("\n\n");
    
  dllist_free_all(&list, tpc_generic_free);

  return 0;
}
