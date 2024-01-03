#include <stdio.h>
#include <stdlib.h>
#include "fracao.h"

fracao_t *create(int num, int den){

    if(den == 0){
        return NULL;
    }

    fracao_t *f = (fracao_t *) malloc(sizeof(fracao_t));

    if(f == NULL){
        return NULL;
    }

    f->num = num;
    f->den = den;

    return f;

};

void print(fracao_t *f){

    if(f != NULL){
        printf("%d / %d \n", f->num, f->den);
    }

}

void destroy(fracao_t *f){

    if(f != NULL){
        free(f);
        f = NULL;
    }
}

int mdc(int num, int den){

    if(den == 0){

        return num;

    } else {

        return mdc(den, num % den);
    }
}

int mmc(int num, int den){

    return num * den / mdc(num, den);
}

fracao_t *sum(fracao_t *F1, fracao_t *F2){

    if(F1 == NULL || F2 == NULL){
        return NULL;
    }

    fracao_t *f = (fracao_t *) malloc(sizeof(fracao_t));

    if(f == NULL){
        return NULL;
    }

    f->den = mmc(F1->den, F2->num);
    f->num = (f->den / F1->den) * F1->num + (f->den / F2->den) * F2->num;

    return f;
}
