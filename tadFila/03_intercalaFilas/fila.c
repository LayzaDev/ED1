#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "fila.h"

struct fila
{
    int inicio, fim, total;
    int elements[MAX];
};

fila_t *cria()
{
    fila_t *f = (fila_t *) malloc(sizeof(fila_t));
    assert(f != NULL);

    f->inicio = 0;
    f->fim = 0;
    f->total = 0;

    return f;
}

int isEmpty(fila_t *f)
{
    assert(f != NULL);

    if(f->total == 0){
        return 1;
    }
    return 0;
}

int isFull(fila_t *f){
    assert(f != NULL);

    if(f->total == MAX - 1){
        return 1;
    }
    return 0;
}

int insere(fila_t *f, int x){

    if(isFull(f) == 1 || f == NULL){
        return 0;
    }

    f->elements[f->fim] = x;
    f->fim = (f->fim + 1) % MAX;
    f->total++;

    return 1;
}

int retira(fila_t *f){

    assert(f != NULL);

    if(isEmpty(f) == 1){
        return 0;
    }

    f->elements[f->inicio] = (f->inicio + 1) % MAX;
    f->total--;

    return 1;
}

fila_t * intercalaFilas(fila_t *f, fila_t *f1, fila_t *f2){

    while(isEmpty(f1) == 0 && isEmpty(f2) == 0){

        char item1 = retira(f1);
        insere(f, item1);
        char item2 = retira(f2);
        insere(f, item2);
    }
    
    return f;
}