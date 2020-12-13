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
vector<int> adj[1010];
stack<int> scc;
int nord, ncomp;
int vis[1010], L[1010];
char in[1010];

map<string,int> M;

void dfs(int u) {
    vis[u] = L[u] = ++nord;
    scc.push(u); in[u] = 1;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (!vis[v]) dfs(v);
        if (in[v]) L[u] = min(L[u], L[v]);
    }
    if (vis[u]==L[u]) {
        while (!scc.empty() && scc.top() != u) {
            in[scc.top()] = 0; scc.pop();
        }
        in[u] = 0; scc.pop();
        ncomp++;
    }
}

void SCC() {
    ncomp = nord = 0;
    for (int i = 0; i < N; i++) in[i] = vis[i] = L[i] = 0;
    for (int i = 0; i < N; i++) if (!vis[i]) dfs(i);
}


int main() {

    int T;
    while (scanf("%d %d ", &N, &T)) {
        if (!(N|T)) break;
        M.clear();
        for (int i = 0; i < N; i++) {
            char S[30];
            gets(S);
            M[S] = i;
        }
        for (int i = 0; i < N; i++) adj[i].clear();
        while (T--) {
            char U[30], V[30];
            gets(U); gets(V);
            int u = M[U], v = M[V];
            adj[u].push_back(v);
        }
        SCC();
        printf("%d\n", ncomp);
    }

    return 0;
}
