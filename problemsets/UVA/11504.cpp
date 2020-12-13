/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

vector<int> adj[101010];
stack<int> scc;
int N;
int ret;
int nord;
int vis[101010], L[101010];
char in[101010];
int comp[101010], ncomp;
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

void SCC() {
    ret = 0;
    nord = 0;
    ncomp = 0;
    act.clear();
    for (int i = 1; i <= N; i++) in[i] = L[i] = vis[i] = 0, comp[i] = -1;
    for (int i = 1; i <= N; i++) if (!vis[i]) dfs(i);
    for (int i = 0; i < act.size(); i++) if (act[i]) ret++;
}



int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        int M;
        scanf("%d %d", &N, &M);
        for (int i = 1; i <= N; i++) adj[i].clear();
        while (M--) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
        }
        SCC();
        printf("%d\n", ret);
    }

    return 0;
}
