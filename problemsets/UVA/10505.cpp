/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int N;
vector<int> adj[210];
char vis[210];
int A, B;

bool dfs(int u, int c) {
    vis[u] = c;
    c ? A++ : B++;
    bool ok = 1;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (vis[v]== c) ok = 0;
        if (vis[v]==-1) ok &= dfs(v,1-c);
    }
    return ok;
}

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) adj[i].clear(), vis[i] = -1;
        for (int i = 1; i <= N; i++) {
            int m, x; scanf("%d", &m);
            for (int j = 0; j < m; j++) {
                scanf("%d", &x);
                adj[i].push_back(x);
                adj[x].push_back(i);
            }
        }
        int ret = 0;
        for (int i = 1; i <= N; i++) if (vis[i]==-1) {
            A = B = 0;
            if (dfs(i,0)) ret += max(A,B);
        }
        printf("%d\n", ret);
    }

    return 0;
}
