/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int C, L;
int S, E, D;
vector<int> adj[110];
char DP[110][210];

char go(int u, int d) {
    char &ret = DP[u][d];
    if (ret != -1) return ret;
    ret = 0;
    if (d == D) {
        if (u == E) return ret = 1;
        return ret;
    }
    for (int i = 0; i < adj[u].size(); i++) ret = max(ret, go(adj[u][i], d+1));
    return ret;
}

int main() {

    while (scanf("%d %d", &C, &L)) {
        if (!(C|L)) break;
        for (int i = 0; i <= C; i++) adj[i].clear();
        for (int i = 0; i < L; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        scanf("%d %d %d", &S, &E, &D);
        for (int i = 0; i <= C; i++) for (int j = 0; j <= D; j++) DP[i][j] = -1;
        char ret = go(S,0);
        if (ret) puts("Yes, Teobaldo can travel.");
        else puts("No, Teobaldo can not travel.");
    }

    return 0;
}
