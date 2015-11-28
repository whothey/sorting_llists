#ifndef _TpContato
#define _TpContato

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 40
#define MAX_FONE 30

typedef struct _contato {
  char nome[MAX_NOME];
  char fone[MAX_FONE];
} TpContato;

/**
 * Creates an new instance of the struct TpContato and returns its reference
 */
TpContato* tpc_create(char *name, char *fone);

void tpc_free(TpContato **record);
void tpc_generic_free(void **record);

int tpc_cmp_name(char name[MAX_NOME], TpContato *contact);

/**
 * Generic item comparison for dllist
 */
int tpc_generic_cmp(const void *, const void *);

void tpc_generic_print(void *item);

/**
 * Generic function to clone the referenced object
 */
void* tpc_generic_clone(void *item);

#endif
