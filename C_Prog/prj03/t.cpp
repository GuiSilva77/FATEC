#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct lista{
    int ra;
    lista *prox;
};

lista *NovoElemento(){
    lista *novo;

    novo = (lista*)malloc(sizeof(lista));

    if(novo == NULL){
        printf("MemÃ³ria Insuficiente!");
    }
    else{
        printf("Digite um RA diferente dos anteriores ");
        scanf("%d", &novo->ra);
    }
    return novo;
}
/*
void deletarFim(lista *inicio){
  lista *aux;

  aux = inicio;

  while(aux->prox != NULL){
    inicio = aux;
    aux = aux->prox;
  }
  inicio->prox = NULL;
  free(aux);
}
*/
/*
void deletarFim(lista *ini)
{
    lista *aux = ini;

    while(aux->prox->prox != NULL)
        aux = aux->prox;

    lista *aux2 = aux->prox;
    free(aux2);
    aux->prox = NULL;
}
*/
void deletarFim(lista *ini)
{
    while (ini->prox->prox != NULL)
        ini = ini->prox;

    lista *aux = ini->prox;
    free(aux);
    ini->prox = NULL;
}




void deletarIndex(lista *inicio){
  int index;
  lista *aux;

  aux = inicio;
  printf("Informe o RA que deseja deletar");
  scanf("%d", &index);

    while(aux->prox != NULL){
      if(aux->ra == index){
        break;
    }
      else
        inicio = aux;
        aux = aux->prox;
    }
    inicio->prox = aux->prox;
    free(aux);
}

void inserirDepois(lista *inicio){
    int index;
    lista *novo;

    printf("Depois de qual RA voce deseja inserir ?");
    scanf("%d", &index);
    novo = NovoElemento();
    novo->prox = NULL;

    while(inicio->prox != NULL){
        if(inicio->ra == index){
          break;
        }
        else
          inicio = inicio->prox;
    }

    novo->prox = inicio->prox;
    inicio->prox = novo;

}


void inserirInicio(lista **inicio, lista **fim){
    lista *novo;

    novo = NovoElemento();
    if(novo == NULL){
        printf("memoria insuficiente");
    }
    else{
        novo->prox = NULL;
        if(*inicio == NULL){
            *inicio = novo;
            *fim = novo;
        }
        else{
            novo->prox = *inicio;
            *inicio = novo;
        }
    }
}

void inserirFim(lista **inicio, lista **fim){
    lista *novo;

    novo = NovoElemento();
    if(novo == NULL){
        printf("memoria Insuficiente");
    }
    else{
        novo->prox = NULL;
        if(*inicio == NULL){
            *inicio = novo;
            *fim = novo;
        }
        else{
            (*fim)->prox = novo;
            *fim = novo;
        }
    }
}

void listar(lista *Inicio){
    if(Inicio == NULL){
        printf("lista vazia!");
    }
    else{
        while(Inicio != NULL){
            printf("%d ", Inicio->ra);
            Inicio = Inicio->prox;
        }
    }
}

void deletarInicio(lista **Inicio){
    lista *aux;

    if(*Inicio == NULL){
        printf("Lista vazia!");
    }
    else{
    aux  = (*Inicio)->prox;
    free(*Inicio);
    *Inicio = aux;
    }
}

void Limpar(lista **Inicio){
    lista *aux;

    if(*Inicio == NULL){
        printf("Lista vazia!");
    }
    else{
        while(*Inicio != NULL){
            aux = (*Inicio)->prox;
            free(*Inicio);
            *Inicio = aux;
        }
    }
}

int main(){
    char op;
    lista *Inicio = NULL, *fim;



    do{
        printf("\n1 - Inserir no Inicio \n2 - Inserir no Fim \n3 - Inserir Depois \n4 - Listar \n5 - Deletar do Inicio \n6 - Deletar Indice \n7 - Deletar Ultimo \n8 - Limpar \n9 - Sair\n");
        op = getchar();
        switch(op){
            case '1':
                    inserirInicio(&Inicio, &fim);
                    break;
            case '2':
                    inserirFim(&Inicio, &fim);
                    break;
            case '3':
                    inserirDepois(Inicio);
                    break;
            case '4':
                    listar(Inicio);
                    break;
            case '5':
                    deletarInicio(&Inicio);
                    break;
            case '6':
                    deletarIndex(Inicio);
                    break;
            case '7':
                    deletarFim(Inicio);
                    break;
            case '8':
                    Limpar(&Inicio);
                    break;
            case '9':
                    Limpar(&Inicio);
                    break;
            default:
                printf("\nOpcao invalida");
                break;
        }
        fflush(stdin);
    }while(op != '9');



    getchar();
    return 0;

}
