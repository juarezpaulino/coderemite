/* The Largest/Smallest Box */

#include <stdio.h>
#include <math.h>

#define EPSILON 0.0000001

int main() {
    
    double L, W;
    double larger;
    
    while (scanf("%lf %lf", &L, &W) != EOF) {
            
        larger = (W + L - sqrt((L*L) - (W*L) + (W*W)))/6.0;
        
        if (W > L)
            printf("%.3lf 0.000 %.3lf\n", larger+EPSILON, L*0.5+EPSILON);
        else
            printf("%.3lf 0.000 %.3lf\n", larger+EPSILON, W*0.5+EPSILON);
    }

    return 0;
}
