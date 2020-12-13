/* Euclid Problem */

#include <stdio.h>


long gcd(long p, long q, long *x, long *y) {
    
    long x1, y1;
    long g;
    
    if (q > p) return (gcd(q, p, y, x));
    
    if (q == 0) {
        *x = 1;
        *y = 0;
        return (p);
    }
    
    g = gcd(q, p%q, &x1, &y1);
    
    *x = y1;
    *y = (x1 - floor(p/q)*y1);
    
    return (g);
}


int main() {
    
    long a, b, d, x, y;
    
    while(scanf("%ld %ld", &a, &b) != EOF) {
        
        d = gcd(a, b, &x, &y);
        
        printf("%ld %ld %ld\n", x, y, d);
    
    }
    
    return 0;
}
