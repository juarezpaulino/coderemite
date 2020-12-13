/* The Knights of the Round Table */

#include <stdio.h>
#include <math.h>


int main() {
    
    double a, b, c;
    double semi;
    double radius;
    
    while (scanf("%lf %lf %lf",  &a, &b, &c) != EOF) {
    
        if ((a == 0.0) || (b == 0.0) || (c == 0.0))
            printf("The radius of the round table is: 0.000\n");
        else {
            semi = (a+b+c)/2;
            radius = sqrt((semi-a)*(semi-b)*(semi-c)/semi);
            printf("The radius of the round table is: %.3lf\n", radius);
        }
    }
    
    return 0;
}
