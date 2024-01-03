#define tamPilha 100

typedef struct pilha Pilha;

Pilha *criar();
void destruir(Pilha *p);
int vazia(Pilha *p);
int cheia(Pilha *p);
int inserirX(Pilha *p, char x);
int inserirY(Pilha *p, char y);
int removerX(Pilha *p, char *x);
int removerY(Pilha *p, char *y);