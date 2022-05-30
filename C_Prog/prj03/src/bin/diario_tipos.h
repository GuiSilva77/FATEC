/**
 * @file tipos.h
 * @author Guilherme Silva (you@domain.com)
 * @brief biblioteca de tipos para o processamento de entrada e saida
 *  do diario
 * @version 0.1
 * @date 2022-04-22
 * 
 * @copyright Copyright (c) 2022
 */

#include <stdint.h>

struct tipo_data {
    uint8_t dia;
    uint8_t mes;
    uint16_t ano;
};

typedef struct tipo_data Data;

struct no_modalidade {
    uint32_t id;
    enum { DEBITO, CREDITO } tipo_entrada;
    int id_conta;
    char *conta;
    double valor;
};

struct tipo_modalidade {
    struct no_modalidade debito;
    struct no_modalidade credito;
    
    struct tipo_modalidade *prox;
    struct tipo_modalidade *fim;
};

typedef struct tipo_modalidade Modalidade;

struct tipo_lancamento {
    uint32_t id;
    Data data;
    char *descricao;
    Modalidade *modalidade;

    struct tipo_lancamento *prox;
};

typedef struct tipo_lancamento Lancamento;

struct diario {
    Lancamento *lancamentos;
    int num_lancamentos;
};

typedef struct diario Diario;