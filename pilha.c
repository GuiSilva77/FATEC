#include <stdio.h>
#include <stdlib.h>

struct tPessoa {
	int RA;
	struct tPessoa *prox;
};

typedef struct tPessoa Pessoa;

void adicionar_inicio(Pessoa**);
Pessoa *novoElemento();
void listar_fila(Pessoa*);
void remover(Pessoa**);
void esvaziar_fila(Pessoa**);
void limpar_buffer();

int main()
{
	Pessoa *inicio = NULL;
	char op;

	do {
		printf(
			"\n1 - Inserir\n"
			"2 - Listar\n"
			"3- remover\n"
			"4- Esvaziar\n"
			"5- Sair\n");

		limpar_buffer();
		op = getchar();

		switch (op)
		{
		case '1': // Inserir
			adicionar_inicio(&inicio);
			break;

		case '2': // listar
			listar_fila(inicio);
			break;

		case '3': // remover
			remover(&inicio);
			break;

		case '4': // esvaziar;
			esvaziar_fila(&inicio);
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

	return aux;
}

void adicionar_inicio(Pessoa **inicio)
{
	Pessoa *aux = novoElemento();

	if (inicio == NULL)
		*inicio = aux;
	else {
		aux->prox = *inicio;
		*inicio = aux;
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
			aux = aux->prox;
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
