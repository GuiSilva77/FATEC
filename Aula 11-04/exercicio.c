#include <stdio.h>
#include <stdlib.h>

struct tPessoa {
	int RA;
	struct tPessoa *ant;
	struct tPessoa *prox;
};

typedef struct tPessoa Pessoa;

void adicionar_inicio(Pessoa**, Pessoa**);
Pessoa *novoElemento();
void listar_fila(Pessoa*);
void listar_pilha(Pessoa*);
void remover(Pessoa**);
void esvaziar_fila(Pessoa**);
void limpar_buffer();

int main()
{
	Pessoa *inicio = NULL;
	Pessoa *fim = NULL;
	char op;

	do {
		printf(
			"\n1 - Inserir\n"
			"2 - Listar\n"
			"3- remover\n"
			"4- Esvaziar\n"
			"5- Sair\n"
			"6- Listar como Fila\n");

		limpar_buffer();
		op = getchar();

		switch (op)
		{
		case '1': // Inserir
			adicionar_inicio(&inicio, &fim);
			break;

		case '2': // listar
			listar_pilha(inicio);
			break;

		case '3': // remover
			remover(&inicio);
			break;

		case '4': // esvaziar;
			esvaziar_fila(&inicio);
			break;

		case '6':
			listar_fila(fim);
			break;
		
		default:
			break;
		}
	} while (op != '5');

	esvaziar_fila(&inicio);
	getchar();
	return 0;
}

Pessoa *novoElemento()
{
	Pessoa *aux = (Pessoa *)malloc(sizeof(Pessoa));
	if (aux == NULL)
	{
		printf("Sem Memória\n");
		exit(1); // saida forçada do programa
	}
	
	// inserção dos dados
	printf("\nDigite o RA: ");
	scanf("%d", &aux->RA);

	aux->prox = NULL;
	aux->ant = NULL;

	return aux;
}

void adicionar_inicio(Pessoa **inicio, Pessoa **fim)
{
	Pessoa *aux = novoElemento();

	if (*inicio == NULL) {
		*inicio = aux;
		*fim = aux;	
	}
	else {
		aux->prox = *inicio;
		(*inicio)->ant = aux;
		*inicio = aux;
	}
}

void listar_pilha(Pessoa *inicio)
{
	Pessoa *aux = inicio;

	if (aux == NULL)
		printf("\nPilha Vazia\n");
	else {
		while (aux != NULL) {
			printf("\nRA: %d", aux->RA);
			aux = aux->prox;
		}
	}
}

void listar_fila(Pessoa *inicio)
{
	Pessoa *aux;
	// se lista for vazia
	if (inicio == NULL) printf("\n\nLista vazia.\n\n");
	else
	{
		aux = inicio;
		while (aux != NULL)
		{
			printf("\nRA: %d\n\n", aux->RA);
			aux = aux->ant;
		}
	}
}

void remover(Pessoa **inicio)
{
	Pessoa *aux = *(inicio);
	*(inicio) = aux->prox;
	free(aux);
	aux = NULL;
}

void esvaziar_fila(Pessoa **inicio)
{
	Pessoa *aux;
	while (*(inicio) != NULL)
	{
		aux = *(inicio);
		*(inicio) = aux->prox;
		free(aux);
	}
}

void limpar_buffer()
{
	char ch;
	while ((ch = getchar()) != '\n' && ch != EOF) {}
}