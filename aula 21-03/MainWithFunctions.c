#include <stdio.h>
#include <stdlib.h>

struct tPessoa {
	int RA;
	struct tPessoa *prox;
};

typedef struct tPessoa Pessoa;

void adicionar_inicio(Pessoa**, Pessoa**);
void listar_fila(Pessoa*);
void remover(Pessoa**);
void esvaziar_fila(Pessoa**, Pessoa**);
void limpar_buffer();

int main()
{
	Pessoa *fim, *inicio = NULL;
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
			adicionar_inicio(&inicio, &fim);
			break;

		case '2': // listar
			listar_fila(inicio);
			break;

		case '3': // remover
			remover(&inicio);
			break;

		case '4': // esvaziar;
			esvaziar_fila(&inicio, &fim);
			break;

		default:
			break;
		}
	} while (op != '5');

	esvaziar_fila(&inicio, &fim);
	getchar();
	return 0;
}

void adicionar_inicio(Pessoa **inicio, Pessoa **fim)
{
	Pessoa *aux;
	// alocação do novo elemento
	aux = (Pessoa *)malloc(sizeof(Pessoa));
	if (aux == NULL)
	{
		printf("Sem Memória\n");
		exit(1); // saida forçada do programa
	}
	// inserção dos dados
	printf("Digite o RA: ");
	scanf("%d", &aux->RA);

	aux->prox = NULL;

	// se inserção do primeiro elemento
	if (*(inicio) == NULL)
		*(inicio) = aux;
	else
		(*fim)->prox = aux;

	*(fim) = aux;
}

void listar_fila(Pessoa *inicio)
{
	Pessoa *aux;
	// se lista for vazia
	if (inicio == NULL) printf("Lista vazia.\n\n");
	else
	{
		aux = inicio;
		while (aux != NULL)
		{
			printf("RA: %d\n\n", aux->RA);
			aux = aux->prox;
		}
	}
}

void remover(Pessoa **inicio)
{
	Pessoa *aux = *(inicio);
	*(inicio) = aux->prox;
	free(aux);
}

void esvaziar_fila(Pessoa **inicio, Pessoa **fim)
{
	Pessoa *aux;
	while (*(inicio) != NULL)
	{
		aux = *(inicio);
		*(inicio) = aux->prox;
		free(aux);
	}
	*(fim) = NULL;
}

void limpar_buffer()
{
	char ch;
	while ((ch = getchar()) != '\n' && ch != EOF) {}
}
