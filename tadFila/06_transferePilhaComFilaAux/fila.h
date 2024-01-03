#define tamFila 10

typedef struct fila Fila;

Fila *createFila();
void destroyFila(Fila *p);
int isFullFila(Fila *p);
int isEmptyFila(Fila *p);
int pushFila(Fila *p, int c);
int popFila(Fila *p);
int inverteOrdemFila(Fila *f, Pilha *p);