/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;

char input[30];

vector<int> adj[30];
stack<int> scc;
vector<string> ret;
int nord;
int vis[30], L[30], in[30];

void dfs(int u) {
    vis[u] = L[u] = ++nord;
    scc.push(u); in[u] = 1;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (!vis[v]) dfs(v);
        if (in[v]) L[u] = min(L[u], L[v]);
    }
    if (vis[u]==L[u]) {
        string r = "";
        while (!scc.empty() && scc.top() != u) {
            r += string(1, scc.top()+'A');
            in[scc.top()] = 0;
            scc.pop();
        }
        r += string(1, u+'A');
        in[u] = 0;
        scc.pop();
        //reverse(r.begin(), r.end());
        sort(r.begin(), r.end());
        ret.push_back(r);
    }
}

void SCC() {
    nord = 0;
    for (int i = 0; i < 26; i++) in[i] = vis[i] = L[i] = 0;
    for (int i = 0; i < 26; i++) if (!vis[i] && input[i]) dfs(i);
}


int main() {

    int M;
    bool f = 1;
    while (scanf("%d", &M) && M) {
        for (int i = 0; i < 26; i++) adj[i].clear(), input[i] = 0;
        while (M--) {
            char a, b, c, d, e, f;
            scanf(" %c %c %c %c %c %c ", &a, &b, &c, &d, &e, &f);
            if (f!=a) adj[f-'A'].push_back(a-'A');
            if (f!=b) adj[f-'A'].push_back(b-'A');
            if (f!=c) adj[f-'A'].push_back(c-'A');
            if (f!=d) adj[f-'A'].push_back(d-'A');
            if (f!=e) adj[f-'A'].push_back(e-'A');
            input[a-'A'] = 1;
            input[b-'A'] = 1;
            input[c-'A'] = 1;
            input[d-'A'] = 1;
            input[e-'A'] = 1;
        }
        ret.clear();
        SCC();
        sort(ret.begin(), ret.end());
        if (!f) putchar('\n');
        f = 0;
        for (int i = 0; i < ret.size(); i++) {
            for (int j = 0; j < ret[i].size(); j++) {
                if (j != 0) putchar(' ');
                putchar(ret[i][j]);
            }
            putchar('\n');
        }
    }

    return 0;
}
