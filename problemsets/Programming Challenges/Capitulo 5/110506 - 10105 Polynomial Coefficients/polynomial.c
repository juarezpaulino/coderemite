/* Polynomial Coefficients */

#include <stdio.h>

int f[13] = {1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600};

long long factorial(long long num) {
    
    if (num <= 1)
        return (long long) 1;
    
    if (num <= 12)
        return (long long) f[(int) num];
           
    return (num * factorial(num - 1));
}


int main() {
    
    long long prod, coef;
    int n, k, i, ni;
    
    while (scanf("%d %d", &n, &k) != EOF) {
        
        prod = 1;
        
        for (i = 0; i < k; i++) {
            scanf("%d", &ni);
            prod =  prod * factorial(ni);
        }
        
        coef = f[(int)n]/prod;
        
        printf("%Ld\n", coef);
    }
    
    return 0;
}
