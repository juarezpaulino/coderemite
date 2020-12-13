#include <stdio.h>

#define INF 0x3F3F3F3F
#define VT 101

int adj[VT][VT][VT];


int main() {

    int n, m;
    int u, v, w;
    int o, d, t;
    int i, j, l, c, k = 1, path;

    while (scanf("%d %d", &n, &m) != EOF) {
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (i == j) adj[0][i][j] = 0;
                else adj[0][i][j] = INF;
        for (i = 0; i < m; i++) {
            scanf("%d %d %d", &u, &v, &w);
            if (adj[0][u][v] > w) adj[0][u][v] = w;
        }

        for (l = 1; l <= n; l++)
            for (i = 0; i <= n; i++)
                for (j = 0; j <= n; j++)
                    if (adj[l-1][i][j] > (u = adj[l-1][i][l]+adj[l-1][l][j]))
                        adj[l][i][j] = u;
                    else adj[l][i][j] = adj[l-1][i][j];
        printf("Instancia %d\n", k++);
        scanf("%d", &c);
        for (m = 0; m < c; m++) {
            scanf("%d %d %d", &o, &d, &t);
            if (adj[t][o][d] == INF) puts("-1");
            else printf("%d\n", adj[t][o][d]);
        }
        putchar('\n');
    }

    return 0;
}
