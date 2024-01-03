#include <stdio.h>
#include <stdlib.h>

int comb(int n, int k){

    if(k == 1){
        return n;
    } else if (k == n){
        return 1;
    } else if(k > 1 && k < n){
        return comb(n-1, k-1) + comb(n-1, k);
    }
}

int main(){

    int n, k;
    
    printf("Valor de n e k: \n");
    scanf("%d %d", &n, &k);

    printf("Comb: %d \n", comb(n, k));

    return 0;
}