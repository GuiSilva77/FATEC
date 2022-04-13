#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <stdint.h>
#include "types.h"
/**
 * @brief Função que inicializa os dados do programa
 * 
 * @return banco_dados 
 */
banco_dados* start_program();

/**
 * @brief Função que termina on que for necessário para a finalização do programa;
 * 
 * @param banco_dados Ponteiro para o Banco de dados; 
 */
void end_program(banco_dados**);
int dashboard(banco_dados**);
void lancamento(banco_dados**);

banco_dados* start_program()
{
    return (banco_dados* )malloc(sizeof(banco_dados));
}

void end_program(banco_dados** db)
{
    free(*db);
}

int dashboard(banco_dados** db)
{
    char op;

    do {
        printf(
            "Digite a Opção para a aplicação: \n"
            "1- Fazer Lançamento\n"
            "2- Verificar Lançamento\n"
            "3- Gerar Balanço\n"
            "4- Sair"
            "Opção: "
        );
        op = getche();
    } while(op != '4'); 

    switch(op)
    {
        case '1':
            lancamento(&db);
        break;
        case '2':
            verificar_lancamento(&db);
        break;
        case '3':
            gerar_balanco(db);
        break;
        case '4':
            return 0;
        break;
        default:
        break;
    }
    return 1;
}

void lancamento(banco_dados** db) 
{
    uint8_t data;
    struct diary_node lancamento;
    system("cls");
    printf("Digite a data do Lançamento (dd-mm-yyyy): ");
    scanf("%d", &data);
    insert_date(lancamento.date, data);

}

