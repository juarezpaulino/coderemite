/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int G[1010][1010];
int vis[1010], L[1010], nord;
char art[1010], brid[1010][1010];

void init(int N) {
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            G[i][j] = 0;
}

int dfs(int u, int p) {
    int ret = 0;
    vis[u] = L[u] = ++nord;
    for (int i = 1; i <= N; i++) if (G[u][i]) {
        if (!vis[i]) {
            ret++;
            dfs(i, u);
            L[u] = min(L[u], L[i]);
            if (L[i] <= vis[u]) G[i][u] = 0;
            if (L[i] >= vis[u]) art[u] = 1;
            if (L[i] > vis[u]) brid[u][i] = 1, brid[i][u] = 1;
        }
        else if (i != p) {
            L[u] = min(L[u],vis[i]);
            G[i][u] = 0;
        }
    }
    return ret;
}

void artbridge() {
    nord = 0;
    for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) brid[i][j] = 0;
    for (int i = 1; i <= N; i++) vis[i] = 0, art[i] = 0;
    for (int i = 1; i <= N; i++) if (!vis[i])
        if (dfs(i, i) < 2) art[i] = 0;
}

int main() {

    int id = 1;
    while (scanf("%d %d", &N, &M)) {
        if (!(N|M)) break;
        init(N);
        for (int i = 0; i < M; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            G[u][v] = G[v][u] = 1;
        }
        artbridge();
        printf("%d\n\n", id++);
        for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) if (G[i][j])
            printf("%d %d\n", i, j);
        puts("#");
    }

    return 0;
}
