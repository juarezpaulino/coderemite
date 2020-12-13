/* The cat in the hat */

#include <stdio.h>
#include <math.h>

int main() {

    double c;
    double xk, xk1, xc;
    int Sa, Sh;
    int ak, h0;
    int N, k;
    int word;
    
    while (scanf("%d %d", &h0, &ak)) {
        
        if ((h0 == 0) && (ak == 0))
            break;

        if (ak == 1) {
            word = h0;
            Sa = 0;
            while (word >>= 1) Sa++;
            Sh = (h0<<1)-1.0;
        }
        else {
            c = log(h0)/log(ak);
            xk = -1.0;
            xk1 = 1.0;
            while (fabs(xk1 - xk) > 0.5) {
                xk = xk1;
                xc = pow(xk, c);
                xk1 = ((c-1.0)*xc + 1.0)/(c*xc/xk - 1.0);
            }
            N = floor(xk+0.5);
            k = floor((log(ak)/log(N))+0.5);

            Sa = floor(((pow(N, k+1.0) - 1.0)/(N-1.0)) - ak + 0.5);
            Sh = floor((ak*N*(pow((N+1.0)/N, k+1.0) - 1.0)) + 0.5);
        }
            
        printf("%d %d\n", Sa, Sh);
    }
    
    return 0;
}
