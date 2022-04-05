/**
 * @file lib.h  
 * @author Guilherme Silva (guilherme@email.com)
 * @brief Biblioteca de Funções para a o Projeto Banco
 * @version 0.1
 * @date 2022-04-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

//declaração do tipo conta corrente
struct tipo_conta
{
	char *nome;
	int cpf;
	int conta_corrente;
	float saldo_conta_poupanca;
	float saldo_conta_corrente;
	int senha;
	struct tipo_conta *prox;
};

typedef struct tipo_conta Cliente;

/**
 * @brief Função Principal  
 * 
 * @param lista Ponteiro para a lista de Clientes
 * @return int 0 para SUCCESS 1 para FAIL 
 */
int dashboard(Cliente **lista);
/**
   * @brief Função para cadastrar os CLientes
   * 
   * @param lista Ponteiro para lista de Clientes
   */
void cadastrar_cliente(Cliente **lista);			  //v
void acessar_conta(Cliente **lista);				  //v
void menu_conta(Cliente *cliente, Cliente *lista);	  //v
void consultar_saldo(Cliente *cliente, int opcao);	  //v
void saque(Cliente *cliente);						  //v
void transferencia(Cliente *cliente, Cliente *lista); //v
void menu_poupanca(Cliente *cliente);				  //v
void depositar_poupanca(Cliente *cliente);			  //v
void sacar_poupanca(Cliente *cliente);				  //v
													  //void extrato_poupanca(Cliente *cliente); TODO
void deposito(Cliente *lista);						  //v

void remover_cliente(Cliente **lista); //v
void listar_clientes(Cliente *lista);  //v

void adicionar_no(Cliente **lista, Cliente *novo);				 //v
void remover_no(Cliente **lista, int cpf);						 //v
Cliente *buscar_no(Cliente *lista, int conta_corrente, int cpf); //v
int gerar_conta_corrente();										 //v
void limpar_lista(Cliente *lista);								 //v

char *inputString();
void limpar_buffer();

//função da area de trabalho
int dashboard(Cliente **lista)
{
	int opcao = 0;

	time_t curtime;
	time(&curtime);

	do
	{
		system("cls");

		printf(
			"%s"
			"------------------------------------------------------\n\n"
			"                       Banco BR                       \n\n"
			"Digite a opção desejada:\n"
			"1 - Cadastrar Conta\n"
			"2 - Acessar Conta\n"
			"3 - Deposito\n"
			"4 - Sair\n"
			"\n\nOpção: ",
			ctime(&curtime));
		scanf("%d", &opcao);
	} while (opcao < 1 || opcao > 4);

	switch (opcao)
	{
	case 1:
		cadastrar_cliente(lista);
		getchar();
		break;
	case 2:
		acessar_conta(lista);
		break;
	case 3:
		deposito(*lista);
		getchar();
		break;
	case 4:
		return 0;
	case 66:
		listar_clientes(*lista);
		getchar();
		break;
	default:
		printf("Opção inválida!\n");
		getchar();
		break;
	}

	return 1;
}

void cadastrar_cliente(Cliente **lista)
{
	time_t curtime;
	time(&curtime);
	Cliente *novo = (Cliente *)malloc(sizeof(Cliente));
	int cpf = 0;
	int senha;

	system("cls");
	printf(
		"%s"
		"------------------------------------------------------\n\n"
		"                       Banco BR                       \n\n",
		ctime(&curtime));
	fflush(stdin);
	printf("Digite o nome do cliente: ");
	novo->nome = inputString();
	printf("Digite o CPF do cliente: ");
	scanf("%d", &cpf);
	printf("Digite a senha do cliente: ");
	scanf("%d", &senha);

	novo->cpf = cpf;
	novo->senha = senha;
	novo->conta_corrente = gerar_conta_corrente(*lista);
	novo->saldo_conta_poupanca = 0;
	novo->saldo_conta_corrente = 0;
	novo->prox = NULL;

	adicionar_no(lista, novo);

	printf("Conta Criada com Sucesso!\n");
	printf("Sua Conta Corrente: %d\n", novo->conta_corrente);
	limpar_buffer();
}

void adicionar_no(Cliente **lista, Cliente *novo)
{
	Cliente *aux = *lista;
	Cliente *ant = NULL;

	if (*lista == NULL)
	{
		*lista = novo;
	}
	else
	{
		while (aux != NULL && aux->cpf < novo->cpf)
		{
			ant = aux;
			aux = aux->prox;
		}

		if (ant == NULL)
		{
			novo->prox = *lista;
			*lista = novo;
		}
		else
		{
			ant->prox = novo;
			novo->prox = aux;
		}
	}
}

int gerar_conta_corrente(Cliente *lista)
{
	//criar um inteiro aleatorio de 6 digitos, que não se reíta com o que já existe
	int conta_corrente = 0;
	int flag = 0;
	srand(time(NULL));

	do
	{
		conta_corrente = rand() % 100000;
		Cliente *aux = buscar_no(lista, conta_corrente, 0);

		if (aux == NULL)
		{
			flag = 1;
		}
	} while (flag == 0);

	return conta_corrente;
}

Cliente *buscar_no(Cliente *lista, int conta_corrente, int cpf)
{
	Cliente *aux = lista;

	if (cpf == 0)
	{
		while (aux != NULL && (aux->conta_corrente != conta_corrente))
		{
			aux = aux->prox;
		}
	}
	else
	{
		while (aux != NULL && (aux->conta_corrente != conta_corrente || aux->cpf != cpf))
		{
			aux = aux->prox;
		}
	}
	return aux;
}

void remover_no(Cliente **lista, int cpf)
{
	Cliente *aux = *lista;
	Cliente *ant = NULL;

	while (aux != NULL && aux->cpf != cpf)
	{
		ant = aux;
		aux = aux->prox;
	}

	if (aux == NULL)
	{
		printf("Cliente não encontrado!\n");
		fflush(stdin);
		getchar();
	}
	else
	{
		if (ant == NULL)
		{
			*lista = aux->prox;
		}
		else
		{
			ant->prox = aux->prox;
		}
		free(aux);
	}
}

void acessar_conta(Cliente **lista)
{
	time_t curtime;
	time(&curtime);

	int conta_corrente;
	int senha;
	Cliente *cliente;

	system("cls");
	printf(
		"%s"
		"------------------------------------------------------\n\n"
		"                       Banco BR                       \n\n",
		ctime(&curtime));
	printf("Digite o numero da conta corrente: ");
	scanf("%d", &conta_corrente);
	printf("Digite a senha: ");
	scanf("%d", &senha);

	cliente = buscar_no(*lista, conta_corrente, 0);

	if (cliente == NULL)
	{
		printf("Conta não encontrada!\n");
		getchar();
		getchar();
	}
	else
	{
		if (cliente->senha != senha)
		{
			printf("Senha incorreta!\n");
			getchar();
			getchar();
		}
		else
		{
			menu_conta(cliente, *lista);
		}
	}
	limpar_buffer();
}

void menu_conta(Cliente *cliente, Cliente *lista)
{
	int opcao;
	time_t curtime;
	time(&curtime);

	do
	{
		system("cls");

		printf(
			"%s"
			"------------------------------------------------------\n\n"
			"                       Banco BR                       \n\n"
			"Olá %s, seja bem vindo a sua conta!\n\n",
			ctime(&curtime), cliente->nome);
		printf(
			"Digite a opção desejada:\n"
			"1 - Consultar saldo\n"
			"2 - Saque\n"
			"3 - Transferencia\n"
			"4 - Poupança\n"
			"5 - Sair\n"
			"\n\nOpção: ");
		scanf("%d", &opcao);

		switch (opcao)
		{
		case 1:
			consultar_saldo(cliente, 1);
			getchar();
			break;
		case 2:
			saque(cliente);
			getchar();
			break;
		case 3:
			transferencia(cliente, lista);
			getchar();
			break;
		case 4:
			menu_poupanca(cliente);
			break;
		case 5:
			break;
		}
	} while (opcao != 5);
}

void consultar_saldo(Cliente *cliente, int opcao)
{
	if (opcao == 1)
	{
		printf("Saldo da conta corrente: R$ %.2f\n", cliente->saldo_conta_corrente);
		limpar_buffer();
	}
	else
	{
		printf("Saldo da conta poupança: R$ %.2f\n", cliente->saldo_conta_poupanca);
		limpar_buffer();
	}
}

void saque(Cliente *cliente)
{
	time_t curtime;
	time(&curtime);
	int valor;
	int saldo;
	int senha;

	system("cls");
	printf(
		"%s"
		"------------------------------------------------------\n\n"
		"                       Banco BR                       \n\n",
		ctime(&curtime));

	if (cliente->saldo_conta_corrente == 0)
	{
		printf("Saldo Insuficiente\n");
		limpar_buffer();
		return;
	}

	printf("Saldo: R$ %.2f\n\n", cliente->saldo_conta_corrente);
	printf("Digite o valor do saque: ");
	scanf("%d", &valor);

	saldo = cliente->saldo_conta_corrente;

	printf("\nDigite a senha: ");
	scanf("%d", &senha);

	if (senha != cliente->senha)
	{
		printf("Senha incorreta!\n");
		limpar_buffer();
		getchar();
	}
	else
	{
		if (valor > saldo)
		{
			printf("Saldo insuficiente!\n");
			limpar_buffer();
			getchar();
		}
		else
		{
			cliente->saldo_conta_corrente -= valor;
			printf("Saque realizado com sucesso!\n");
			limpar_buffer();
			getchar();
		}
	}
}

void transferencia(Cliente *cliente, Cliente *lista)
{
	time_t curtime;
	time(&curtime);
	int conta_corrente_destino;
	int valor;
	int senha;
	Cliente *cliente_destino;

	system("cls");
	printf(
		"%s"
		"------------------------------------------------------\n\n"
		"                       Banco BR                       \n\n",
		ctime(&curtime));

	if (cliente->saldo_conta_corrente == 0)
	{
		printf("Saldo Insuficiente\n");
		limpar_buffer();
		return;
	}

	printf("Saldo: R$ %.2f\n\n", cliente->saldo_conta_corrente);
	printf("Digite o numero da conta corrente de destino: ");
	scanf("%d", &conta_corrente_destino);

	cliente_destino = buscar_no(lista, conta_corrente_destino, 0);

	if (cliente_destino == NULL)
	{
		printf("Conta não encontrada!\n");
		getchar();
	}
	else
	{
		printf("Digite o valor da transferencia: ");
		scanf("%d", &valor);

		printf("\nDigite a senha: ");
		scanf("%d", &senha);

		if (senha != cliente->senha)
		{
			printf("Senha incorreta!\n");
		}
		else
		{
			if (valor > cliente->saldo_conta_corrente)
			{
				printf("Saldo insuficiente!\n");
			}
			else
			{
				cliente->saldo_conta_corrente -= valor;
				cliente_destino->saldo_conta_corrente += valor;
				printf("Transferencia realizada com sucesso!\n");
				getchar();
			}
		}
	}
}

void menu_poupanca(Cliente *cliente)
{
	time_t curtime;
	time(&curtime);
	int opcao;

	do
	{
		system("cls");
		printf(
			"%s"
			"------------------------------------------------------\n\n"
			"                       Banco BR                       \n\n",
			ctime(&curtime));
		printf(
			"Poupança:\n\n"
			"Digite a opção desejada:\n"
			"1 - Consultar saldo\n"
			"2 - Transferir para conta poupanca\n"
			"3 - Transferir para conta corrente\n"
			"4 - Sair\n"
			"\n\nOpção: ");
		scanf("%d", &opcao);

		switch (opcao)
		{
		case 1:
			consultar_saldo(cliente, 0);
			getchar();
			break;
		case 2:
			depositar_poupanca(cliente);
			getchar();
			break;
		case 3:
			sacar_poupanca(cliente);
			getchar();
			break;
		case 4:
			break;
		}
	} while (opcao < 4);
}

void depositar_poupanca(Cliente *cliente)
{
	time_t curtime;
	time(&curtime);
	int valor;
	int senha;

	system("cls");
	printf(
		"%s"
		"------------------------------------------------------\n\n"
		"                       Banco BR                       \n\n",
		ctime(&curtime));

	if (cliente->saldo_conta_corrente == 0)
	{
		printf("Saldo Insuficiente\n");
		limpar_buffer();
		return;
	}

	printf("Saldo: R$ %.2f\n\n", cliente->saldo_conta_corrente);
	printf("Digite o valor do deposito: ");
	scanf("%d", &valor);

	printf("\nDigite a senha: ");
	scanf("%d", &senha);

	if (senha != cliente->senha)
	{
		printf("Senha incorreta!\n");
		limpar_buffer();
		getchar();
	}
	else
	{
		cliente->saldo_conta_poupanca += valor;
		printf("Deposito realizado com sucesso!\n");
		limpar_buffer();
		getchar();
	}
}

void sacar_poupanca(Cliente *cliente)
{
	time_t curtime;
	time(&curtime);
	int valor;
	int saldo;
	int senha;

	system("cls");
	printf(
		"%s"
		"------------------------------------------------------\n\n"
		"                       Banco BR                       \n\n",
		ctime(&curtime));

	if (cliente->saldo_conta_corrente == 0)
	{
		printf("Saldo Insuficiente\n");
		limpar_buffer();
		return;
	}

	printf("Saldo: R$ %.2f\n\n", cliente->saldo_conta_poupanca);
	printf("Digite o valor do saque: ");
	scanf("%d", &valor);

	saldo = cliente->saldo_conta_poupanca;

	printf("\nDigite a senha: ");
	scanf("%d", &senha);

	if (senha != cliente->senha)
	{
		printf("Senha incorreta!\n");
		limpar_buffer();
		getchar();
	}
	else
	{
		if (valor > saldo)
		{
			printf("Saldo insuficiente!\n");
			limpar_buffer();
			getchar();
		}
		else
		{
			cliente->saldo_conta_poupanca -= valor;
			printf("Saque realizado com sucesso!\n");
			limpar_buffer();
			getchar();
		}
	}
}

void deposito(Cliente *lista)
{
	time_t curtime;
	time(&curtime);
	int conta_corrente_destino;
	int valor;

	system("cls");
	printf(
		"%s"
		"------------------------------------------------------\n\n"
		"                       Banco BR                       \n\n",
		ctime(&curtime));
	printf("Digite o numero da conta corrente de destino: ");
	scanf("%d", &conta_corrente_destino);

	Cliente *cliente_destino = buscar_no(lista, conta_corrente_destino, 0);

	if (cliente_destino == NULL)
	{
		printf("Conta não encontrada!\n");
		getchar();
		return;
	}
	else
	{
		printf("Digite o valor do deposito: ");
		scanf("%d", &valor);

		cliente_destino->saldo_conta_corrente += valor;
		printf("Deposito realizado com sucesso!\n");
		getchar();
	}
	limpar_buffer();
}

void limpar_lista(Cliente *lista)
{
	Cliente *aux = lista;
	Cliente *proximo;

	while (aux != NULL)
	{
		proximo = aux->prox;
		free(aux);
		aux = proximo;
	}
}

void listar_clientes(Cliente *lista)
{
	Cliente *aux = lista;

	while (aux != NULL)
	{
		printf("\nNome: %s\n", aux->nome);
		printf("CPF: %d\n", aux->cpf);
		printf("Conta corrente: %d\n", aux->conta_corrente);
		printf("Saldo da conta corrente: R$ %.2f\n", aux->saldo_conta_corrente);
		printf("Saldo da conta poupança: R$ %.2f\n", aux->saldo_conta_poupanca);
		printf("Senha: %d\n", aux->senha);
		printf("\n");
		system("pause");
		aux = aux->prox;
	}
}

char *inputString()
{
	//create a function to get input from the user and return it as a string, trimming null characters from the end of the string if necessary and removing leading and trailing whitespace, creating his own functions
	char *string = malloc(sizeof(char) * 100);
	fgets(string, 100, stdin);
	int len = strlen(string);
	if (string[len - 1] == '\n')
	{
		string[len - 1] = '\0';
	}
	return string;
}

void limpar_buffer()
{
	char ch;
	while ((ch = getchar()) != '\n' && ch != EOF)
		;
}