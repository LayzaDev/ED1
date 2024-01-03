#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "ponto.h"
#include "circle.h"

struct circle {
    Ponto *centro; 
    float raio;
};

// Função que cria um círculo com centro no ponto P e raio r

Circle *createCircle(Ponto* centro, float raio)
{
    Circle *circulo = (Circle *) malloc(sizeof(Circle));
    assert(circulo != NULL);

    circulo->centro = centro;
    circulo->raio = raio;

    return circulo;
}

// Função que calcula a área de um círculo

float area(Circle *circulo)
{
    return PI * pow(circulo->raio, 2);
}

// Função que verifica se um ponto P está dentro de um círculo C

int dentroDoCirculo(Ponto *ponto, Circle *circulo){

    float dist = distancia(ponto, circulo->centro);

    if(dist < circulo->raio){
        return 1;
    } else {
        return 0;
    }
}

// Função que libera a memória alocada para um círculo

void destruirCirculo(Circle *circulo){
    destroyPonto(circulo->centro);
    free(circulo);
}
