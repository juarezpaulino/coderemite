/* Triangular Sum */

#include <stdio.h>

int N, n;
int W[301];


int main() {
    
    int i;
 
    W[0] = 0;
    for (i = 1; i <= 300; i++) W[i] = W[i-1]+i*(((i+2)*(i+1))/2);

    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        scanf("%d", &n);   
        printf("%d %d %d\n", i, n, W[n]);
    }
    
    return 0;
}
