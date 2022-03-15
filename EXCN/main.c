#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct tipo_no_prod {
    char *nome;
    unsigned int codigo;
    float preco;
    no_prod *prox;
};

typedef struct tipo_no_prod no_prod;

void adicionar_inicio(no **lista);

int main()
{
    setlocale(LC_ALL, "portuguese");





    return 0;
}

