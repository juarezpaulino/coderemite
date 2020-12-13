#include <stdio.h>


int main() {

    int N, C, K;
    int vector[102];
    int i, aux, min;
    
    scanf("%d %d %d", &N, &C, &K);
    while ((N != 0) && (C != 0) && (K != 0)) {
        for (i = 0; i <= K; i++)
            vector[i] = 0;
        
        for (i = 0; i < N*C; i++) {
            scanf("%d", &aux);
            vector[aux]++;
        }
        
        min = vector[1];
        for (i = 1; i <= K; i++)
            if (vector[i] < min)
                min = vector[i];
        
        aux = 0;
        for (i = 1; i <= K; i++)
            if (vector[i] == min){
                if (aux != 0)
                    putchar(' ');
                printf("%d", i);
                aux = 1;
            }
        putchar('\n');

        
        scanf("%d %d %d", &N, &C, &K);
    }
    
    
    return 0;
}
