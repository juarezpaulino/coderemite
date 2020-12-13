/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int N, M;
vector<pair<int,int> > U;
vector<int> adj[505];
int vis[505];

int dfs(int u) {
    vis[u] = 1;
    int ret = 0;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (!vis[v]) ret += dfs(v);
    }
    return ret+1;
}


int main() {

    while (scanf("%d %d", &N, &M)) {
        if (!(N|M)) break;
        int u, v, c, best;
        scanf("%d %d %d", &u, &v, &best);
        U.clear();
        U.push_back(make_pair(u,v));
        for (int i = 1; i < M; i++) {
            scanf("%d %d %d", &u, &v, &c);
            if (c == best) U.push_back(make_pair(u,v));
            else if (c > best) {
                best = c;
                U.clear();
                U.push_back(make_pair(u,v));
            }
        }
        for (int i = 1; i <= N; i++) adj[i].clear(), vis[i] = 0;
        for (int i = 0; i < U.size(); i++) {
            int u = U[i].first, v = U[i].second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ret = 1;
        for (int i = 1; i <= N; i++) if (!vis[i])
            ret = max(ret, dfs(i));
        printf("%d\n", ret);
    }

    return 0;
}
