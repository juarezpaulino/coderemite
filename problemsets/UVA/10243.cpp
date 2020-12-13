/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>

using namespace std;

int N;
vector<int> adj[1010];
int vis[1010], DP[1010][2], id = 1;

void dfs(int u)
{
    vis[u] = id;
    DP[u][0] = 0;
    DP[u][1] = 1;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (vis[v] != id) {
            dfs(v);
            DP[u][0] += DP[v][1];
            DP[u][1] += min(DP[v][0], DP[v][1]);
        }
    }
}


int main() {

    while (scanf("%d", &N) != EOF) {
        if (!N) break;
        for (int i = 0; i < N; i++) {
            adj[i].clear();
            int m, v;
            scanf("%d", &m);
            while (m--) {
                scanf("%d", &v);
                v--;
                adj[i].push_back(v);
            }
        }
        dfs(0);
        int ret;
        if (N == 1) ret = 1;
        else ret = min(DP[0][0], DP[0][1]);
        printf("%d\n", ret);
        id++;
    }

    return 0;
}
