#include <stdio.h>
#include <stdlib.h>
#include "exercicio.h"

int main()
{
	Aluno *fim, *inicio = NULL;
	char op;

	do {
        system("cls");
		printf(
			"Sistema de Alunos\n\n"
            "Digite uma opcao:\n"
            "1- Listar Alunos;\n"
            "2- Adicionar Aluno;\n"
            "3- Remover Aluno;\n"
            "4- Esvaziar Lista de Alunos;\n"
			"5- Adicionar Inicio;\n"
			"6- Adicionar Fim;\n"
			"7- remover Inicio;\n"
			"8- remover Fim;\n"
            "9- Sair;\n\nOpcao: ");

		op = getchar();

		switch (op)
		{
		case '1': // Inserir
			listar(inicio);
			break;

		case '2': // listar
			adicionar(&inicio, &fim);
			break;

		case '3': // remover
			remover(&inicio);
			break;

		case '4': // esvaziar;
			esvaziar(&inicio, &fim);
			break;
		
		case '5': // adicionar inicio
			adicionar_inicio(&inicio);
			break;

		case '6': // adicionar fim
			adicionar_fim(&inicio);
			break;

		case '7': // remover inicio
			remover_inicio(&inicio);
			break;

		case '8': // remover fim
			remover_fim(inicio);
			break;

		default:
			break;
		}
	} while (op != '9');

	esvaziar(&inicio, &fim);
	getchar();
	return 0;
}