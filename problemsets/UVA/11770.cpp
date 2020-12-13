/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

int N;
vector<int> adj[10101];
stack<int> scc;
vector<vector<int> > ret;
int nord, ncomp;
int vis[10101], L[10101], comp[10101];
char in[10101];
vector<bool> act;

void dfs(int u) {
    vis[u] = L[u] = ++nord;
    scc.push(u); in[u] = 1;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (!vis[v]) dfs(v);
        if (in[v]) L[u] = min(L[u], L[v]);
        else act[comp[v]] = 0;
    }
    if (vis[u]==L[u]) {
        act.push_back(1);
        while (!scc.empty() && scc.top() != u) {
            comp[scc.top()] = ncomp; in[scc.top()] = 0; scc.pop();
        }
        comp[u] = ncomp; in[u] = 0; scc.pop();
        ncomp++;
    }
}

int SCC() {
    ncomp = nord = 0;
    act.clear();
    for (int i = 1; i <= N; i++) in[i] = vis[i] = L[i] = 0, comp[i] = -1;
    for (int i = 1; i <= N; i++) if (!vis[i]) dfs(i);
    int ret = 0;
    for (int i = 0; i < act.size(); i++) ret += act[i];
    return ret;
}


int main() {

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int M;
        scanf("%d %d ", &N, &M);
        for (int i = 1; i <= N; i++) adj[i].clear();
        while (M--) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
        }
        int ret = SCC();
        printf("Case %d: %d\n", t, ret);
    }

    return 0;
}
