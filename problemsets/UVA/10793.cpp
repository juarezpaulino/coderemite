/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

int G[110][110];

int main() {

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        printf("Map %d: ", t);
        int N, M;
        scanf("%d %d", &N, &M);
        for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) G[i][j] = (i==j) ? 0 : (1<<29)-(i*N+j);
        while (M--) {
            int u, v, c;
            scanf("%d %d %d", &u, &v, &c);
            G[u][v] = G[v][u] = min(G[u][v], c);
        }
        for (int k = 1; k <= N; k++) for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++)
            G[i][j] = min(G[i][j],G[i][k]+G[k][j]);
        int ret = 1<<29;
        for (int k = 1; k <= N; k++) {
            int d = G[k][1];
            bool ok = 1;
            for (int j = 2; j <= 5; j++) if (G[k][j]!=d) { ok = 0; break; }
            if (!ok) continue;
            for (int j = 6; j <= N; j++) d = max(d, G[k][j]);
            ret = min(ret, d);
        }
        if (ret > 1<<28) puts("-1");
        else printf("%d\n", ret);
    }

    return 0;
}
