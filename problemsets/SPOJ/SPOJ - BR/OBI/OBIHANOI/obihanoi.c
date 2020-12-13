#include <stdio.h>

int main() {
    int sol[31];
    int n; register int k; for (k = 1; k <= 30; k++) sol[k] = (1<<k)-1;
    k = 1;
    while (scanf("%d", &n) && n) {
        printf("Teste %d\n%d\n\n", k++, sol[n]);
    }
    return 0;
}

