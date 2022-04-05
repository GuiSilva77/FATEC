#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "lib.h"


int main()
{
  setlocale(LC_ALL, "portuguese");

  Cliente *lista = NULL;
  int flag;

  do {
    flag = dashboard(&lista);
  } while (flag);

  limpar_lista(lista);
  return EXIT_SUCCESS;
}
