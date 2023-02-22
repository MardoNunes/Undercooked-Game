struct noDuplo{
	int id;
	int pedido;
	char *ingrediente;
	struct noDuplo *prox;
	struct noDuplo *ant;
};


struct listaDupla{
	int tam;
	struct noDuplo*fim;
	struct noDuplo *cabeca;
};




int randomPedido();

void enqueue(struct listaDupla *Lista, int *id, int pedido, int tamIngrediente, char *ingrediente);

void dequeue(struct listaDupla *Lista);

void initLista(struct listaDupla *Lista);

void initNoDuplo(struct noDuplo *novo);

void imprimiLista(struct listaDupla *Lista);

void adicionaPedido(struct listaDupla *Lista, int *id);

