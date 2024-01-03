#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complexos.h"

int main(){

    Complexo* c;
    Complexo* c1;
    Complexo* c2;
    Complexo* c3;

	float aux1, aux2;

    // O usuario deve passar dois numeros reais e imaginarios como parametro;

    printf("----------------------------------------------------------------\n");

    printf("Digite o valor da parte real e imaginaria do primeiro numero: \n\n");
    scanf("%f %f", &aux1, &aux2);
    c1 = criar(aux1, aux2);

    printf("\n----------------------------------------------------------------\n");

    printf("Digite o valor da parte real e imaginaria do segundo numero: \n\n");
    scanf("%f %f", &aux1, &aux2);
    c2 = criar(aux1, aux2);

    printf("\n----------------------------------------------------------------\n\n");

    c3 = soma(c1, c2);
    printf("SOMA: %.2f %.2fi \n", get_real(c3), get_imag(c3));

    printf("\n----------------------------------------------------------------\n\n");

    c3 = multiplica(c1, c2);
    printf("MULTIPLICACAO: %.2f + %.2fi \n", get_real(c3), get_imag(c3));

    printf("\n----------------------------------------------------------------\n\n");

    printf("MODULO: %.2f \n", modulo(c));

    printf("\n----------------------------------------------------------------\n");

    return 0;
}