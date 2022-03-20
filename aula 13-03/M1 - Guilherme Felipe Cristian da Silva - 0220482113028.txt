#include <stdio.h>

int main()
{
  int m[4][4],l,c, cont;
  int s[10], vetor[16];

  for(l = 0; l < 16; l++)
    vetor[l] = 0;

  for(l = 0; l < 10; l++)
    s[l] = 0;

  for(l = 0; l < 4; l++)
  {
    for(c = 0; c < 4; c++)
    {
      printf("[%d] [%d] = ", l, c);
      scanf("%d",&m[l][c]);

      vetor[(l * 4) + c] = m[l][c];

      s[l] += m[l][c];
      s[c + 4] +=m [l][c];
    }

    s[8] += m[l][l];
    s[9] += m[l][3 - l];
  }

  int i, j, aux;
  for(i = 0; i < 4; i++)
  {
    for(j = 0; j < 4-1; j++)
    {
      if (vetor[j] > vetor[j+1])
      {
        aux = vetor[i];
        vetor[i] = vetor[i+1];
        vetor[i+1] = aux;
      }
    }
  }

  for(i = 0; i < 16; i++)
  {
    if(vetor[i] == m[l][c] && vetor[i + 1] == m[l][c])
    {
      printf("\nNao eh quadrado magico");
      return 0;
    }
  }

  for(l = 0; l < 10; l++)
  {
    if(s[0] != s[l])
      cont++;
  }

  if(cont == 0)
    printf("Pode ser um Quadrado Magico");
  else
    printf("Nao eh um Quadrado Magico");

  return 0;
}
