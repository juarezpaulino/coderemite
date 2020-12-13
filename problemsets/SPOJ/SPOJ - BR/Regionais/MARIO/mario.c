/* Mario */

#include <stdio.h>

int n, l;
int arm[100000];


int main() {

    int i, j;
    int min;
    int d;
    
    while (scanf("%d %d", &n, &l)) {
        
        if ((!n) && (!l)) break;
        
        for (i = 0; i < l; i++) scanf("%d", &arm[i]);
        
        min = 2000000000;
        for (i = 0; i < l; i++) {
            for (j = 1; (i+j < l) && (arm[i+j] < arm[i]+n); j++);
            if ((n-j) < min) min = n-j;
            if (!min) break;
        }
        
        printf("%d\n", min);
    }
    
    return 0;
}
