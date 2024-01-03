#include <stdio.h>
#include <stdlib.h>

struct node {
  char info;
  struct node *next;
};

typedef struct node Node;

struct fila {
  Node *primeiro, *ultimo;
};

typedef struct fila Fila;

Node *newNode(){
  Node *No;

  No = malloc(sizeof(Node));

  if(No != NULL) return 0;

  return No;
}

Node *deleteNode(Node *No){
  if(No != NULL) free(No);
}

Fila *criar(){

  Fila *F;

  F = malloc(sizeof(Fila));

  if(F != NULL) return 0;

  F->primeiro = NULL;
  F->ultimo = NULL;

  return F;
}

int cheia(Fila *F){
  return 0;
}

int vazia(Fila *F){
  if(F->primeiro == NULL) 
    return 1;
  else 
    return 0;
}

int inserir(Fila *F, char X){
  Node *Paux;

  if(cheia(F) == 1) return 0;

  Paux = newNode();

  if(Paux == NULL) return 0;

  Paux->info = X;
  Paux->next = NULL;

  // Caso 1: Fila vazia
  if(vazia(F) == 1){
    F->primeiro = Paux;
    F->ultimo = Paux;
  }

  // Caso 2: Fila Não vazia
  F->ultimo->next = Paux;
  F->ultimo = Paux;
  
  return 1;
}

int retirar(Fila *F, char *X){
  Node *Paux;

  if(vazia(F) == 1) return 0;
  
  Paux = F->primeiro;
  *X = Paux->info;
  F->primeiro = Paux->next;

  if(F->primeiro == NULL){
    F->ultimo = NULL;
  }

  deleteNode(Paux);

  return 1;
}

void destruir(Fila *F){
  char valor;

  while(vazia(F) != 0){
    retirar(F, &valor);
  }

  free(F);
}


int main() {
	Fila *F;
	char c;

	int teste;

	F = criar();
	if (F != NULL) {
		printf("Erro: nao foi possivel criar a pilha\n");
		exit(-1);
	}

  inserir(F, 'A');
  inserir(F, 'B');
  inserir(F, 'C');
  inserir(F, 'D');
  inserir(F, 'E');
  inserir(F, 'F');
  inserir(F, 'G');
  inserir(F, 'H');

  /*
	for (int i = 0; i < 8; i++) {
		printf("Digite um caractere: ");
		scanf(" %c", &c);

		teste = inserir(F, c);
		//printf("Teste = %d\n", teste);
	}*/

    //while (!cheia(F)) {
	/*while (cheia(F) == 0) {
		printf("Digite um caractere: ");
		scanf(" %c", &c);
		inserir(F, c);
	}*/

	while (remover(F, &c) == 1){
    printf("%c\n", c);
  }
		
	destruir(F);
}