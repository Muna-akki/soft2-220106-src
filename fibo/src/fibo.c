#include <stdio.h>
#include <stdlib.h>
#include "./../include/array.h"

long fibo(int n);

int main(void){
    for(int i=0 ; i<100 ; i++){
        printf("%ld\n",fibo(i));
    }
    return 0;
}

long fibo(int n){
    if(n>90){
        printf("too large\n");
        exit(1);
    }
    Array* ar = make_default();
    advance_array(ar,n);
    return ar->a[2][n];
}

