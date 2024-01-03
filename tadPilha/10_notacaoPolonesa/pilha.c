#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "pilha.h"

struct pilha {
    int topo; 
    char elements[tamPilha];
};

typedef struct pilha pilha_t;

pilha_t *create(){

    pilha_t *p = (pilha_t *) malloc(sizeof(pilha_t));
    assert(p != NULL);

    p->topo = -1;

    return p;
}

void destroy(pilha_t *p){

    if(p != NULL){ 
        free(p);
    }
}

int isFull(pilha_t *p){

    assert(p != NULL);

    if(p->topo == tamPilha - 1){
        return 1;
    } else {
        return 0;
    }
}

int isEmpty(pilha_t *p){

    assert(p != NULL);

    if(p->topo == -1){

        return 1;
        
    } else {
        return 0;
    }
}

int push(pilha_t *p, char x){
    
    assert(p != NULL);

    if(isFull(p) == 1){
        return 0;
    }

    p->topo+=1;
    p->elements[p->topo] = x;

    return 1;
}

int pop(pilha_t *p, char *x){

    assert(p != NULL);

    if(isEmpty(p) == 1){
        return 0;
    }

    *x = p->elements[p->topo];
    p->topo-=1;

    return 1;
}
