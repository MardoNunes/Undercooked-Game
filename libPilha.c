#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libPilha.h"
//Criação da minha pilha para montar os pedidos!

void initPilha(struct pilha *Pilha){
	Pilha = malloc(sizeof(struct pilha));
	if(Pilha == NULL)
		printf("Erro ao alocar!!\n");

	Pilha->tam = 0;
	Pilha->topo = NULL;
}

void push(struct pilha *Pilha, char ingrediente){
	
	struct pilha *novo = malloc(sizeof(struct pilha));
	novo->ingrediente = ingrediente;
	
	//toda vez que pegamos um ingrediente adicionamos na pilha
	//o maximo é 6, entao faco essa vereficação aqui
	if(Pilha->tam > MAX_INGRE)
		printf(" ");		//se for maior nao faz nada!
	
	if(Pilha->topo == NULL)
		novo->prox = NULL;
	else
		novo->prox = Pilha->topo;	//novo node aponta para o antigo topo
	
	Pilha->topo = novo;	//e o topo aponta para o novo nodo
				//Como o topo sempre aponta pro fim, coloquei ele para fazer essa operação sempre no final da função
	Pilha->tam = Pilha->tam + 1;

}

void pop(struct pilha *Pilha){
	
	struct pilha *aux = malloc(sizeof(struct pilha));
	Pilha->tam = 0;
	if(Pilha->topo == NULL){
		return;
	}
	
	//Aqui eu vou excluir toda a pilha 
	//ou seja excluir todo os ingredientes!
	while(Pilha->topo != NULL){
		aux = Pilha->topo;
		Pilha->topo = Pilha->topo->prox;
       		free(aux);
	}
	Pilha->tam = 0;
}

void imprimiPilha(struct pilha *Pilha){
	
	struct pilha *aux = malloc(sizeof(struct pilha));
	if(Pilha->topo == NULL)
		return;
	else{
		aux = Pilha->topo;
		printf("\n==================INGREDIENTE================\n");
		while(aux != NULL){
			printf("%-6c", aux->ingrediente);
			aux = aux->prox;
		}
		printf("\n");
		printf("=============================================\n");
		printf("\n");
	}
}

