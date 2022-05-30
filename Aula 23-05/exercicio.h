#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tAluno {
	int RA;
    char* nome;
    int telefone;
	struct tAluno *prox;
};

typedef struct tAluno Aluno;

void adicionar(Aluno**, Aluno**);
void listar(Aluno*);
void remover(Aluno**);
void esvaziar(Aluno**, Aluno**);
char* inputString();
Aluno* pesquisar_no(Aluno*, int);
Aluno* novo_aluno();

void adicionar_inicio(Aluno**);
void adicionar_fim(Aluno**);
void remover_inicio(Aluno**);
void remover_fim(Aluno*);

Aluno* novo_aluno() {
	Aluno *aux;
	aux = (Aluno *)malloc(sizeof(Aluno));
	if (aux == NULL)
	{
		printf("Sem Memoria\n");
		exit(1);
	}
	
	printf("Digite o RA: ");
	scanf("%d%*c", &aux->RA);

    printf("Digite o Nome do aluno: ");
    aux->nome = inputString();

    printf("Digite o telefone do aluno: ");
    scanf("%d", &aux->telefone);

	aux->prox = NULL;

	return aux;
}

void adicionar(Aluno **inicio, Aluno **fim)
{
	Aluno *novo = novo_aluno();

	if (*(inicio) == NULL)
		*(inicio) = novo;
	else
		(*fim)->prox = novo;

	*(fim) = novo;
}

void listar(Aluno *inicio)
{
	system("cls");
	printf("Listgem de ALunos: \n");
	Aluno *aux;
	if (inicio == NULL) printf("Lista vazia.\n\n");
	else
	{
		aux = inicio;
		while (aux != NULL)
		{
			printf("RA: %d\n", aux->RA);
			printf("Nome: %s\n", aux->nome);
			printf("Telefone: %d\n\n", aux->telefone);
			aux = aux->prox;
		}
	}

	system("Pause");
}

void remover(Aluno **inicio)
{
	Aluno *aux = *(inicio);
	int RA;
	system("cls");
	printf("Digite o RA do aluno para decadastramento: ");
	scanf("%d", &RA);

	Aluno *aluno = pesquisar_no(aux, RA);

	if (aluno == aux)
		*(inicio) = aux->prox;

	if(aluno == NULL) {
		printf("Aluno nao cadastrado.");
		return;
	} else {
		free(aluno);
		printf("Aluno Decadastrado com sucesso.\n");
		system("Pause");
	}
}

Aluno* pesquisar_no(Aluno *ini, int RA)
{
	Aluno *aux = ini;
	while (aux != NULL && aux->RA != RA)
		aux = aux->prox;

	return aux;
}


void esvaziar(Aluno **inicio, Aluno **fim)
{
	Aluno *aux;
	while (*(inicio) != NULL)
	{
		aux = *(inicio);
		*(inicio) = aux->prox;
		free(aux);
	}
	*(fim) = NULL;
}


char *inputString()
{
	//create a function to get input from the user and return it as a string, trimming null characters from the end of the string if necessary and removing leading and trailing whitespace, creating his own functions
	char *string = (char*)malloc(sizeof(char) * 100);
	fgets(string, 100, stdin);
	int len = strlen(string);
	if (string[len - 1] == '\n')
	{
		string[len - 1] = '\0';
	}
	return string;
}

void adicionar_inicio(Aluno **inicio)
{
	Aluno *novo = novo_aluno();

	novo->prox = *(inicio);
	*(inicio) = novo;
}

void adicionar_fim(Aluno **inicio)
{ 
	Aluno *novo = novo_aluno();

	if (*(inicio) == NULL)
		*(inicio) = novo;
	else
	{
		Aluno *aux = *(inicio);
		while (aux->prox != NULL)
			aux = aux->prox;
		
		aux->prox = novo;
	}
}

void remover_inicio(Aluno **inicio)
{
	Aluno *aux = *(inicio);
	*(inicio) = aux->prox;
	free(aux);
}

void remover_fim(Aluno *inicio)
{
	while (inicio->prox->prox != NULL)
		inicio = inicio->prox;
	
	free(inicio->prox);
	inicio->prox = NULL;
}