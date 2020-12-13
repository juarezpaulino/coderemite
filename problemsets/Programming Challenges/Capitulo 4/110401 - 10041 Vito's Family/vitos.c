/* Vito1s Family */

#include <stdio.h>
#include <stdlib.h>

int compare(const void *x, const void *y) {
    
    return(*(int *)x - *(int *)y);
}

int main() {

    int cases, relatives, streets[502], sum;
    int i;
    
    scanf("%d", &cases);    
    while (cases) {
        
        sum = 0;
        
        scanf("%d", &relatives);
        for (i = 0; i < relatives; i++)
            scanf("%d", &streets[i]);
        
        qsort(streets, relatives, sizeof(int), compare);

        for (i = 1; i <= relatives/2; i++) {
            if (((relatives/2) - i) >= 0)
                sum += streets[relatives/2] - streets[(relatives/2) - i];
            if (((relatives/2) + i) < relatives)
                sum += streets[(relatives/2) + i] - streets[relatives/2];
        }
        
        printf("%d\n", sum);
        
        cases--;
    }

    return 0;
}
