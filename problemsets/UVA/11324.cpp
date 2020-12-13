/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int N, M;
vector<int> adj[1010];
int D[1010];

stack<int> scc;
int nord, ncomp;
vector<vector<int> > compNo;
int vis[1010], L[1010], comp[1010];
char in[1010];

void dfs(int u) {
    vis[u] = L[u] = ++nord;
    scc.push(u); in[u] = 1;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (!vis[v]) dfs(v);
        if (in[v]) L[u] = min(L[u], L[v]);
    }
    if (vis[u]==L[u]) {
        vector<int> r;
        while (!scc.empty() && scc.top() != u) {
            comp[scc.top()] = ncomp; r.push_back(scc.top()); in[scc.top()] = 0; scc.pop();
        }
        comp[u] = ncomp; r.push_back(u); in[u] = 0; scc.pop();
        reverse(r.begin(), r.end());
        compNo.push_back(r);
        ncomp++;
    }
}

void SCC() {
    ncomp = nord = 0;
    compNo.clear();
    for (int i = 1; i <= N; i++) in[i] = vis[i] = L[i] = 0, comp[i] = -1;
    for (int i = 1; i <= N; i++) if (!vis[i]) dfs(i);
}

int go(int k) {
    int &ret = D[k];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0; i < compNo[k].size(); i++) {
        int u = compNo[k][i];
        for (int j = 0; j < adj[u].size(); j++) {
            int v = comp[adj[u][j]];
            if (v != k) ret = max(ret, go(v));
        }
    }
    ret += compNo[k].size();
    return ret;
}


int main() {

    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &M);
        for (int i = 0; i <= N; i++) adj[i].clear(), D[i] = -1;
        while (M--) {
            int u, v; scanf("%d %d", &u, &v);
            adj[u].push_back(v);
        }
        SCC();
        int ret = 0;
        for (int i = 0; i < ncomp; i++) ret = max(ret, go(i));
        printf("%d\n", ret);
    }

    return 0;
}
