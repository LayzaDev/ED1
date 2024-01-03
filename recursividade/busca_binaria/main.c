#include<stdlib.h>
#include<stdio.h>

int busca_binaria(int *A, int chave, int first, int last)
{
    if (first > last) return 0; // false

    int m = (first + last) / 2;
    if (chave == A[m]) return 1;
    else if (chave > A[m]) return busca_binaria(A, chave, m+1, last);
    else return busca_binaria(A, chave, first, m-1);
}

int main(int argc, char *argv[])
{
    int vet[] = {1, 2, 3, 5, 8, 13, 21, 44};
    int valor;

    printf("Digite o valor a ser procurado: ");
    scanf("%d", &valor);
  
    if (busca_binaria(vet, valor, 0, 8) == 1)
        printf("Encontrou\n");
    else printf("Nao encontrou\n");

    return 0;
}