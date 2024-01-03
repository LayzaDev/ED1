#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "fila.h"

struct fila
{
    int esq, dir, total;
    int elements[MAX];
};

fila_t *cria()
{
    fila_t *f = (fila_t *) malloc(sizeof(fila_t));
    assert(f != NULL);

    f->esq = 0;
    f->dir = 0;
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

int insDir(fila_t *f, int x){

    if(isFull(f) == 1 || f == NULL){
        return 0;
    }

    f->elements[f->dir] = x;
    f->dir = (f->dir+1) % MAX;
    f->total++;

    return 1;
}

int insEsq(fila_t *f, int x){

    if(isFull(f) == 1 || f == NULL){
        return 0;
    }

    f->esq--;

    if(f->esq < 0){
        f->esq = MAX - 1;
    }

    f->elements[f->esq] = x;
    f->total++;

    return 1;
}

int remEsq(fila_t *f){

    assert(f != NULL);

    if(isEmpty(f) == 1){
        return 0;
    }

    f->esq = (f->esq + 1) % MAX;
    f->total--;

    return 1;
}

int remDir(fila_t *f){

    assert(f != NULL);

    if(isEmpty(f) == 1){
        return 0;
    }

    f->dir--;
    if(f->dir < 0){
        f->dir = MAX - 1;
    }
    f->total--;

    return 1;
}

