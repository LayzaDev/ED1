#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "pilha.h"
#include "fila.h"
/*
Considere uma Pilha P vazia e uma Fila F não vazia. 
Utilizando apenas os testes de Fila e Pilha vazias, as operações Inserir, Retirar, Empilhar e Desempilhar, e uma variável aux do tipo char, escreva uma função que inverta a ordem dos elementos da Fila.
*/

int main(){

    Fila *f = createFila();
    if(f == NULL){
        printf("erro na fila \n");
        exit(-1);
    };

    Pilha *p = createPilha();
    if(p == NULL){
        printf("erro na pilha\n");
        exit(-1);
    };

    printf("Insira elementos na fila: \n");

    while(isFullFila(f) == 0){

        int c;

        scanf("%d", &c);
        pushFila(f, c);
    }

    int resultado = inverteOrdemFila(f, p);

    printf("%d \n", resultado);

    destroyFila(f);
    destroyPilha(p);

    return 0;
}