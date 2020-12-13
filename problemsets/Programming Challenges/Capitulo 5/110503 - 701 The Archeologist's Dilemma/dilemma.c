/* The Archeologists Dilemma */

#include <stdio.h>
#include <math.h>


int main() {

    double logt =log10(2.0);
    double num;
    double e;
    double i;
    int min;
    unsigned aux;
    
    while (scanf("%lf", &num) != EOF) {
        
        for (aux = (unsigned)num, min = 1; aux/=10; min++);
        for (i = (double)min+1.0; ; i += 1.0)
            if ((e = ceil((log10(num) + i)/logt)) == floor((log10(num+1.0) + i)/logt))
                break;
        
        printf("%.0lf\n", e);
    }    
    
    return 0;
}
