/* verifica se existe um .h na sua pasta

#ifndef _COMPLEXO_H_
#define _COMPLEXO_H_
*/

typedef struct complexo Complexo;

// chamada das funções
Complexo *criar(float real, float imag);

Complexo *soma(Complexo* c1, Complexo* c2);

void separa(Complexo* c, float *real, float *imag);

float get_real(Complexo* c);

float get_imag(Complexo* c);

Complexo *multiplica(Complexo* c1, Complexo* c2);

float modulo(Complexo* c);
