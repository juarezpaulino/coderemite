/* Is This Integration */

#include <stdio.h>
#include <math.h>


int main() {
 
    double pi6 = acos(0.0)/3.0;
    double root3 = sqrt(3.0);
    double a;
    double A, B, C;
    int i;
    double calcA = 2.0*(pi6 + 0.5 - (root3/2.0));
    double calcC = 4.0*(1.0 - pi6 - (root3/4.0));
    double a2;
    
    while (scanf("%lf", &a) != EOF) {
    
        a2 = a*a;
        A = a2*calcA;
        C = a2*calcC;
        B = a2 - A - C;
        
        printf("%.3lf %.3lf %.3lf\n",  A, B, C);
    }
    
    return 0;    
}
