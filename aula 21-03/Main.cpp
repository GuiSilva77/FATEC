#include <stdio.h>
#include <stdlib.h>

typedef struct Pessoa {
	int RA; // dado do User
	Pessoa *prox;
};

int main()
{
	Pessoa *fim, *aux, *inicio = NULL;
	char op;

	do {
		printf(
			"\n1 - Inserir\n"
			"2 - Listar\n"
			"3- remover\n"
			"4- Esvaziar\n"
			"5- Sair\n");

		char ch;
		while ((ch = getchar()) != '\n' && ch != EOF) { }

		op = getchar();
		switch (op)
		{
		case '1': // Inserir

			// alocação do novo elemento
			aux = (Pessoa *)malloc(sizeof(Pessoa));
			if (aux == NULL)
			{
				printf("Sem Memória\n");
				exit(1); // saida forçada do programa
			}
			// inserção dos dados
			printf("\nDigite o RA: ");
			scanf("%d", &aux->RA);

			aux->prox = NULL;

			// se inserção do primeiro elemento
			if (inicio == NULL)
				inicio = aux;
			else
				fim->prox = aux;

			fim = aux;
			break;

		case '2': // listar

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
			break;

		case '3': // remover
			aux = inicio;
			inicio = aux->prox;
			free(aux);
			aux = NULL;
			break;

		case '4': // esvaziar;
			while (inicio != NULL)
			{
				aux = inicio;
				inicio = aux->prox;
				free(aux);
			}
			fim = NULL;
			break;

		default:
			break;
		}
	} while (op != '5');

	while (inicio != NULL)
	{
		aux = inicio;
		inicio = aux->prox;
		free(aux);
	}

	getchar();
	return 0;
}
