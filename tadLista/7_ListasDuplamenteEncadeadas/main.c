#include <stdio.h>
#include <stdlib.h>

// Declarando a estrutura Node da lista encadeada simples
struct node 
{
  char info;
  struct node *esq, *dir;
};

// Definição do tipo Node
typedef struct node Node;

// Declaração da estrutura Pilha
struct pilha
{
  Node *topo;
};

// Definção do tipo Lista (usando Pilha)
typedef struct pilha Pilha;

// Criação de um novo Nó
Node *newNode()
{
  Node *No;

  //Se não puder alocar, retorna NULL
  No = malloc(sizeof(Node));

  return No;
}

// Deletar Nó da lista
void deleteNode(Node *No)
{
  if(No != NULL) free(No);
}

// Criação da Lista usando Pilha
Pilha *createPilha()
{
  Pilha *P;

  P = malloc(sizeof(Pilha));

  if(P != NULL) {
    P->topo == NULL;
  }

  return P;
}

// Verificação de lista vazia
int isEmpty(Pilha *P)
{
  if(P->topo == NULL) return 1 ;
  else return 0;
}

// Verificação de lista cheia
// Considerando que ela nunca estará cheia..
int isFull(Pilha *P)
{ 
  return 0;
}

int empilha(Pilha *P, char X){

  Node *Paux;

  if(cheia(P) == 1) return 0;

  Paux = newNode();
  if(Paux == NULL) return 0;

  if(vazia(P) == 1){
    // CASO 1: PILHA VAZIA
    Paux->info = X;
    Paux->esq = Paux;
    Paux->dir = Paux;
    P->topo = Paux;
  }
  //CASO 2: PILHA NÃO VAZIA
  Paux->dir = P->topo;
  Paux->esq = P->topo->esq;
  P->topo->esq->dir = Paux;
  P->topo->esq = Paux;
  P->topo = Paux;
  Paux = NULL;
}