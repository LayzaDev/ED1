#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int mdc(int a, int b){
    if(b == 0){
        return a;
    } else {
        return mdc(b, a%b);
    }
}

int main(){

    int a, b;

    printf("Valor de a: \n");
    scanf("%d", &a);
    printf("Valor de b: \n");
    scanf("%d", &b);

    mdc(a, b);

    printf("mdc: %d \n", mdc(a, b));
    return 0;
}