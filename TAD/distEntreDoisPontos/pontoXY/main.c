#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "tad.h"

int main(){

    ponto_t *p1;
    ponto_t *p2;
    p1 = criar(4.0, 1.0);
    p2 = criar(1.0, 3.0);

    printf("Coordenadas do ponto p1: (%f, %f)\n", acessarX(p1), acessarY(p1));
    printf("Coordenadas do ponto p2: (%f, %f)\n", acessarX(p2), acessarY(p2));
  
    printf("Distancia entre p1 e p2: %f\n", distancia(p1, p2));
  
    destruir(p1);
    destruir(p2);
  
    return 0;
}