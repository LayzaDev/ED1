#define tamPilha 10

typedef struct pilha Pilha;

Pilha *createPilha();
void destroyPilha(Pilha *p);
int isFullPilha(Pilha *p);
int isEmptyPilha(Pilha *p);
int pushPilha(Pilha *p, char c);
int popPilha(Pilha *p);
