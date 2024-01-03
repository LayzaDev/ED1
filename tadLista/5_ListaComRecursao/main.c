#include<stdlib.h>
#include<stdio.h>

// declaracao do no(node) da lista encadeada simples
struct node {
    int info;
    struct node *next;
};

// definicao do tipo Node
typedef struct node Node;

// declaracao da lista em si
struct lista {
    Node *head;
    //struct node *topo;
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
    if (L != NULL) L->head = NULL; // lista vazia
    
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
    if (L->head == NULL) return 1;
    else return 0;
}

int inserir(Lista *L, int X)
{
	Node *Paux, *Pant; // Ponteiros auxiliares
	Node *P; // Ponteiro para o novo node
	
	// Se a lista esta cheia, nao pode inserir
	if (cheia(L)) return 0;

	// Cria o novo node e verifica se eh valido
	P = newNode();
	if (P == NULL) return 0;

	P->info = X;
	Paux = L->head;
	Pant = NULL;

	// Busca a possivel posicao de insercao
	while (Paux != NULL && Paux->info < X) {
		Pant = Paux;
		Paux = Paux->next;
	}

	// Elemento ja existente na lista
	if (Paux != NULL && Paux->info == X) return 0;

	if (Paux != L->head) {
		// Caso 1: Node inserido no interior da lista
		// (cauda?)
		Pant->next = P;
		P->next = Paux;
	} else {
		// Caso 2: Node inserido na primeira posicao
		// (cabeca)
		L->head = P;
		P->next = Paux;
	}

	return 1;
}

int remover(Lista *L, int X)
{
	Node *Paux, *Pant;

	Paux = L->head;
	Pant = NULL;

	// Busca o elemento a ser removido
	while (Paux != NULL && Paux->info < X) {
		Pant = Paux;
		Paux = Paux->next;
	}

	if (Paux != NULL && Paux->info == X) {
		// encontrei o elemento e vou retira-lo
		if (Paux != L->head) {
			Pant->next = Paux->next;
		} else {
			//L-head = L->head->next;
			L->head = Paux->next;
		}
		deleteNode(Paux);
		return 1;	// true, deu certo
	} else { // nao encontrei o elemento
		return 0;	// false, nao achou
	}
}

// Utiliza recursao de cauda
int comprimento_cauda(Node *P, int n)
{
	if (P == NULL) return n;
	else {
		return comprimento_cauda(P->next, n+1);
	}
}

int comprimento(Lista *L)
{
	Node *P;
	int comp;

	P = L->head;
	comp = comprimento_cauda(P, 0);

	return comp;
}

int pertence_auxiliar(Node *P, int X)
{	//Chegou ao final da lista e não encontrou X
  if(P == NULL) return 0; 
	//Encontrou X, então X pertence a lista
  else if(P->info == X) return 1; 
	//Ainda não encontrou X, então continua percorrendo a lista
  else return pertence_auxiliar(P->next, X); 
}

int pertence(Lista *L, int X)
{
  Node *Paux;
  Paux = L->head;
 // Inicia a recursão e retorna o resultado da verificação de pertencimento
 return pertence_auxiliar(Paux, X);
}

int ultimo_auxiliar(Node *P){
	// Se P for igual a Nulo, não encontramos o elemento
  if(P == NULL) return 0;
	// Se o próximo de P for igual a NULL, retorna o valor de P->info
  else if(P->next == NULL) return P->info;
	// Senão, chama a função novamente passando pro próximo de P
  else return ultimo_auxiliar(P->next);
}

int ultimo(Lista *L)
{
  Node *Paux;
  Paux = L->head;
  return ultimo_auxiliar(Paux);
}

int soma_auxiliar(Node *P)
{
	if(P == NULL)
		return 0;
	else
		return P->info + soma_auxiliar(P->next);
}

int soma(Lista *L){

	Node *Paux;
	Paux = L->head;

	if(vazia(L) == 1){
		return 0;
	} else {
		return soma_auxiliar(Paux);
	}
}

int soma_impares_aux(Node *P){
	if(P == NULL){
		return 0;
	} else {
		if (P->info % 2 != 0)
		{
			return P->info + soma_impares_aux(P->next);
		} else {
			return soma_impares_aux(P->next);
		}
	}
} 

int soma_impares(Lista *L){

	Node *Paux;
	Paux = L->head;

	if(vazia(L) == 1){
		return 0;
	} else {
		return soma_impares_aux(Paux);
	}
}

int n_esimo_aux(Node* P, int N) {
    if (P == NULL || N < 0) {
      return -1; // Valor inválido para indicar que o elemento não foi encontrado ou parâmetros inválidos
    } else if (N == 0) {
      return P->info;
    } else if (P->next != NULL) {
      return n_esimo_aux(P->next, N - 1);
    } else {
      return -1; // Valor inválido para indicar que o elemento não foi encontrado
    }
}

int n_esimo(Lista* L, int N) {
	Node* P = L->head;

	if (P == NULL) {
		return -1; // Valor inválido para indicar que a lista está vazia
	} else if(N == 0){
		return P->info;
	} else {
		return n_esimo_aux(P, N);
	}
}

// NAO RESPEITA O TAD
void imprimir(Lista *L)
{
	Node *Paux;
	Paux = L->head;

	while (Paux != NULL) {
		printf("%d ", Paux->info);
		Paux = Paux->next;
	}
	printf("\n");
}

void destruir(Lista *L)
{
	// Avanca o head e deleta o Paux
	Node *Paux;

	while(!vazia(L)) {
		Paux = L->head;
		L->head = Paux->next;
		deleteNode(Paux);
	}
	free(L);
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

	printf("-------------------------------------------------\n\n");

	int tamanho, elemento;

	printf("Defina um tamanho para a lista: ");
	scanf("%d", &tamanho);

	printf("\n-------------------------------------------------\n\n");

	printf("Insira numeros inteiros na lista:\n");

	for(int i = 0; i < tamanho; i++){
		
		int valor = 1;

		scanf("%d", &valor);

		inserir(L, valor);
	}

	printf("\n-------------------------------------------------\n\n");

	printf("Verifique se um numero pertence a lista: ");
	scanf("%d", &elemento);

	printf("\nO numero %d pertence a lista?  %d ", elemento, pertence(L, elemento));

	printf("\n\n-------------------------------------------------\n\n");

	int N;
	printf("Digite o valor de N: ");
	scanf("%d", &N);

	printf("\nn-ésimo elemento da lista: %d ", n_esimo(L, N));

	printf("\n\n-------------------------------------------------\n\n");

	printf("Lista: ");
	imprimir(L);

	printf("\n-------------------------------------------------\n\n");

	printf("Comprimento da lista: %d", comprimento(L));

	printf("\n\n-------------------------------------------------\n\n");

	printf("Ultimo elemento da lista: %d ",ultimo(L));

	printf("\n\n-------------------------------------------------\n\n");

	printf("Somatório dos números da lista: %d ", soma(L));

	printf("\n\n-------------------------------------------------\n\n");

	printf("Somatório dos números ímpares da lista: %d ", soma_impares(L));

	printf("\n\n-------------------------------------------------\n\n");

	remover(L, 2);
	remover(L, 4);
	remover(L, 1);
	remover(L, 6);
	remover(L, 10);

	printf("Lista após remoção: ");
	imprimir(L);

	printf("\n-------------------------------------------------\n\n");

	//printf("%d\n", remover(L, ));
	//imprimir(L);

	// printf("%d\n", remover(L, 'F'));
	//imprimir(L);

	printf("Novo comprimento da lista: %d ", comprimento(L));

	printf("\n\n-------------------------------------------------\n\n");

	printf("Novo ultimo elemento da lista: %d ",ultimo(L));

	printf("\n\n-------------------------------------------------\n\n");
	
	destruir(L);
	
	return 0;
}