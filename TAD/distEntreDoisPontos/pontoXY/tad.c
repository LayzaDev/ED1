#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "tad.h"

struct ponto
{
    float x;
    float y;
};

//(a) criar_ponto(x, y): cria um ponto com as coordenadas x e y e retorna um ponteiro para o ponto criado.
ponto_t *criar(float x, float y)
{
    ponto_t *p = (ponto_t *) malloc(sizeof(ponto_t));
    assert(p != NULL);

    p->x = x;
    p->y = y;

    return p;
}

//(b) destruir_ponto(ponto): libera a memória alocada para o ponto recebido como parâmetro.
void destruir(ponto_t *p){
    free(p);
}

//(c) acessar_x(ponto): retorna a coordenada x e a coordenada y do ponto recebido como parâmetro.
float acessarX(ponto_t *p){
    return p->x;
}

float acessarY(ponto_t *p){
    return p->y;
}

//(d) distancia(ponto1, ponto2): calcula e retorna a distância entre dois pontos recebidos como parâmetros.
float distancia(ponto_t *p1, ponto_t *p2){

    float distX = p2->x - p1->x;
    float distY = p2->y - p1->y;

    return sqrt(pow(distX, 2) + pow(distY, 2));
}