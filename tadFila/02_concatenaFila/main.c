#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(){

    fila_t *f = cria();
    if(f == NULL){
        printf("Erro \n");
        exit(-1);
    }

    printf("Insira elementos na fila: \n");
}