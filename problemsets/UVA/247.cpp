/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

vector<int> adj[30];
stack<int> scc;
vector<vector<int> > compNo;
int nord, ncomp;
int vis[30], L[30], comp[30];
char in[30];

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
            comp[scc.top()] = ncomp;
            r.push_back(scc.top());
            in[scc.top()] = 0;
            scc.pop();
        }
        comp[u] = ncomp;
        r.push_back(u);
        in[u] = 0;
        scc.pop();
        reverse(r.begin(), r.end());
        compNo.push_back(r);
        ncomp++;
    }
}

void SCC(int N) {
    ncomp = nord = 0;
    compNo.clear();
    for (int i = 0; i < N; i++)
        in[i] = vis[i] = L[i] = 0,
        comp[i] = -1;
    for (int i = 0; i < N; i++)
        if (!vis[i]) dfs(i);
}


int main() {

    int N, M;
    int id = 1;
    bool blank = 0;
    while (scanf("%d %d", &N, &M) && (N | M)) {
        map<string, int> mapa;
        vector<string> U;
        char A[100], B[100];
        int a, b;
        for (int i = 0; i < N; i++) adj[i].clear();
        for (int i = 0; i < M; i++) {
            scanf("%s %s", A, B);
            if (mapa.count(A)) a = mapa[A];
            else { a = mapa[A] = U.size(); U.push_back(A); }
            if (mapa.count(B)) b = mapa[B];
            else { b = mapa[B] = U.size(); U.push_back(B); }
            adj[a].push_back(b);
        }

        SCC(N);

        if (blank) putchar('\n');
        blank = 1;
        printf("Calling circles for data set %d:\n", id++);
        for (int i = 0; i < ncomp; i++) {
            printf("%s", U[compNo[i][0]].c_str());
            for (int j = 1; j < compNo[i].size(); j++) printf(", %s", U[compNo[i][j]].c_str());
            putchar('\n');
        }
    }

    return 0;
}
