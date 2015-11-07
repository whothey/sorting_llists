#include "tpcontato.h"

TpContato* tpc_create(char *name, char *phone)
{
  TpContato *record = NULL;

  record = (TpContato *)malloc(sizeof(TpContato));
  strcpy(record->nome, name);
  strcpy(record->fone, phone);

  return record;
}

void tpc_free(TpContato **record)
{
  tpc_generic_print((void *) (*record));
  free(*record);

  *record = NULL;
}

void tpc_generic_free(void **record)
{
  tpc_free((TpContato **) record);
}

void tpc_generic_print(void *item)
{
  TpContato *record = (TpContato *) item;

  printf("--------------------------------\n");
  printf("%5s: %s\n", "Nome", record->nome);
  printf("%5s: %s\n", "Fone", record->fone);
  printf("--------------------------------\n");
}
