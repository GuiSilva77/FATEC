/**
 * @brief Programa que implementa a ordenação de um vetor de inteiros.
 *
 *  O programa faz a ordenação de um vetor de inteiros que foi digitado pelo
 * usuário. O método usado é a ordenação por bolha, que faz sucessivas comparações
 * entre os elementos do vetor, e troca-os caso necessário.
 *
 * @file TR1- Guilherme Felipe Cristian da Silva - 0220482113028.txt
 **/

// macro para o compilador ignorar warnings de incompatibilidade de funções
#define _CRT_SECURE_NO_WARNINGS

// inclusão das bibliotecas
#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *, int);
void mostrar_array(int *, int);

int main()
{
  int *vetor = (int *)malloc(sizeof(int) * 1000);

  int i = 0;
  do
  {
    if (i < 6)
      printf("Digite um numero inteiro ou digite -1 para sair: ");
    else
      printf("Digite:\n Um numero inteiro;\n -1 para sair\n -2 para ordenar o vetor\n\n numero: ");
    scanf("%d", &vetor[i]);

    if (vetor[i] == -1)        /*  Opção de saída do programa  */
    {
      free(vetor);
      return 0;
    }

    if (vetor[i] == -2)        /*  Opção de ordenar            */
    {
      mostrar_array(vetor, i);
      bubble_sort(vetor, i - 1);
      mostrar_array(vetor, i);
      vetor[i] = 0; /* Limpa a posição que foi digitada a opção     */
      i--;          /* Volta o contadar em uma casa                 */
    }
    i++;
  } while (vetor[i-1] != -1 && i <= 999);

  printf("Voce digitou mais de 1000 numeros, comece novamente.\n");

  getchar();
  return 1;
}

/**
 * @brief Função que ordena um vetor de inteiros.
 * 
 * @param arr ponteiro para o array de inteiros
 * @param n  tamanho do array
 */
void bubble_sort(int *arr, int n)
{
  int i=0, m=1, aux=0, troca = 1;
  while (m <= n && troca == 1)
  {
    troca = 0;
    for (i = 0; i < n; i++)
    {
      if (arr[i] > arr[i+1])
      {
        troca = 1;
        aux = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = aux;
      }
    }

    m += 1;
  }
}

// função que mostra o vetor na tela
void mostrar_array(int *arr, int n)
{
  int i = 0;
  printf("\nVetor: ");

  for (i = 0; i < n; i++)
    printf("%d ", arr[i]);

  printf("\n");
}

