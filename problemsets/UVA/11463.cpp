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
        printf("Case %d: ", t);
        int N, M;
        scanf("%d %d", &N, &M);
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) G[i][j] = (i==j) ? 0 : (1<<29)-(i*N+j);
        while (M--) {
            int u, v;
            scanf("%d %d", &u, &v);
            G[u][v] = G[v][u] = 1;
        }
        for (int k = 0; k < N; k++) for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
            G[i][j] = min(G[i][j],G[i][k]+G[k][j]);
        int u, v;
        scanf("%d %d", &u, &v);
        int ret = -1;
        for (int i = 0; i < N; i++) ret = max(ret,G[u][i]+G[i][v]);
        printf("%d\n", ret);
    }

    return 0;
}
