#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "pilha.h"

struct pilha {
    int topo;
    char elementos[tamPilha];
};

Pilha *criar(){
    Pilha *p = (Pilha *) malloc(sizeof(Pilha));
    assert(p != NULL);

    p->topo = -1;
    return p;
}

void destruir(Pilha *p){
    if(p != NULL){
        free(p);
    }
}

int vazia(Pilha *p){

    assert(p != NULL);

    if(p->topo == -1){
        return 1;
    } else {
        return 0;
    }
}

int cheia(Pilha *p){

    assert(p != NULL);

    if(p->topo == tamPilha - 1){
        return 1;
    } else {
        return 0;
    }
}

int inserirX(Pilha *p, char x){
    assert(p != NULL);

    if(cheia(p) == 1){
        return 0;
    } 

    p->topo += 1;
    p->elementos[p->topo] = x;

    return 1;
}

int inserirY(Pilha *p, char y){
    assert(p != NULL);

    if(cheia(p) == 1){
        return 0;
    }

    p->elementos[p->topo] = y;
    p->topo += 1;

    return 1;
}

int removerX(Pilha *p, char *x){
    
    if(vazia(p) == 1){
        return 0;
    }

    *x = p->elementos[p->topo];
    p->topo--;

    return 1;
}

int removerY(Pilha *p, char *y){
    
    if(vazia(p) == 1){
        return 0;
    }

    *y = p->elementos[p->topo];
    p->topo--;

    return 1;
}

