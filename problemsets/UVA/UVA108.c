/* Maximun Sum - Maior retangulo soma na matriz nxn */

#include <stdio.h>

#define MINVALUE -1000000000
#define MAXN 100

int values[MAXN][MAXN];
int n;

int maxsum(int s[]) {
    
    int i;
    int current, max;
    
    current = max = s[0];
    for (i = 1; i < n; i++) {
        current = current>0?current+s[i]:s[i];
        if (current > max) max = current;
    }
    
    return (max);
}

int main() {
    
    int i, j, k;
    int sum[100];
    int max, aux;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &values[i][j]);

    max = MINVALUE;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++)
            sum[i] = 0;
        
        for (i = k; i < n; i++) {
            for (j = 0; j < n; j++)
                sum[j] += values[i][j];
            
            aux = maxsum(sum);
            if (aux > max) max = aux;
        }
    }
    
    printf("%d\n", max);
    
    return 0;
}
