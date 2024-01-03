#include <stdio.h>
#include "fracao.h"

int main(){

    fracao_t *f1, *f2;

    f1 = create(1, 2);
    f2 = create(3, 4);

    fracao_t *f3 = sum(f1, f2);

    print(f1);
    print(f2);
    print(f3);

    destroy(f1);
    destroy(f2);
    destroy(f3);

    return 0;
}