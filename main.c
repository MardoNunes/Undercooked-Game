#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include "libFila.h"
#include "libPilha.h"
#define Y 33

#define COLOR_RED	"\x1b[31m"
#define COLOR_RESET	"\x1b[0m"
#define COLOR_YELLOW	"\x1b[33m"



//Iprimi o nome do jogo
void title(){
printf(COLOR_RED "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" COLOR_RESET "\n\n");
printf(COLOR_RED "			##  ## ###    ## ####   ###### ######     #####   #####    ####   ## ##  ##### ####" COLOR_RESET "\n");
printf(COLOR_RED "			##  ## ## ##  ## ## ##  ##     ##  ##   ###     ##    ## ##    ## ####   ##    ## ##" COLOR_RESET"\n");
printf(COLOR_RED "			##  ## ##  ## ## ##  ## #####  ######   ###      #     #  #    #  ###    ##### ##  ##" COLOR_RESET"\n");
printf(COLOR_RED "			##  ## ##   #### ##  ## ##     ##   ##  ###     ##    ## ##    ## ## ##  ##    ##  ##" COLOR_RESET"\n");
printf(COLOR_RED "			###### ##    ### ## ##  #####  ##    ##   #####   #####    ####   ## ### ##### ## ##" COLOR_RESET"\n\n");
printf(COLOR_RED "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" COLOR_RESET "\n\n");

}

void printGamerOver(){
  system("clear");
  printf("   _____          __  __ ______    ______      ________ _____\n");
  printf("  / ____|   /\\   |  \\/  |  ____|  / __ \\ \\    / /  ____|  __ \\ \n");
  printf(" | |  __   /  \\  | \\  / | |__    | |  | \\ \\  / /| |__  | |__) |\n");
  printf(" | | |_ | / /\\ \\ | |\\/| |  __|   | |  | |\\ \\/ / |  __| |  _  /\n");
  printf(" | |__| |/ ____ \\| |  | | |____  | |__| | \\  /  | |____| | \\ \\ \n");
  printf("  \\_____/_/    \\_\\_|  |_|______|  \\____/   \\/   |______|_|  \\_\\\n");
  printf("\n\nVocê atingiu a cota máxima de fails ou de lixo!!\n\n");
}

void printWin(){
printf("##      ##   ######    ##     ##  	 	##         ##    #  ###      ##\n");
printf("  ##  ##    #      #   ##     ##  	 	##         ##   ##  ## ##    ##\n");
printf("    ##     #        #  ##     ##   		##   ###   ##   ##  ##  ##   ##\n");
printf("    ##     #        #  ##     ##   		##  ## ##  ##   ##  ##   ##  ##\n");
printf("    ##      #      #   ##     ##   		## ##   ## ##   ##  ##    ## ##\n");
printf("    ##       ######    #########   		####     ####   ##  ##     ####\n");
printf("\n\nParabéns, você ganhou o jogo!!\n\n");
}


//Esse sera o placar do jogo
void placar(struct listaDupla *Lista, struct pilha *Pilha, int *fails, int *pontos, int *lixo){
    imprimiLista(Lista);
    imprimiPilha(Pilha);
    printf(COLOR_YELLOW "                      			Pontos: %d" COLOR_RESET, *pontos);
    printf(COLOR_YELLOW "                      Fails: %d" COLOR_RESET, *fails);
    printf(COLOR_YELLOW "                      Lixo: %d" COLOR_RESET "\n", *lixo);
}

//Esse procedimento irá imprimi o mapa
void printMapa(struct listaDupla *Lista, struct pilha *Pilha, char mapa[6][Y], int *fails, int *pontos, int *lixo){
    
    system("clear");    //system("clear") limpa a tela a toda chamada de print!
    title();
     for( int i = 0; i < 6; i++){
        printf("                               			%s\n", mapa[i]);
    }
    printf("\n");
    placar(Lista, Pilha, fails, pontos, lixo);
    printf("\n");
}

//compara cada elemento da pilha com o elemento da fila
int compara(struct listaDupla *Lista, struct pilha *Pilha, char *ingrediente, int tam){
	int i = tam - 1;
	int ok = 0;
	struct pilha *aux = malloc(sizeof(struct pilha));
	
	while( Pilha->topo != NULL && ok != 1 ){
		
		aux = Pilha->topo;
		if(ingrediente[i] != aux->ingrediente)
			ok = 1 ;
		Pilha->topo = Pilha->topo->prox;
		i--;
	}
	free(aux);
	return ok;
}

//verefica se a pilha atual esta de acordo com o pedido da fila
int verefica(struct listaDupla *Lista, struct pilha *Pilha){
	char *ingrediente;
	struct noDuplo *aux;
	aux = Lista->cabeca;

	switch(aux->pedido){
		case 0:
			ingrediente = "pHQP";
			return compara(Lista, Pilha, ingrediente, 4);
			break;
		case 1: 
			ingrediente = "pHSP";
			return compara(Lista, Pilha, ingrediente, 4);
			break;
		case 2:
			ingrediente = "pHQPFR";
			return compara(Lista, Pilha, ingrediente, 6);
			break;
		case 3:
			ingrediente = "pHSPFR";
			return compara(Lista, Pilha, ingrediente, 6);
			break;
		case 4:
			ingrediente = "pQPFR";
			return compara(Lista, Pilha, ingrediente, 5);
			break;
		case 5:
			ingrediente = "SFR";
			return compara(Lista, Pilha, ingrediente, 3);
			break;
		default:
			break;
	}
}

//função que verefica se a pilha está vazia
int pilhaVazia(struct pilha *Pilha){
	if(Pilha->tam == 0)
		return 0;
	return 1;
}



//Essa função irá retornar o valor da coluna do jogador no mapa
int posicaoJogadorCol(char mapa[6][Y]){
    int jogador;
    for( int i = 0; i < 6; i++){
        for( int j = 0; j < Y; j++){
            if(mapa[i][j] == '&'){
                jogador = j;
            }
        }
    }
    return jogador;
}
//Essa função irá retornar o valor da linha do jogador no mapa
int posicaoJogadorLin(char mapa[6][Y]){
    int jogador;
    for( int i = 0; i < 6; i++){
        for( int j = 0; j < Y; j++){
            if(mapa[i][j] == '&'){
                jogador = i;
            }
        }
    }

    return jogador;
}

//Essa função move o jodagor para a direita
//passo fail e pontos para printar o placar toda vez que se printa o mapa
void moveDireita(struct pilha *Pilha, struct listaDupla *Lista, char mapa[6][Y], int *fails, int *pontos, int *lixo){
    int col = posicaoJogadorCol(mapa);
    int lin = posicaoJogadorLin(mapa);
    char ingrediente;
    if(mapa[lin][col+1] == ' '){
        mapa[lin][col] = ' ';
        mapa[lin][col+1] = '&';
        printMapa(Lista, Pilha, mapa, fails, pontos, lixo);
    }
    else if(mapa[lin][col+1] == 'o' || mapa[lin][col+1] == 'F' || mapa[lin][col+1] == 'R' || mapa[lin][col+1] == 'p' || mapa[lin][col+1] == 'H' || mapa[lin][col+1] == 'Q' || mapa[lin][col+1] == 'S' || mapa[lin][col+1] == 'P'){
        if(mapa[lin][col+1] == 'o'){
		if(pilhaVazia(Pilha) == 1){
			pop(Pilha);
			*lixo = *lixo + 1;
		}
	}
    }
}


//Essa função move o jodagor para a esquerda
void moveEsquerda(struct pilha *Pilha, struct listaDupla *Lista, char mapa[6][Y], int *fails, int *pontos, int *lixo){
    int col = posicaoJogadorCol(mapa);
    int lin = posicaoJogadorLin(mapa);
    if(mapa[lin][col-1] == ' '){
        mapa[lin][col] = ' ';
        mapa[lin][col-1] = '&';
        printMapa(Lista, Pilha, mapa, fails, pontos, lixo);
    }
    else if(mapa[lin][col-1] == 'F' || mapa[lin][col-1] == 'R' || mapa[lin][col-1] == 'p' || mapa[lin][col-1] == 'H' || mapa[lin][col-1] == 'Q' || mapa[lin][col-1] == 'S' || mapa[lin][col-1] == 'P'){
        
	char ingrediente = mapa[lin][col-1];
	push(Pilha, ingrediente);
    }
}

//Essa função move o jodagor para cima
void moveCima(struct pilha *Pilha, struct listaDupla *Lista, char mapa[6][Y], int *fails, int *pontos, int *lixo){
    int col = posicaoJogadorCol(mapa);
    int lin = posicaoJogadorLin(mapa);
    if(mapa[lin-1][col] == ' '){
        mapa[lin][col] = ' ';
        mapa[lin-1][col] = '&';
        printMapa(Lista, Pilha, mapa, fails, pontos, lixo);
    }
    else if(mapa[lin-1][col] == 'R' || mapa[lin-1][col] == 'F' || mapa[lin-1][col] == '@' || mapa[lin-1][col] == 'p' || mapa[lin-1][col] == 'H' || mapa[lin-1][col] == 'Q' || mapa[lin-1][col] == 'S' || mapa[lin-1][col] == 'P'){
        
	if(mapa[lin-1][col] == 'o'){
		if(pilhaVazia(Pilha) == 1){
			pop(Pilha);
			*lixo = *lixo + 1;
		}
	}
	else if(mapa[lin-1][col] != '@'){
		char ingrediente = mapa[lin-1][col];
		push(Pilha, ingrediente);
	}
	else if(pilhaVazia(Pilha) == 1){
			if(verefica(Lista, Pilha) == 1)
				*fails = *fails + 1;
			else
				*pontos = *pontos + 1;
		
			dequeue(Lista);
			pop(Pilha);
		}
		
	}
}
//Essa função move o jodagor para baixo
void moveBaixo(struct pilha *Pilha, struct listaDupla *Lista, char mapa[6][Y], int *fails, int *pontos, int *lixo){
    int col = posicaoJogadorCol(mapa);
    int lin = posicaoJogadorLin(mapa);
    char ingrediente;
    if(mapa[lin+1][col] == ' '){
        mapa[lin][col] = ' ';
        mapa[lin+1][col] = '&';
        printMapa(Lista, Pilha, mapa, fails ,pontos, lixo);
    }
    else if(mapa[lin+1][col] == 'Q' || mapa[lin+1][col] == 'p' || mapa[lin+1][col] == 'H' || mapa[lin+1][col] == 'S' || mapa[lin+1][col] == 'P' ){
        if(mapa[lin+1][col] == 'o'){
		if(pilhaVazia(Pilha) == 1){
			pop(Pilha);
			*lixo = *lixo + 1;
		}
	}
	else{
		ingrediente = mapa[lin+1][col];
		push(Pilha, ingrediente);
	}
    }
}


//Essa função consegue obter o caracter do usario sem aprecisar apertar enter
int getch(void){
    int ch;
    struct termios t_old, t_new;

    //tcgetattr obtém os parâmetros do terminal atual
    //STDIN_FILENO dirá ao tcgetattr que ele deve gravar as configurações
    //de stdin para t_old
    tcgetattr(STDIN_FILENO, &t_old);
    
    //agora a configuação de t_old é copiada para t_new
    t_new = t_old;
    
    //ICANON normalmente cuida para que uma linha por vez seja processada
    //isso significa que ele retornará se vir um "\n" ou um EOF ou um EOL
    t_new.c_lflag &= ~(ICANON | ECHO);

    //esta linha faz com que o getch não espere por um "\n" ou EOF ou EOL
    tcsetattr(STDIN_FILENO, TCSANOW, &t_new);

    //aqui ch recebe o caracter digitado
    ch = getchar();

    //aqui as configurações de t_old são restauradas
    tcsetattr(STDIN_FILENO, TCSANOW, &t_old);
    
    
    return ch;
}

void vereficaLista(struct listaDupla *Lista, int *id){
	if(Lista->tam < 1){
		adicionaPedido(Lista, id);
	}
}

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
    int okFail = 0;
    int okPontos = 0;
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
    do{
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
	    if(fails > 3 || lixo > 5)
		    okFail = 1;
        if(pontos == 5)
            okPontos = 1;
    }while(okFail != 1 || okPontos != 1);

    if(fails > 3 || lixo > 5)
	    printGamerOver();
    else
        printWin();
	    
   return 0;

}

