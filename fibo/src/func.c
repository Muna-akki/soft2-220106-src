#include <stdio.h>
#include <stdlib.h>
#include "./../include/array.h"

Array* make_default(){
    Array* ar = (Array*) malloc(sizeof(Array));
    ar->a[0][0] = 1;
    ar->a[1][0] = 0;
    ar->a[2][0] = 0;
    ar->a[3][0] = 1;
    for(int i=0 ; i<3 ; i++){
        ar->a[i][1] = 1;
    }
    ar->a[3][1] = 0;
    ar->memo[0] = 1;
    ar->memo[1] = 1;
    for(int i=2 ; i<100 ; i++){
        ar->memo[i] = 0;
    }
    return ar;
}
void advance_array(Array* ar, int n){
    if( (ar->memo[n]) == 1 ){
        return;
    }
    advance_array(ar,n/2);
    ar->memo[n] = 1;
    long o = ar->a[0][n/2];
    long p = ar->a[1][n/2];
    long q = ar->a[2][n/2];
    long r = ar->a[3][n/2];
    ar->a[0][n] = o*o + p*q;
    ar->a[1][n] = o*p + p*r;
    ar->a[2][n] = o*q + q*r;
    ar->a[3][n] = p*q + r*r;
    if(n%2==1){
        long o2 = ar->a[0][n];
        long q2 = ar->a[2][n];
        ar->a[0][n] += ar->a[1][n];
        ar->a[2][n] += ar->a[3][n];
        ar->a[1][n] = o2;
        ar->a[3][n] = q2;
    }
    return;
}
