#include <stdio.h>

char g[7][7];
int deg[7], marc[7];

void dfs(int v) {
    register int i;
    marc[v] = 1; for (i = 0; i < 7; i++) if (g[v][i] && !marc[i]) dfs(i);
}

int connect() {
    register int i;
    for (i = 0; i < 7; i++) marc[i] = 0;
    for (i = 0; i < 7 && !deg[i]; i++); dfs(i);
    for (i = 0; i < 7; i++)  if (deg[i] && !marc[i]) return 0;
    return 1;
}


int main() {
   
    int register i, j, imp, k = 1;
    int n, x, y;
   
    while (scanf("%d", &n) && n) {
        for (i = 0; i < 7; i++) { for (j = 0; j < 7; j++) g[i][j] = 0; deg[i] = 0; }
        for (i = 0; i < n; i++) {
            scanf("%d %d", &x, &y); deg[x]++; deg[y]++; g[x][y] = g[y][x] = 1;
        }
        for (imp = i = 0; i < 7; i++) imp += deg[i]&1;
        if ((imp > 2) || (!connect())) printf("Teste %d\nnao\n\n", k++);
        else printf("Teste %d\nsim\n\n", k++);
    }
    
    return 0;
}

