//Implemente as operações Retira, Cria, Vazia e Cheia para uma fila com vetor circular

#define MAX 10

typedef struct fila fila_t;

fila_t *cria();
int insere(fila_t *f, int x);
int retira(fila_t *f);
int isEmpty(fila_t *f);
int isFull(fila_t *f);
int concatenaFilas(fila_t *f1, fila_t *f2);