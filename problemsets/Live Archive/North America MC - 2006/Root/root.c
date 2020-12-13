/* Root of the problem */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int B, n;
double N;
int a;

int pwr(int x, int y) {

    int aux;

    if (y == 0) return(1);
    if (y%2) return(pwr(x, y-1) * x);
    else {
        aux = pwr(x, y/2);
        return(aux*aux);
    }  
}


int main() {

    while (scanf("%d %d", &B, &n)) {
        
        if ((!B) && (!n)) break;
        
        N = n;
        a = floor(exp((1.0/N)*log(B)));
        if (abs(B-pwr(a, n)) <= abs(B-pwr(a+1, n))) printf("%d\n", a);
        else printf("%d\n", a+1);
    }
    
    return 0;
}
