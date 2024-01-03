#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "pilha.h"
#include "fila.h"

struct pilha 
{
    int topo;
    int elem_P[tamPilha];
};

Pilha *createPilha(){

    Pilha *p = (Pilha *) malloc(sizeof(Pilha));
    assert(p != NULL);

    p->topo = -1;

    return p;
}

void destroyPilha(Pilha *p){

    if(p != NULL){
        free(p);
    }
}   

int isFullPilha(Pilha *p){

    assert(p != NULL);

    if(p->topo == tamPilha)
    {
        return 1;
    } else 
    {
        return 0;
    }

}

int isEmptyPilha(Pilha *p){
    
    assert(p != NULL);

    if(p->topo == -1)
    {
        return 1;
    } else 
    {
        return 0;
    }
}

int pushPilha(Pilha *p, char c){
    assert(p != NULL);

    if(isFullPilha(p) == 1){
        return 0;
    } 

    p->topo++;
    p->elem_P[p->topo] = c;

    return p;
}

int popPilha(Pilha *p){

    assert(p != NULL);

    if(isEmptyPilha(p) == 1){
        return 0;
    } 

    char valor = p->elem_P[p->topo];
    p->topo--;
    return valor;

    return p;
}


int inverteOrdemFila(Fila *f, Pilha *p){

    while(isEmptyPilha(p) == 0){
        int item = popPilha(p);
        pushFila(f, item);
    }

    while(isEmptyFila(f) == 0){
        int item = popFila(f);
        pushPilha(p, item);
    }

    return 1;
}