#include <stdio.h>
#include <stdlib.h>
//exemplo de struct
struct Ponto {
    int x, y;
}z;

int main() {
/*
    struct Ponto v[10]
    v[0].x = 15;
    v[0].y = 32;
*/

    struct Ponto *p;
    p = (struct Ponto*)malloc(sizeof(struct Ponto));
    if (p == NULL)
        printf("Sem Memoria");
    else {
    // (p*).x = 10
    //   |-> op. acesso
    p->x = 10;

    free(p);
    }
    return 0;
}
