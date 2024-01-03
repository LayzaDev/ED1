#include <stdio.h>
#include <stdlib.h>

// Declarando a estrutura Node da lista encadeada simples
struct node 
{
  char info;
  struct node *Next;
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

// Função para empilhar elementos na Lista
int empilhar(Pilha *P, char X)
{
  Node *Paux;

  if(isFull(P) == 1) return 0;

  Paux = newNode();

  if(Paux == NULL) return 0;

  Paux->info = X;
  Paux->Next = P->topo;
  P->topo = Paux;

  return 1;
}


// Função para desempilhar os elementos da Lista
int desempilhar(Pilha *P, char *X)
{
  Node *Paux;

  if(isEmpty(P) == 1) return 0;

  // Forma 1:
  // *X = P->topo->info;
  // P->topo = P->topo->Next;

  // Forma 2:
  Paux = P->topo;
  *X = Paux->info;
  P->topo = Paux->Next;

  deleteNode(Paux);

  return 1;
}

// Função para liberar espaço na lista
void destroy(Pilha *P){

  char valor;

  while(isEmpty(P) != 0){
    desempilhar(P, &valor);
  }

  free(P);
}

int main(){

  Pilha *P;
  char valor;

  P = createPilha();

  if(P == NULL){
    printf("ERRO AO CRIAR PILHA \n");
    exit(1);
  }

  empilhar(P, 'A');
  empilhar(P, 'B');
  empilhar(P, 'C');
  empilhar(P, 'D');

  while(isEmpty(P) == 0){
    desempilhar(P, &valor);
    printf("%c ", valor);
  }

  printf("\n");

  destroy(P);

  return 0;
}