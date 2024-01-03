#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "fila.h"
#include "pilha.h"

struct fila 
{
    int first, last, total;
    int elem[tamFila];
};

Fila *createFila()
{

    Fila *f = (Fila *) malloc(sizeof(Fila));
    assert(f != NULL);

    f->first = 0;
    f->last = 0;
    f->total = 0;

    return f;
}

void destroyFila(Fila *f)
{

    if(f != NULL)
    {
        free(f);
    }
}

int isFullFila(Fila *f)
{

    assert(f != NULL);

    if(f->total == tamFila)
    {
        return 1;
    } else 
    {
        return 0;
    }
}

int isEmptyFila(Fila *f)
{
    assert(f != NULL);

    if(f->total == 0)
    {
        return 1;
    } else 
    {
        return 0;
    }
}

int pushFila(Fila *f, int c)
{
    assert(f != NULL);

    if(isFullFila(f) == 1){
        return 0;
    }

    f->last++;
    f->elem[f->last] = c;
    f->total++;

    return 1;
}

int popFila(Fila *f){

    assert(f != NULL);
    if(isEmptyFila(f) == 1){
        return 0;
    }

    int valor = f->elem[f->first];
    f->first = (f->first + 1) % tamFila;

    return valor;
}



