/* Marbles */

#include <stdio.h>


int main() {

    int c1, c2, n1, n2, n, i, box1, box2, aux1, aux2, cost1, cost2;
    char found;
    
    while (scanf("%d", &n)) {
    
        if (n == 0)
            break;
            
        scanf("%d %d", &c1, &n1);
        scanf("%d %d", &c2, &n2);
        
        found = 0;
        for (i = n/n1; i >= 0; i--)
            if (!((n - (i * n1)) % n2)) {
                box1 = i;
                box2 = (n - (i * n1))/n2;
                cost1 = (box1 * c1) + (box2 * c2);
                found = 1;
                break;
            }
        
        if (!found) {
            printf("failed\n");
            continue;
        }
        
        for (i = n/n2; i >= 0; i--)
            if (!((n - (i * n2)) % n1)) {
                aux2 = i;
                aux1 = (n - (i * n2))/n1;
                cost2 = (aux1 * c1) + (aux2 * c2);
                break;
            }
        
        if (cost1 < cost2)
            printf("%d %d\n", box1, box2);
        else
            printf("%d %d\n", aux1, aux2);
    }

    return 0;
}
