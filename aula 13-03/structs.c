#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tam;
    int *p;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);
    p = (int*)malloc(tam * sizeof(int));

    for(int i = 0;i < tam; i++)
    {
        printf("[%d] = ", i);
        scanf("%d", &p[i]);
    }

    free(p);
    return 0;
}
