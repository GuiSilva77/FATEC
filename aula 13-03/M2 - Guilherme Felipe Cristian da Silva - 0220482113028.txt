#include <stdio.h>

int main()
{
  int m[4][4],l,c, cont;
  int s[10];

  for(l = 0; l < 10; l++)
    s[l] = 0;

  for(l = 0; l < 4; l++)
  {
    for(c = 0; c < 4; c++)
    {
      printf("[%d] [%d] = ", l, c);
      scanf("%d",&m[l][c]);

      int i, j;
      for(i = 0; i <= l; i++)
      {
        for(j = 0; j < c; j++)
        {
          if (m[i][j] == m[l][c])
          {
            if(i == l && j == c) break;
            printf("Nao eh qadrado magico.");
            return 0;
          }
        }
      }

      s[l] += m[l][c];
      s[c + 4] +=m [l][c];
    }

    s[8] += m[l][l];
    s[9] += m[l][3 - l];
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
