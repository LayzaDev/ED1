// declaração do topo da pilha
#define tamPilha 5
typedef struct pilha pilha_t;

pilha_t *create();
void destroy(pilha_t *p);
int isEmpty(pilha_t *p);
int push(pilha_t *p, char x);
int pop(pilha_t *p, char *x);