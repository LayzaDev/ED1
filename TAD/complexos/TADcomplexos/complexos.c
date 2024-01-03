#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complexos.h"

// Criar uma estutura que contenha os parametros necessarios para se criar um numero complexo;
struct complexo {
    float real;
    float imag;
};
// Implementar uma função para criar um numero complexo, a função recebe dois valores do tipo float
Complexo *criar(float real, float imag){

    Complexo *c;

    c->real = real;
    c->imag = imag;

    return c;
}

// Implementar uma função soma, para somar as duas partes do numero complexo (reais e imaginarios)
Complexo *soma(Complexo *c1, Complexo *c2){

    Complexo *sum;
    
    sum = criar(c1->real + c2->real, c1->imag + c2->imag);

    return sum;
}

//Criar uma função que recebe um numero complexo passado por valor e dois valores do tipo float passados por referencia, essa função deve separar os valores recebidos por cada parte.
void separa(Complexo *c, float *real, float *imag){

    *real = c->real;
    *imag = c->imag;

}

// Criar uma função que recebe um numero complexo e retorne apenas sua parte real
float get_real(Complexo *c){

    return c->real;
}

// Criar uma função que recebe um numero complexo e retorne apenas sua parte imaginaria
float get_imag(Complexo *c){

    return c->imag;
}

/* Implementar uma função para multiplicar dois numeros complexos (Multiplicação de números complexos:USAR DISTRIBUTIVA)
    
    
    z1 · z2 = (a + bi)*(c + di), aplicando a propriedade distributiva,

    z1 · z2 = ac + adi + cbi + bdi^2, mas, como vimos, i² = sqrt(-1)

    z1 · z2 = ac + adi + cbi – bd

    z1 · z2 = (ac – bd) + (ad + cb)i

    c1 * c2 = (a*c – b*d) + (a*d + c*b)i
                reais          imag
    a = c1.real
    c = c2.real
    bi = c1.imag
    di = c2.imag
*/
Complexo *multiplica(Complexo *c1, Complexo *c2){

    Complexo *mult;

    mult->real = c1->real * c2->real - c1->imag * c2->imag;
    mult->imag = c1->real * c2->imag + c1->imag * c2->real;

    return mult; 
}

// Implementar uma função para calcular o modulo de um numero complexo(calculo do modulo: raiz quadrada da parte real elevada a 2 + parte imag elevada a 2)
float modulo(Complexo *c){

    float mod;

    mod = sqrt(pow(c->real, 2) + pow(c->imag, 2));
    //Forma 2: sqrt(c.real * c.real + c.imag * c.imag);

    return mod;
}
