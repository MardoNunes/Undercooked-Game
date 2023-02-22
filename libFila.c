#include <stdio.h>
#include <stdlib.h>
#include "libFila.h"


//Gera o numero do pedido aleatorioamente
int randomPedido(){
    int pedido = rand() % 6;
    return pedido;
}

void enqueue(struct listaDupla *Lista, int *id, int pedido,int tamIngrediente, char *ingrediente){
    struct noDuplo *novo = malloc(sizeof(struct noDuplo));
    novo->ingrediente = (char*)malloc(tamIngrediente*sizeof(char));
    novo->id = *id;
    novo->ingrediente = ingrediente;
    novo->pedido = pedido;
    novo->prox = NULL;
    novo->ant = NULL;
    *id = *id + 1;

    //Se a cabeça for nula, a cabeca e fim apoontam para o novo nodo!
    if(Lista->cabeca == NULL){
        Lista->cabeca = novo;
        Lista->fim = novo;
    }
    else{
        Lista->fim->prox = novo;    //ligo o meu ultimo nodo com o novo nodo(atual)
        novo->ant = Lista->fim;     //lig o atual com o ultimo nodo
        Lista->fim = novo;          //e ai aponto o final da lista para o novo final
    }
    Lista->tam = Lista->tam + 1;
}

void dequeue(struct listaDupla *Lista){ 

    if(Lista->cabeca == NULL)
        printf("Lista vazia!\n");
    else if(Lista->tam == 1){       //se a lista tem 1 nodo, apena coloco NULL em seus ponteiros
        Lista->cabeca = NULL;
        Lista->fim = NULL;
    }
    else{
        //se não, fço a jogada de ponteiros
        Lista->cabeca = Lista->cabeca->prox;    //aqui a cabeca aponta para o proximo nodo
        Lista->cabeca->ant = NULL;          //no proximo nodo, desligo o ponteiro anterior
    }

    Lista->tam = Lista->tam - 1;
    
}

void initLista(struct listaDupla *Lista){
    
    Lista = malloc(sizeof(struct listaDupla));
    if(Lista == NULL)
        printf("Erro ao alocar memoria!\n");
    else{
        Lista->cabeca = NULL;
        Lista->fim = NULL;
        Lista->tam = 0;
    }
}

void initNoDuplo(struct noDuplo *no){
    no = malloc(sizeof(struct noDuplo));
    if(no == NULL)
        printf("Erro ao alocar memoria!\n");
    else{
        no->prox = NULL;
        no->ant = NULL;
    }
}

void imprimiLista(struct listaDupla *Lista){

    struct noDuplo *aux = malloc(sizeof(struct noDuplo));
    aux = Lista->cabeca;


    printf("		||==============||\n");
    printf("		|| ID || INGR.  ||\n");
    printf("		||--------------||\n");
    while(aux != NULL){
        printf("		|| %-2d || %-6s ||\n", aux->id, aux->ingrediente);
        aux = aux->prox;
    }
    printf("		||==============||\n");
}

void adicionaPedido(struct listaDupla *Lista, int *id){
    
    for(int cont = 0; cont < 5; cont ++){
        switch(randomPedido()){
            case 0:
                enqueue(Lista, id, 0, 4, "pHQP");  //x-burguer
                break;
            case 1:
                enqueue(Lista, id, 1, 4, "pHSP");  //x-salada
                break;
            case 2:
                enqueue(Lista, id, 2, 6, "pHQPFR");    //combo-1
                break;
            case 3:
                enqueue(Lista, id, 3, 6, "pHSPFR"); //combo-2
                break;
            case 4:
                enqueue(Lista, id, 4, 5, "pQPFR"); //Vegetariano
                break;
            case 5:
                enqueue(Lista, id, 5, 3, "SFR");   //vegano
                break;
            default:
                printf("Erro ao gerar pedido!\n");
                break;
            }
    }
    imprimiLista(Lista);
}
