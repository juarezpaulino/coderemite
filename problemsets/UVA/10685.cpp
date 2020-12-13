/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <map>
#include <vector>
#include <string>

using namespace std;

vector<int> adj[5050];
int V[5050];

int dfs(int u) {
    V[u] = 1;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (!V[v]) V[u] += dfs(v);
    }
    return V[u];
}


int main() {

    int C, R;
    while (scanf("%d %d", &C, &R) && (C|R)) {
        map<string, int> mapa;
        char S[1010], T[1010];
        for (int i = 0; i < C; i++) {
            scanf("%s", S);
            mapa[S] = i;
            V[i] = 0;
            adj[i].clear();
        }
        for (int i = 0; i < R; i++) {
            scanf("%s %s", S, T);
            int s = mapa[S], t = mapa[T];
            adj[s].push_back(t);
            adj[t].push_back(s);
        }
        int ret = 0;
        for (int i = 0; i < C; i++) if (!V[i]) ret = max(ret, dfs(i));
        printf("%d\n", ret);
    }

    return 0;
}
