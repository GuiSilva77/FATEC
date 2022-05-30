/**
 * @file diario.h
 * @author Guilherme Silva (you@domain.com)
 * @brief Biblioteca de funções para o processamento de entrada e saida do diario
 * @version 0.1
 * @date 2022-04-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "diario_tipos.h"
#include <time.h>


// void diario_apagar(Diario *diario);


Lancamento* lancamento_criar();
void lancamento_imprimir(Lancamento *lancamento);
void lancamento_destruir(Lancamento *lancamento);


void modalidade_criar(Modalidade **modalidade);
void modalidade_escrever(struct no_modalidade *modalidade, int opcao);
void modalidade_imprimir(Modalidade *modalidade);
void modalidade_destruir(Modalidade **modalidade);


uint32_t gerar_id();
char* entrada_string();
Data entrada_data();
void limpar_buffer();

void lancamento_imprimir(Lancamento *lancamento)
{
    printf(
        "Id: %d\n"
        "Lancamento: \n"
        "Data: %d/%d/%d\n", lancamento->id,lancamento->data.dia, lancamento->data.mes, lancamento->data.ano
    );

    printf("\nDescricao: %s\n", lancamento->descricao);

    modalidade_imprimir(lancamento->modalidade);

    printf("\n");
}

void modalidade_imprimir(Modalidade *modalidade)
{
    printf("Modalidade: \n");
    
    while (modalidade != NULL)
    {
        printf("\n");
        printf("Debito: %s R$%.2f\n",
            modalidade->debito.conta,
            modalidade->debito.valor
        );
        printf("Credito: %s R$%.2f\n\n",
            modalidade->credito.conta,
            modalidade->credito.valor
        );
        
        modalidade = modalidade->prox;
    }
}

void modalidade_escrever(struct no_modalidade *modalidade, int opcao)
{
    modalidade->id = gerar_id();

    modalidade->tipo_entrada = opcao == 0 ? DEBITO : CREDITO;

    printf("Digite o nome da conta: ");
    modalidade->conta = entrada_string();

    printf("Digite o valor: ");
    scanf("%lf", &modalidade->valor);
    limpar_buffer();
    
}

void modalidade_criar(Modalidade **modalidade)
{
    Modalidade *aux = NULL;
    int opcao;

    do {
        aux = (Modalidade*) malloc(sizeof(Modalidade));

        modalidade_escrever(&aux->debito, 0);
        modalidade_escrever(&aux->credito, 1);

        aux->prox = NULL;

        if (*(modalidade) == NULL)
            *(modalidade) = aux;
        else
            (*modalidade)->fim->prox = aux;            

        (*modalidade)->fim = aux;

        printf("Deseja adicionar mais uma modalidade? (S/N)");
        scanf("%c", &opcao);

        limpar_buffer();
    } while (opcao == 'S');
}

uint32_t gerar_id()
{
    //generate a ramdom 32 bit number
    uint32_t id = 0;
    srand(time(NULL));
    id = rand();

    //return the random number
    return id;
}

char* entrada_string()
{
    char *string = malloc(sizeof(char) * 280);
    fgets(string, 280, stdin);
    int len = strlen(string);
    if (string[len - 1] == '\n') 
    {
        string[len - 1] = '\0';
    }

    limpar_buffer();

    return string;
}

Data entrada_data()
{
    Data data;

    //get date from time.h and store it in data
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    data.dia = tm->tm_mday;
    data.mes = tm->tm_mon + 1;
    data.ano = tm->tm_year + 1900;

    return data;
}

Lancamento* lancamento_criar()
{
    Lancamento *lancamento = (Lancamento*) malloc(sizeof(Lancamento));

    lancamento->id = gerar_id();
    lancamento->data = entrada_data();

    lancamento->descricao = entrada_string();

    lancamento->modalidade = NULL;
    modalidade_criar(&lancamento->modalidade);

    lancamento->prox = NULL;

    return lancamento;
}

void limpar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void modalidade_destruir(Modalidade **modalidade)
{
    Modalidade *aux = *modalidade;
    Modalidade *prox = NULL;

    while (aux != NULL)
    {
        prox = aux->prox;
        free(aux);
        aux = prox;
    }
}

void lancamento_destruir(Lancamento *lancamento)
{
    free(lancamento->descricao);
    modalidade_destruir(&lancamento->modalidade);
    free(lancamento);
}
