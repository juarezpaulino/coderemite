/* Hartals */

#include <stdio.h>

char days[3653];
int hartals[105];

int main() {

    int t, n, p;
    int lost, num;
    int i, j;
    
    scanf("%d", &t);
    while (t) {
        lost = 0;
        
        scanf("%d", &n);
        days[0] = 2;
        for (i = 1; i <= n; i++) {
            if ((!(i % 7)) || ((i % 7) == 6))
                days[i] = 2;
            else
                days[i] = 0;
        }
        
        scanf("%d", &p);
        for (i = 0; i < p; i++) {
            scanf("%d", &num);
            hartals[i] = num;
        }
        
        for (i = 1; i <= n; i++) {
            if (days[i] == 0) {
                for (j = 0; (j < p) && (days[i] == 0); j++) {
                    if ((i % hartals[j]) == 0) {
                        days[i] = 1;
                        lost++;
                    }
                }
            }
        }
        
        printf("%d\n", lost);
        
        t--;
    }    
    
    return 0;
}
