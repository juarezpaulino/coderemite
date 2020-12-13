#include <stdio.h>
#include <stdlib.h>

int fig[8], n;
char in[8];

int cmp(int *a, int *b) { return *a-*b; }

void perm(int v[], int k) {
    int i;
    if (k == n) {
        for (i = 0; i < n-1; i++) printf("%d ", v[i]); printf("%d\n", v[i]);
        return;
    }
    for (i = 0; i < n; i++) if (!in[i]) { 
        in[i] = 1; v[k] = fig[i]; perm(v, k+1); in[i] = 0;
    }
}

int main() {
    
    int i, cmp(), v[8], c = 0;
    
    while (scanf("%d", &n)) {
        if (!n) break;
        if (c) putchar('\n');
        for (i = 0; i < n; i++) { scanf("%d", &fig[i]); in[i] = 0; }
        qsort(fig, n, sizeof(int), cmp);
        perm(v, 0);
        c = 1;
    }
    
    return 0;
}
