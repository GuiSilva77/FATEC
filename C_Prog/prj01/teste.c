#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

enum tipo{
  SAQUE_CC,
  SAQUE_CP,
  DEPOSITO_CC,
  DEPOSITO_CP,
  TRANSFERENCIA_CC,
  TRANSFERENCIA_CP,
};

typedef struct transacao{
  int id;
  enum tipo tipo;
  int valor;
  char *data;
  struct transacao *prox;
};

struct tipo_conta {
  char *nome;
  int cpf;
  int conta_corrente;
  float saldo_conta_poupanca;
  float saldo_conta_corrente;
  int senha;
  struct transacao *transacoes;
  struct tipo_conta *prox;
};

int main()
{


  return EXIT_SUCCESS;
}