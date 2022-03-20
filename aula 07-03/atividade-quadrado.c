#include <stdio.h>
#include <stdlib.h>

#define LINHA 4
#define COLUNA 4

int busca(int mat[LINHA][COLUNA], int chave, int lin, int col);
void mostrar_matriz(int mat[LINHA][COLUNA]);
int validar_quadrado(int mat[LINHA][COLUNA]);

int main()
{
  int matriz[LINHA][COLUNA], i, j;

    for(i = 0; i < LINHA; i++)
    {
        for(j = 0; j < COLUNA; j++)
        {
            printf("Digite um numero para a posicao [%d][%d] do quadrado magico: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
            if(busca(matriz, matriz[i][j], i, j))
            {
                if (i == 0 && j == 0) break;
                printf("Numero repetido, digite outro para a posicao [%d][%d] do quadrado magico: ", i+1, j+1);
                scanf("%d", &matriz[i][j]);
            }
        }
    }

    mostrar_matriz(matriz);

    if (validar_quadrado(matriz))
        printf("Os valores inseridos formam um quadrado magico.\n");
    else
        printf("Os valores inseridos NAO formam um quadrado magico.\n");

    system("pause");
    return 0;
}

int busca(int mat[LINHA][COLUNA], int chave, int lin, int col)
{
    int i, j;
    for(i = 0; i <= lin; i++)
    {
        for(j = 0; j < col; j++)
        {
            if (mat[i][j] == chave)
            {
                if(i == lin && j == col) break;
                return 1;
            }
        }
    }

    return 0;
}

void mostrar_matriz(int mat[LINHA][COLUNA])
{
    int i, j;
    printf("\n Matriz: \n");
    for(i = 0; i < LINHA; i++)
    {
        for(j = 0; j < COLUNA; j++)
        {
            printf(" %d ", mat[i][j]);
        }
        printf("\n");
    }
}

int validar_quadrado(int mat[LINHA][COLUNA])
{
    int soma = 0, soma_diagonalP = 0;
    int i, j;

    /*
        Para avaliar o quadrado mágico, pensei na seguinte solução:
        - são 9 linhas, 9 colunas e 2 diagonais;
        - se todas elas são iguais então a soma dos valores é igual a multilicação da
          diagonal principal pelo numero de linhas;
    */

    //soma dos valores
    for(i = 0; i < LINHA; i++)
    {
        for(j = 0; j < COLUNA; j++)
        {
            if (i == j)
                soma_diagonalP += mat[i][j];

            soma += mat[i][j];
        }
    }

    printf("Soma dos valores: %d\n", soma);
    printf("Soma da diagonal principal: %d\n", soma_diagonalP);
    //teste
        if (soma == (soma_diagonalP * LINHA))
            return 1;
        else
            return 0;
}
