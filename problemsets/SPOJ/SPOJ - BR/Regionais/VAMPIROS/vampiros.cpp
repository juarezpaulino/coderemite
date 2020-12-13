/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/* Vampiros */

#include <stdio.h>

double pow(double p, int n) {
    double r;
 
    if (n == 0) return 1;
    else if (n&1) return pow(p, n-1) * p;
    else {
        r = pow(p, n>>1);
        return r*r;
    }
}


int main() {
    
    int ev1, ev2, at, d;
    int e1, e2, n;
    int i;
    double p, eps;
    
    while (scanf("%d %d %d %d", &ev1, &ev2, &at, &d)) {
        
        if (!ev1 && !ev2 && !at && !d) break;
        
        p = at/6.0;
        e1 = (ev1+d-1) / d; e2 = (ev2+d-1) / d;
        n = e1+e2;
        
        if (at == 3) printf("%.1lf\n", ((double)e1/n)*100);
        else {
            p = (1 - pow((1-p)/p,e1)) / (1 - pow((1-p)/p,n));
            printf("%.1lf\n", p*100);
        }
    }
    
    return 0;   
}
