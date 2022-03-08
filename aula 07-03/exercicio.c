#include <stdio.h>
#include <stdlib.h>

int main()
{
  int v[4], i, j;

  for (i = 0; i < 4; i++)
  {
    printf("Digite v[%d]= ", i);
    scanf("%d", &v[i]);
  }

  for (j = 0; j < 3; j++)
  {
    for (i = 0; i < 3; i++)
    {
      if (v[i] > v[i + 1])
      {
        int aux = v[i];
        v[i] = v[i + 1];
        v[i + 1] = aux;
      }
    }
  }

  for (i = 0; i < 4; i++)
    printf(" %d ", v[i]);

  getchar();
  return 0;
}
