#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "ponto.h"

struct ponto
{
    float x;
    float y;
};

//(a) criar_ponto(x, y): cria um ponto com as coordenadas x e y e retorna um ponteiro para o ponto criado.
Ponto *createPonto(float x, float y)
{
    Ponto *p = (Ponto *) malloc(sizeof(Ponto));
    assert(p != NULL);

    p->x = x;
    p->y = y;

    return p;
}

//(b) destruir_ponto(ponto): libera a memória alocada para o ponto recebido como parâmetro.
void destroyPonto(Ponto *p){
    free(p);
}

//(c) acessar_x(ponto): retorna a coordenada x e a coordenada y do ponto recebido como parâmetro.
float acessarX(Ponto *p){
    return p->x;
}

float acessarY(Ponto *p){
    return p->y;
}

//(d) distancia(ponto1, ponto2): calcula e retorna a distância entre dois pontos recebidos como parâmetros.
float distancia(Ponto *p1, Ponto *p2){

    float distX = p2->x - p1->x;
    float distY = p2->y - p1->y;

    return sqrt(pow(distX, 2) + pow(distY, 2));
}