/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

struct triple { int u, v, c; };

vector<int> adj[10101], cost[10101];
int D[10101];
int ret;

int dfs(int u) {
    int ans = u, r = D[u];
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (D[v]==-1) {
            D[v] = D[u]+cost[u][i];
            int w = dfs(v);
            if (D[w] > r) r = D[w], ans = w;
        }
    }
    ret = max(ret, r);
    return ans;
}

int main() {

    char S[10101];
    while (1) {
        int N = 0;
        map<int,int> mapa;
        vector<triple> input;
        bool ok = 1;
        while (1) {
            if (!gets(S)) { ok = 0; break; }
            if (*S == 0) break;
            istringstream is(S);
            int u, v, d;
            is >> u >> v >> d;
            if (!mapa.count(u)) mapa[u] = N++;
            if (!mapa.count(v)) mapa[v] = N++;
            u = mapa[u];
            v = mapa[v];
            input.push_back((triple){u,v,d});
        }
        if (!ok && !N) break;
        if (!N) { puts("0"); gets(S); continue; }
        for (int i = 0; i < N; i++) adj[i].clear(), cost[i].clear(), D[i] = -1;
        for (int i = 0; i < input.size(); i++) {
            int u = input[i].u, v = input[i].v, c = input[i].c;
            adj[u].push_back(v); cost[u].push_back(c);
            adj[v].push_back(u); cost[v].push_back(c);
        }
        ret = D[0] = 0; int u = dfs(0);
        for (int i = 0; i < N; i++) D[i] = -1;
        ret = D[u] = 0; int v = dfs(u);
        printf("%d\n", ret);
        if (!ok) break;
    }

    return 0;
}
