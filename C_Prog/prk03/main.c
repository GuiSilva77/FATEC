#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lib.h"

int main()
{
    int flag = 0;

    banco_dados *db = start_program();

    do {
        flag = dashboard(&db);
    } while (flag);

    end_program(&db);
    return EXIT_SUCCESS;
}