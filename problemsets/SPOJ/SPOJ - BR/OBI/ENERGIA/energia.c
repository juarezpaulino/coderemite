#include <stdio.h>

int adj[101][101], nadj[101], f;
char disc[101];

void dfs(int v) {
    register int i;
    disc[v] = 1; f++;
    for (i = 0; i < nadj[v]; i++) if (!disc[adj[v][i]]) dfs(adj[v][i]);
}


int main() {
    
    int n, m, x, y;
    register int i, k = 1;
    
    while (scanf("%d %d", &n, &m) && (n||m)) {
        for (i = 1; i <= n; i++) disc[i] = nadj[i] = 0;
        while (m--) {
            scanf("%d %d", &x, &y); adj[x][nadj[x]++] = y; adj[y][nadj[y]++] = x;
        }
        f = 0; dfs(1);
        if (f < n) printf("Teste %d\nfalha\n\n", k++);
        else printf("Teste %d\nnormal\n\n", k++);
    }
    return 0;
}

