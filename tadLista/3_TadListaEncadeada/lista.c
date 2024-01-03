#include<stdlib.h>
#include<stdio.h>

// declaracao do no(node) da lista encadeada simples
struct node {
  char info;
  struct node *next;
};

// definicao do tipo Node
typedef struct node Node;

// declaracao do nó cabeça
struct lista {
  Node *head;
};

// definicao do tipo Lista
typedef struct lista Lista;

Node *newNode()
{
  Node *n;

  // Se nao puder alocar, retorna NULL
  n = malloc(sizeof(Node));

  return n;
}

void deleteNode(Node *n)
{
  if (n != NULL) free(n);
}

Lista *criar()
{
  Lista *L;

  L = malloc(sizeof(Lista));
  if (L != NULL) L->head = NULL; // pilha vazia
  
  return L;
}

// Nessa versao, assume-se que nunca estara cheia
// Poderiamos limitar a quantidade de elementos...
int cheia(Lista *L)
{
  return 0;
}

int vazia(Lista *L)
{
  if (L->head == NULL) 
    return 1;
  else 
    return 0;
}

// Insere um elemento na lista por enquanto seguindo o algoritmo da Pilha
// Retorna TRUE se deu certo, FALSE caso contrario
int empilhar(Lista *L, char X)
{
  Node *Paux;
  
  if (cheia(L) == 1) return 0;
  
  Paux = newNode();

  // Se a alocacao nao foi possivel, interrompa
  if (Paux == NULL) return 0;  

  Paux->info = X;
  Paux->next = L->head;
  L->head = Paux;
  
  return 1;
}

int retirar(Lista *L, char X)
{
  Node *Pant, *Paux;
  // exercicio: colocar em uma função

  // busca pelo elemento procurado
  Paux = L->head;
  Pant = NULL;

  while(Paux != NULL && Paux->info < X){
    Pant = Paux;
    Paux = Paux->next;
  }

   //Elemento encontrado, vamos removê-lo
  if(Paux != NULL && Paux->info == X){
   
    // primeiro caso, encontrou no interior da lista ou no fim
    if(Paux != L->head){

      Pant->next = Paux->next;
      
    } else { 
      // segundo caso, achou na primeira posição
      L->head = Paux->next;

      //alternativa 2: L->head = L->head->next;
    }

    deleteNode(Paux);

  } else return 0;
}

void destruir(Lista *L){

  Node *Paux;

  while(!vazia(L)){
    Paux = L->head;
    L->head = Paux->next;
    deleteNode(Paux);
  }

  free(L);
}

// Não respeita o tad
void imprimir(Lista *L){
  Node *Paux;

  Paux = L->head;

  while(Paux != NULL){
    printf("%c \n", Paux->info);
    Paux = Paux->next;
  }
}

int main()
{
    Lista *L;

    // Criar a lista
    L = criar();
    if (L == NULL) {
        printf("Erro ao criar a lista\n");
        exit(1);
    }
    
    empilhar(L, 'E');
    empilhar(L, 'D');
    empilhar(L, 'C');
    empilhar(L, 'B');
    empilhar(L, 'A');
    imprimir(L);
    
    retirar(L, 'D');
    imprimir(L);

    retirar(L, 'A');
    imprimir(L);

    retirar(L, 'C');
    imprimir(L);

    destruir(L);

    return 0;
}
