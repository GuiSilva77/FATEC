#include <stdio.h>
#include <stdlib.h>

#define LINHA 9
#define COLUNA 9

int busca(int mat[LINHA][COLUNA], int chave, int lin, int col);
void mostrar_matriz(int mat[LINHA][COLUNA]);
int validar_quadrado(int mat[LINHA][COLUNA]);

int main()
{
  int matriz[9][9], i, j;  

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
    int soma_linhas[LINHA], soma_colunas[COLUNA], soma_diagonalP = 0, soma_diagonalS = 0;
    int i, j, soma;
    
    //zerando os vetores
    for (i = 0; i < LINHA; i++)
    {
      soma_linhas[i] = 0;
      soma_colunas[i] = 0;
    }

    /*
        Para avaliar o quadrado mágico, pensei na seguinte solução:
        - são 9 linhas, 9 colunas e 2 diagonais;
        - se todas elas são iguais então a soma de todas elas é igual a multilicação
          de uma linha pelo número de linhas, colunas e diagonais;
    */
    
    //soma dos valores
    for(i = 0; i < LINHA; i++)
    {
        for(j = 0; j < COLUNA; j++)
        {
          //soma da diagonal principal
          if (i == j)
            soma_diagonalP += mat[i][j];
          
          //soma da diagonal secundaria
          if ((i + j) == (LINHA - 1))
            soma_diagonalS += mat[i][j];

          //soma das linhas
          soma_linhas[i] += mat[i][j];

          //soma das colunas
          soma_colunas[j] += mat[i][j];
        }
    }

    //soma geral
    for(i = 0; i < LINHA; i++)
    {
        soma += soma_linhas[i];
        soma += soma_colunas[i];
    }

    //soma da diagonal principal
    soma += soma_diagonalP;

    //soma da diagonal secundaria
    soma += soma_diagonalS;

    //imprimir a soma das linhas, colunas e diagonais
    printf("\nSoma das linhas: ");
    for(i = 0; i < LINHA; i++)
    {
        printf("%d ", soma_linhas[i]);
    }
    printf("\nSoma das colunas: ");
    for(i = 0; i < COLUNA; i++)
    {
        printf("%d ", soma_colunas[i]);
    }

    printf("\n\nSoma da diagonal principal: %d\n", soma_diagonalP);
    printf("Soma da diagonal secundaria: %d\n\n", soma_diagonalS);

    //teste
        if (soma == soma_linhas[1] * (LINHA + COLUNA + 2))
            return 1;
        else
            return 0;
}