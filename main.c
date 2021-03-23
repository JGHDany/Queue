#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//Definição da Estrutura de Dados:

typedef int telem;
typedef struct no {
	telem dado;
	struct no* prox;
} tno;

typedef struct fila {
	tno* inicio;
	tno* final;
} tfila;


//Operações:
//1. Criar - cria uma fila vazia
void criar (tfila *F);

//2. Vazia - testa se uma fila está vazia
int vazia (tfila F);

//3. Primeiro - obtém o elemento do início de uma fila
int primeiro (tfila F, telem *elem);

//4. Inserir - insere um elemento no fim de uma fila
int inserir (tfila *F, telem valor);

//5. Remover - remove o elemento do início de uma fila, retornando o elemento removido
int remover (tfila *F, telem *valor);

//7. Esvaziar - remove todos os elementos da fila.
int esvaziarFila(tfila *F);

//8. ImprimirFila - imprime todos os elementos da fila.
void imprimirFila(tfila F);

int main()
{
	tfila f;
	telem valor;
	criar(&f);

	int opcao;

   do{

		printf("\n\n\n\t EDITOR DE FILA ENCADEADA\n");
		printf("\n\t 1 - INSERIR   				   ");
		printf("\n\t 2 - REMOVER   				   ");
		printf("\n\t 3 - EXIBIR PRIMEIRO ELEMENTO  ");
		printf("\n\t 4 - EXIBIR A FILA    		   ");
		printf("\n\t 5 - ESVAZIAR A FILA   		   ");
		printf("\n\t 6 - SAIR           		   ");

		printf("\n\n\t  DIGITE SUA OPÇÃO: ");
		scanf("%d",&opcao);
		system("CLS");
		switch(opcao){

			case 1: {
				printf("\n\t EMFILA um elemento:");
				scanf("%d",&valor);
				if(inserir(&f, valor)>0){
					printf("\n\tOK <- inserir (&fila, %d)",valor);
				}
			}break;

			case 2: {
				telem valor;
				if(remover(&f, &valor)>0)
					printf("\n\tOK <- remover(&fila, %d)", valor);

			}break;

			case 3:{
				telem dado;
				if(primeiro (f, &dado)>0)
					printf("\n\t OK <- O primeiro(fila, => [%d])", dado);
			}break;
			case 4:{
					if(!vazia(f)){
						printf("\n\tFILA :");
						imprimirFila(f);
					}else	printf("\n\tFila Vazia!");
			}break;
			case 5:{
				if(esvaziarFila(&f)>0){
					printf("\n\t OK <- Fila Esvaziada!");
					free(&f);
				}
			}break;
			default : printf("\n\tOPS! Este caso ainda nao esta tratado!");
		}
	}while(opcao!=6);

    return 0;
}

//Operações:
//1. Criar - cria uma fila vazia
void criar (tfila *F)
{
	F->inicio = F->final = NULL;
}

//2. Vazia - testa se uma fila está vazia
int vazia (tfila F)
{
	return (F.inicio == NULL && F.final == NULL);
}

//3. Primeiro - obtém o elemento do início de uma fila
int primeiro (tfila F, telem *elem)
{
	if (vazia(F)) { // Erro: fila vazia
		printf("\n\tprimeiro: Fila Vazia");
		return 0;
	}
	*elem = (F.inicio)->dado;
	return 1;
}

//4. Inserir - insere um elemento no fim de uma fila
int inserir (tfila *F, telem valor)
{
	tno *novo;
	novo = (tno*) malloc(sizeof(tno));
	if (novo == NULL) return 0; /* Erro: mem¢ria insuficiente */
	novo->dado = valor;
	novo->prox = NULL;
	if (vazia(*F))
		F->inicio = novo;
	else
		(F->final)->prox = novo;
	F->final = novo;
	return 1;
}

//5. Remover - remove o elemento do início de uma fila, retornando o elemento removido
int remover (tfila *F, telem *valor)
{
	tno *aux;
	if (vazia(*F)){ // Erro: fila vazia
		printf("\n\tRemocao: Fila Vazia");
		return 0;
	}

	primeiro(*F,valor);
	if(F->inicio == F->final)
		F->final = NULL;
	aux = F->inicio;
	F->inicio = (F->inicio)->prox;
	free(aux);
	return 1;
}

//7. Esvaziar - remove todos os elementos da fila.
int esvaziarFila(tfila *F){

	if(vazia(*F)) { // Erro: fila vazia
		printf("\n\tesvaziarFila: Fila Vazia");
		return 0;
	}
	tfila *faux;
	faux->final = F->final;
	faux->inicio = F->inicio;

	F->inicio = NULL;
	F->final = NULL;
	free(faux);
	free(F);

	return 1;
}

//8. ImprimirFila - imprime todos os elementos da fila sem alterar a fila
void imprimirFila(tfila F){

	if (vazia(F)){ // Erro: fila vazia
		printf("\n\timprimirFila: Fila Vazia");
		return ;
	}
	else{
		printf(" %d",(F.inicio)->dado);
		F.inicio = (F.inicio)->prox;
		if(F.inicio != NULL)
			printf(" <- ");

		if(F.inicio == NULL) return;
		imprimirFila(F); //lista os restantes elementos
	}
}
