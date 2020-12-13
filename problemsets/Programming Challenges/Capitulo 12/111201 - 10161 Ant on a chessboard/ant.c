/* Ant on a Chessboard */

#include <stdio.h>
#include <math.h>


int main() {

    unsigned n, x, aux;    
    
    while (scanf("%u", &n)) {
        
        if (n == 0)
            break;
    
        x = ceil(sqrt(n));
        aux = 2*(x-1);
        
        if (x%2) {
            if ((x*x) - n <= aux/2)
                printf("%u %u\n", (x*x)-n+1, x);
            else
                printf("%u %u\n", x, n-(x*x)+aux+1);
        }
        else {
            if ((x*x) - n <= aux/2)
                printf("%u %u\n", x, (x*x)-n+1);
            else
                printf("%u %u\n", n-(x*x)+aux+1, x);
        }
    }
    
    return 0;
}
