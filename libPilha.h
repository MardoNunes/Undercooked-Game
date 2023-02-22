#define MAX_INGRE 6

struct pilha{
	int tam;
	char ingrediente;
	struct pilha *prox;
	struct pilha *topo;
};



void initPilha(struct pilha *Pilha);

void push(struct pilha *Pilha, char ingrediente);

void pop(struct pilha *Pilha);

void imprimiPilha(struct pilha *Pilha);
