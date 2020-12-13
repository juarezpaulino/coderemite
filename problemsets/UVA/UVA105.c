/* The Skyline Problem */

#include <stdio.h>

#define MAXB 20001


int main() {
    
    int height[MAXB];
    int i;
    int li, hi, ri;
    int start, end, aux;
    
    for (i = 0; i < MAXB; i++)
        *(height+i) = 0;
    
    scanf("%d %d %d", &li, &hi, &ri);
    start = li*2;
    end = ri*2;
    for (i = li*2; i <= ri*2; i++)
        if (hi > *(height+i))
            *(height+i) = hi;
    while (scanf("%d %d %d", &li, &hi, &ri) != EOF) {
        if (ri*2 > end)
            end = ri*2;
        for (i = li*2; i <= ri*2; i++)
            if (hi > *(height+i))
                *(height+i) = hi;
    }
    
    aux = height[start];
    printf("%d %d ", start/2, height[start]);
    for (i = start+2; i <= end; i+=2)
        if (height[i] != aux) {
            if (height[i] > aux)
                printf("%d ", i/2);
            else
                printf("%d ", (i-2)/2);
            if ((aux != height[i-1]) && (height[i] != height[i-1]))
                printf("%d %d ", height[i-1], i/2);
            aux = height[i];
            printf("%d ", height[i]);
        }
    printf("%d ", end/2);
    printf("0\n");
    
    return 0;
}
