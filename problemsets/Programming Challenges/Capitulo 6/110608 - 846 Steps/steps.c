/* Steps */

#include <stdio.h>
#include <math.h>


float find_min(float diff) {
    
    float root, min;
    
    root = floor(sqrt(diff));
    min = (2 * root) - 1 + ceil((diff - (root * root))/ root);
    
    return (min);
}

int main() {

    int n, x, y;
    float steps;
    
    scanf("%d", &n);
    while (n) {
    
        scanf("%d %d", &x, &y);
        
        if (x == y)
            printf("0\n");
        else {
            steps = find_min(y-x);
            printf("%.0f\n", steps);
        }
        
        n--;
    }    
    
    return 0;
}
