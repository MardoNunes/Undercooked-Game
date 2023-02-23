#define Y 33


void title();
void printGamerOver();
void printWin();
void placar(struct listaDupla *Lista, struct pilha *Pilha, int *fails, int *pontos, int *lixo);
void printMapa(struct listaDupla *Lista, struct pilha *Pilha, char mapa[6][Y], int *fails, int *pontos, int *lixo);
int compara(struct listaDupla *Lista, struct pilha *Pilha, char *ingrediente, int tam);
int verefica(struct listaDupla *Lista, struct pilha *Pilha);
int pilhaVazia(struct pilha *Pilha);
int posicaoJogadorCol(char mapa[6][Y]);
int posicaoJogadorLin(char mapa[6][Y]);void moveDireita(struct pilha *Pilha, struct listaDupla *Lista, char mapa[6][Y], int *fails, int *pontos, int *lixo);
void moveEsquerda(struct pilha *Pilha, struct listaDupla *Lista, char mapa[6][Y], int *fails, int *pontos, int *lixo);
void moveCima(struct pilha *Pilha, struct listaDupla *Lista, char mapa[6][Y], int *fails, int *pontos, int *lixo);
void moveBaixo(struct pilha *Pilha, struct listaDupla *Lista, char mapa[6][Y], int *fails, int *pontos, int *lixo);
int getch(void);
void vereficaLista(struct listaDupla *Lista, int *id);