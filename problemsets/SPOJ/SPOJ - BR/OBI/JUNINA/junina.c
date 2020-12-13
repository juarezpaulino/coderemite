#include <stdio.h>

int n, g[20][20];
int comissao[20], max;

void junina(int pos, int k) {
    register int i;
    if (pos == n) { if (k > max) max = k; return; }
    if (k + n - pos <= max) return;
    for (i = 0; i < pos && !(g[pos][i] && comissao[i]); i++);
    if (i == pos) { comissao[pos] = 1; junina(pos+1, k+1); comissao[pos] = 0; }
    junina(pos+1, k);
}


int main() {

    register int i, j, k = 1;
    int x;

    while (scanf("%d", &n) && n) {
        for (i = 0; i < n; i++) { for (j = 0; j < n; j++) g[i][j] = 0; comissao[i] = 0; }
        for (i = 0; i < n; i++) { while (scanf("%d", &x) && x) g[i][x-1] = g[x-1][i] = 1; }
        max = 0; junina(0, 0);
        printf("Teste %d\n%d\n\n", k++, max);
    }  
    
    return 0;
}

