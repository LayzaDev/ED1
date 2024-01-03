#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main()
{
    FilaPrioridade *fp;
    char c;
    int prioridade;

    fp = criar();

    while (!cheia(fp)) {
        printf("Entre com um caractere e sua prioridade: ");
        scanf(" %c %d", &c, &prioridade);
	inserir(fp, c, prioridade);
    }

    while (retirar(fp, &c) == 1) {
        printf("%c\n", c);
    }

    destruir(fp);

    return 0;
}