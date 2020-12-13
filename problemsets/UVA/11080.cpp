/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> adj[210];
char vis[210];
int A, B;

bool dfs(int u, int c) {
    vis[u] = c;
    (c) ? A++ : B++;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (vis[v]==c) return 0;
        if (vis[v]==-1)
            if (!dfs(v,1-c)) return 0;
    }
    return 1;
}

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &M);
        for (int i = 0; i < N; i++) adj[i].clear(), vis[i] = -1;
        while (M--) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ret = 0;
        for (int i = 0; i < N; i++) if (vis[i]==-1) {
            if (!adj[i].size()) { ret++; continue; }
            A = B = 0;
            if (!dfs(i,0)) { ret = -1; break; }
            ret += min(A, B);
        }
        printf("%d\n", ret);
    }

    return 0;
}
