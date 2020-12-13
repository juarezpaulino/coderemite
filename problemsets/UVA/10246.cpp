/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int adj[100][100], cost[100][100];

int main() {

    int id = 1;
    int C, R, Q;
    while (scanf("%d %d %d", &C, &R, &Q) && (C|R|Q)) {
        for (int i = 1; i <= C; i++) for (int j = 1; j <= C; j++) {
            adj[i][j] = (i==j) ? 0 : 1<<27;
            cost[i][j] = 1<<27;
        }
        for (int i = 1; i <= C; i++) scanf("%d", &cost[i][i]);
        while (R--) {
            int u, v, c;
            scanf("%d %d %d", &u, &v, &c);
            adj[u][v] = adj[v][u] = min(adj[u][v], c);
            cost[u][v] = cost[v][u] = max(cost[u][u], cost[v][v]);
        }
        for (int k = 1; k <= C; k++) for (int i = 1; i <= C; i++) for (int j = 1; j <= C; j++) {
            int d = adj[i][k]+adj[k][j];
            int c = max(cost[i][k],cost[k][j]);
            if (d+c < adj[i][j]+cost[i][j]) {
                adj[i][j] = d;
                cost[i][j] = c;
            }
        }
        for (int k = 1; k <= C; k++) for (int i = 1; i <= C; i++) for (int j = 1; j <= C; j++) {
            int d = adj[i][k]+adj[k][j];
            int c = max(cost[i][k],cost[k][j]);
            if (d+c < adj[i][j]+cost[i][j]) {
                adj[i][j] = d;
                cost[i][j] = c;
            }
        }
        if (id > 1) putchar('\n');
        printf("Case #%d\n", id++);
        while (Q--) {
            int u, v;
            scanf("%d %d", &u, &v);
            if (adj[u][v]+cost[u][v] >= (1<<27)) puts("-1");
            else printf("%d\n", adj[u][v]+cost[u][v]);
        }
    }

    return 0;
}
