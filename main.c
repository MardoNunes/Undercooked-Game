#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include "libFila.h"
#include "libPilha.h"
#include "libBurguer.h"
#define Y 33





int main(){
    struct listaDupla *Lista = malloc(sizeof(struct listaDupla));
    if(Lista == NULL)
	    printf("Erro ao alocar memory!\n");
    else{
    	Lista->tam = 0;
    	Lista->cabeca = NULL;
    	Lista->fim = NULL;
	}
   
    struct pilha *Pilha = malloc(sizeof(struct pilha));
    if(Pilha == NULL)
	    printf("Erro ao alocar memory\n");
    else{
    	Pilha->tam = 0;
   	 Pilha->topo = NULL;
    	Pilha->prox = NULL;
    }
   
    char input;
    int fails = 0;
    int pontos = 0;
    int lixo = 0;
    int id = 1;
    //o mapa é uma matriz de string!
    char mapa[6][Y] = {{"#---------------|@|------------#"},
                       {"|  [ F ] [ R ]                 |"},
                       {"|                             o|"},
                       {"|             &                |"},
                       {"| [ p ] [ H ] [ Q ] [ S ] [ P ]|"},
                       {"#------------------------------#"}};

   
    //essa função gera 5 pedidos toda vez
    adicionaPedido(Lista, &id);
    printMapa(Lista, Pilha, mapa, &fails, &pontos, &lixo);
    while(pontos < 10 && fails < 3 && lixo < 5){
        input = getch();
        vereficaLista(Lista, &id);       
        switch (input){
        case 'd':
            moveDireita(Pilha, Lista, mapa, &fails, &pontos, &lixo);
            break;
        case 'a':
            moveEsquerda(Pilha, Lista, mapa, &fails, &pontos, &lixo);
            break;
        case 'w':
            moveCima(Pilha, Lista, mapa, &fails, &pontos, &lixo);
            break;
        case 's':
            moveBaixo(Pilha, Lista, mapa, &fails, &pontos, &lixo);
            break;
        default:
            break;
        }
    }

    if(pontos > 9)
        printWin();
    else
        printGamerOver();
   return 0;

}

