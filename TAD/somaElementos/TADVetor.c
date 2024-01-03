#include<stdlib.h>
#include<stdio.h>

struct vetor {
	int valor[10];
	int tamanho;
};

typedef struct vetor Vetor;

int soma(Vetor vet)
{
	int s;

	s = 0;
	for (int i = 0; i < vet.tamanho; i++) {
		s = s + vet.valor[i];
	}

	return s;
}

int main()
{
	Vetor vet;

	printf("Digite o tamanho do vetor: ");
	scanf("%d", &vet.tamanho);

	for (int i = 0; i < vet.tamanho; i++) {
		printf("Digite o %do. valor: ", i+1);
		scanf("%d", &vet.valor[i]);
	}

	printf("O valor da soma eh: %d\n", soma(vet));

	return 0;
}
