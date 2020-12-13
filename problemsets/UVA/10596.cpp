/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>

using namespace std;

int N, R;
vector<int> adj[202];
int vis[202];

void dfs(int u) {
    vis[u] = 1;
    for (int i = 0; i < adj[u].size(); i++) if (!vis[adj[u][i]]) dfs(adj[u][i]);
}


int main() {

    while (scanf("%d %d", &N, &R) != EOF) {
        for (int i = 0; i < N; i++) adj[i].clear(), vis[i] = 0;
        for (int i = 0; i < R; i++) {
            int c1, c2;
            scanf("%d %d", &c1, &c2);
            adj[c1].push_back(c2);
            adj[c2].push_back(c1);
        }
        bool ok = 1, con = 1;
        for (int i = 0; ok && i < N; i++) if (adj[i].size()%2) ok = 0;
        dfs(0); for (int i = 0; ok && con && i < N; i++) if (!vis[i]) con = 0;
        if (ok && con) puts("Possible");
        else puts("Not Possible");
    }

    return 0;
}
