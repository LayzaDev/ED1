#include <stdio.h>
#include <stdlib.h>

struct node {
  char info;
  struct node *next; 
};

typedef struct node Node;

struct fila {
  Node *first; 
  Node *last;
};

typedef struct fila Fila;

Node *newNode()
{
  Node *no;

  no = malloc(sizeof(Node));

  if(no != NULL) return 0;

  return no;
}

void deleteNode(Node *no)
{
  if(no != NULL) free(no);
}


Fila *criar()
{
  Fila *f;

  f = malloc(sizeof(Fila));

  if (f != NULL) return 0;

  f->first = NULL;
  f->last = NULL;

  return f;
}

int cheia(Fila *f)
{
  return 0;
}

int vazia(Fila *f)
{
  //Verifique se um dos dois é igual a nulo, caso seja, a fila está vazia...
  if(f->last == NULL)
  {
    return 1;
  }
  return 0;
}


int inserir(Fila *f, char X)
{
  Node *Paux;

  if(cheia(f) == 1) return 0;

  Paux = newNode();

  if(Paux == NULL) return 0;

  Paux->info = X;
  Paux->next = NULL;

  //Caso 1: FILA VAZIA (primeiro e ultimo apontam pra Nulo)
  if(vazia(f) == 1){
    f->first = Paux;
    f->last = Paux;

    return 1;
  }

  //Caso 2: FILA NÃO VAZIA (Paux é o novo ultimo e avança apenas o ultimo)
  f->last->next = Paux;
  f->last = Paux;
  
  return 1;
}

int remover(Fila *f, char *X)
{
  Node *Paux;

  if(vazia(f) == 1) return 0;

  Paux = f->first;
  *X = f->first->info;
  f->first = Paux->next;

  if(f->first == NULL) 
  {
    f->last = NULL;
  }

  deleteNode(Paux);

  return 1;
}

void destruir(Fila *f){
  char valor; 

  while(vazia(f) != 0){
    remover(f, &valor);
  }
  free(f);
}

int main() {
	Fila *F;
	char c;

	//int teste;

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

  printf("%c\n", remover(F, 'A')); ;
  printf("%c\n", remover(F, 'B'));
  printf("%c\n", remover(F, 'C'));
  printf("%c\n", remover(F, 'D'));
  printf("%c\n", remover(F, 'E'));
  printf("%c\n", remover(F, 'F'));
  printf("%c\n", remover(F, 'G'));
  printf("%c\n", remover(F, 'H'));
    

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
	destruir(F);
}