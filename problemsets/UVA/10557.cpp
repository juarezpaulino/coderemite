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

vector<int> adj[110];
int vis[110], D[110];
int V[110];
int N;

void dfs(int u) {
    vis[u] = 1;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (!vis[v]) dfs(v);
    }
}

int main() {

    while (scanf("%d", &N)!=EOF) {
        if (N == -1) break;
        for (int i = 1; i <= N; i++) adj[i].clear(), vis[i] = 0, D[i] = -(1<<30);
        for (int i = 1; i <= N; i++) {
            int k;
            scanf("%d %d", V+i, &k);
            while (k--) {
                int v; scanf("%d", &v);
                adj[i].push_back(v);
            }
        }
        D[1] = 100;
        for (int k = 1; k <= N; k++) {
            for (int u = 1; u <= N; u++)
                for (int i = 0; i < adj[u].size(); i++) {
                    int v = adj[u][i];
                    if (D[u] > 0) D[v] = max(D[v], D[u]+V[v]);
                }
        }
        bool cycle = 0;
        for (int u = 1; u <= N; u++)
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i];
                if (D[u] > 0 && D[v] < D[u]+V[v]) {
                    dfs(u);
                    if (vis[N]) { cycle = 1; break; }
                }
            }
        if (cycle || D[N]>0) puts("winnable");
        else puts("hopeless");
    }

    return 0;
}
