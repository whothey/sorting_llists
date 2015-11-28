#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "libs/tpcontato/tpcontato.h"
#include "libs/dllist/dllist.h"
#include "libs/dllist/sorting.h"

#define EXIT_OPTION 6

void display_menu()
{
  printf("1) Criar Lista\n");
  printf("2) Insertion Sort\n");
  printf("3) Selection Sort\n");
  printf("4) Quick Sort\n");
  printf("5) Merge Sort\n");
  printf("6) Sair\n");
}

double _difftime(clock_t start)
{
  return ((double)clock() - start) / CLOCKS_PER_SEC;
}

int main()
{
  int list_size, i, choice;
  dl_node *list = NULL, *copy = NULL;
  char temp_name[MAX_NOME], temp_phone[MAX_FONE];
  double time_result;
  clock_t _start;

  do {
    display_menu();
    printf("Escolha uma opção: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      dllist_free_all(&list, tpc_generic_free);
      printf("Insira o tamanho total da lista: ");
      scanf("%d", &list_size);

      srand(time(NULL));

      dllist_create(&list);

      // Populate with fake data
      for (i = 0; i < list_size; i++) {
	sprintf(temp_name, "Fulano %d", rand() / list_size);
	sprintf(temp_phone, "(%02d) %04d-%04d", rand() % 99, rand() % 9999, rand() % 9999);

	dllist_insert_tail(&list, tpc_create(temp_name, temp_phone), sizeof(TpContato));
      }

      dllist_print_all_records(list, tpc_generic_print);
      break;

    case 2:
      dllist_free_all(&copy, tpc_generic_free);
      copy = dllist_copy(list, tpc_generic_clone);
      _start = clock();
      dllist_insertion_sort(copy, tpc_generic_cmp);
      time_result = _difftime(_start);
      dllist_print_all_records(copy, tpc_generic_print);
      printf("Tempo: %lf segs\n", time_result);
      break;

    case 3:
      dllist_free_all(&copy, tpc_generic_free);
      copy = dllist_copy(list, tpc_generic_clone);
      _start = clock();
      dllist_selection_sort(copy, tpc_generic_cmp);
      time_result = _difftime(_start);
      dllist_print_all_records(copy, tpc_generic_print);
      printf("Tempo: %lf segs\n", time_result);
      break;

    case 4:
      dllist_free_all(&copy, tpc_generic_free);
      copy = dllist_copy(list, tpc_generic_clone);
      _start = clock();
      dllist_quick_sort(copy, tpc_generic_cmp);
      time_result = _difftime(_start);
      dllist_print_all_records(copy, tpc_generic_print);
      printf("Tempo: %lf segs\n", time_result);
      break;

    case 5:
      dllist_free_all(&copy, tpc_generic_free);
      copy = dllist_copy(list, tpc_generic_clone);
      _start = clock();
      copy = dllist_merge_sort(&copy, tpc_generic_cmp);
      time_result = _difftime(_start);
      dllist_print_all_records(copy, tpc_generic_print);
      printf("Tempo: %lf segs\n", time_result);
      break;

    case 6:
      printf("Bye!\n");
      break;
      
    default:
      printf("Opção inválida! [%d]\n", choice);
    }
    
  } while (choice != EXIT_OPTION);

  dllist_free_all(&list, tpc_generic_free);
  dllist_free_all(&copy, tpc_generic_free);

  return 0;
}
