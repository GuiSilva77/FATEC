#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *arr, int n);

int main()
{
  int *vetNumeros = malloc(10 * sizeof(int));
  int tamanhoVetor = 0;
  char pergunta;

  int i = 0;
  for (i = 0; i < 10; i++)
  {
    if (i >= 6)
    {
      printf("Deseja ordenar o vetor ? (S/N) : ");
      scanf("%s", &pergunta);

      if (pergunta == 'S')
      {
        tamanhoVetor = i;

        bubble_sort(vetNumeros, tamanhoVetor);

        for (q = 0; q <= tamanhoVetor; q++)
        {
        printf("%d ", vetNumeros[q]);
        }

        break;
      }
    }

    fflush(stdin);

    printf("Informe o valor da posicao [%d] : ", i);
    scanf("%d", &vetNumeros[i]);
    tamanhoVetor = i;
  }

  getchar();
  return 0;
}

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