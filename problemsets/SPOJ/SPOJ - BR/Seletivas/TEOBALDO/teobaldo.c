#include <stdio.h>

char adj[101][101];
char v[2][101];


int main() {
    
    int c, l;
    int a, b;
    int s, e, d;
    int i, j, k, m;
    
    while (scanf("%d %d", &c, &l) != EOF) {
        if (!c && !l) break;
        memset(adj, 0, sizeof(adj));
        for (i = 0; i < l; i++) { scanf("%d %d", &a, &b); adj[a][b] = adj[b][a] = 1; }
        scanf("%d %d %d", &s, &e, &d);
        memset(v[0], 0, sizeof(v[0])); v[0][s] = 1;
        m = 1;
        for (k = 1; k <= d; k++) {
            for (j = 1; j <= c; j++) {
                v[m][j] = 0;
                for (i = 1; i<=c && !v[m][j]; i++)
                    v[m][j] |= v[m^1][i] & adj[i][j];
            }
            m ^= 1;
        }
        
        if (v[m^1][e]) puts("Yes, Teobaldo can travel.");
        else puts("No, Teobaldo can not travel.");
    }
    
    return 0;   
}
