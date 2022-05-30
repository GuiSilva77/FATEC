#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

int main(int argc, char const *argv[])
{
    Lancamento *lancamento = lancamento_criar();

    lancamento_imprimir(lancamento);

    lancamento_destruir(lancamento);
    
    system("pause");
    return 0;
}
