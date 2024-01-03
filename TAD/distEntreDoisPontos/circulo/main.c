#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "ponto.h"
#include "circle.h"

int main(){

    float x1, y1, x2, y2, raio;

    printf("\nponto 1 (x, y): \n\n");
    scanf("%f %f", &x1, &y1);

    Ponto *p1 = createPonto(x1, y1);

    printf("\nponto 2 (x,y): \n\n");
    scanf("%f %f", &x2, &y2);
   
    Ponto *p2 = createPonto(x2, y2);

    printf("\nRaio: \n\n");
    scanf("%f", &raio);

    // cria um circulo com centro no ponto p1 e raio 2

    Circle *c1 = createCircle(p1, raio);

    // acessa as coordenadas dos pontos

    float x1_get, y1_get, x2_get, y2_get;
    
    x1_get = acessarX(p1);
    y1_get = acessarY(p1);
    x2_get = acessarX(p2);
    y2_get = acessarY(p2);
    
    printf("\nCoordenadas de p1: (%.2f, %.2f)\n\n", x1_get, y1_get);
    printf("\nCoordenadas de p2: (%.2f, %.2f)\n\n", x2_get, y2_get);

    // calcula a distancia entre os pontos
    
    float dist = distancia(p1, p2);
    printf("\nDistancia entre p1 e p2: %f \n\n", dist);

    // calcula a area do circulo

    float area_Circulo = area(c1);
    printf("\nArea do circulo: %f \n\n", area_Circulo);

    // verifica se o ponto p2 esta dentro do circulo
    
    if(dentroDoCirculo(p1, c1) || dentroDoCirculo(p2, c1)){
        printf("\nO ponto está dentro do circulo \n\n");
    } else {
        printf("\nO ponto está fora do circulo: \n\n");
    }
    
    // libera a memoria dos pontos e do circulo

    destroyPonto(p1);
    destroyPonto(p2);
    destruirCirculo(c1);
    
    return 0;
}