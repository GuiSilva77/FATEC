/**
  * @date 22-03-21
  *
  * @author Guilherme Silva
  *
  * @brief Aula 21-03 Estrutura de Dados
  */

#include <stdio.h>
#include <stdlib.h>

typedef struct Pessoa {
    int RA; // dado do USR
    Pessoa *prox;
};

int main()
{
    Pessoa *fim, *aux, *inicio = NULL;
    char op;

    do {
        printf("1- Inserir\n"
               "2- Listar\n"
               "3- Remover\n"
               "4- Esvaziar\n"
               "5- Sair\n"
               );
        op = getchar();

        switch(op)
        {
        case 1: // Inserir

            // alocação do novo elemento
            aux = (Pessoa *)malloc(sizeof(Pessoa));
            if(aux == NULL)
            {
                printf("Sem Memoria.");
                exit(1); // Saída forçada do programa
            }

            // Inserção dos dados
            printf("Digite o RA: ");
            scanf("%d", &aux->RA);

            aux->prox = NULL;

            // Se inserção do primeiro elemento
            if(inicio == NULL)
                inicio = aux;
            else // Se inserção de outro elemento
                fim->prox = aux;

            fim = aux;
        break;
        case 2: // Listar

            // Se lista for vazia
            if (inicio == NULL) printf("Lista vazia.");
            else
            {
                aux = inicio; // aux vai para o inicio da lista
                while(aux != NULL) // Loop até o fim da lista
                {
                    printf("RA: %d", aux->RA);
                    aux = aux->prox;
                }
            }
        break;
        case 3: // Remover
            aux = inicio;
            inicio = aux.prox;
            free(aux);
        break;
        case 4: // Esvaziar
          Cliente *proximo;

          while (aux != NULL) {
            proximo = aux->prox;
            free(aux);
            aux = proximo;
          }
        break;
        case 5: // Sair

        break;
        default:
        break;
        }
    } while (op != '5');



    getchar();
    return 0;
}
