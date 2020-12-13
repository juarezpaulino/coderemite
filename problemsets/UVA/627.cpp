/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <sstream>

using namespace std;

int N;
int dist[300], par[300];
vector<int> adj[300];
map<int,int> mapa;
map<int,int> rmapa;

void retrieve(int u, int s) {
    if (u == s) { printf("%d", rmapa[s]); return; }
    else { retrieve(par[u],s); printf(" %d", rmapa[u]); }
}

int main() {

    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i < N; i++) adj[i].clear();
        mapa.clear(); rmapa.clear();

        char S[1010];
        for (int i = 0; i < N; i++) {
            char c;
            int x, y, u, v;
            scanf("%s", S);

            istringstream is(S);
            is >> x >> c;
            if (mapa.count(x)) u = mapa[x];
            else { y = mapa.size(); u = mapa[x] = y; rmapa[u] = x; }
            while (is >> y) {
                is >> c;
                if (mapa.count(y)) v = mapa[y];
                else { x = mapa.size(); v = mapa[y] = x; rmapa[v] = y; }
                adj[u].push_back(v);
                if (c != ',') break;
            }
        }

        printf("-----\n");
        int M;
        scanf("%d", &M);
        while (M--) {
            int x, y, s, t;
            scanf("%d %d", &x, &y);
            s = mapa[x]; t = mapa[y];
            queue<int> q;
            for (int i = 0; i < N; i++) dist[i] = 1<<30;
            dist[s] = 0;
            q.push(s);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                if (u == t) break;
                for (int i = 0; i < adj[u].size(); i++) {
                    int v = adj[u][i];
                    if (dist[v] == 1<<30) {
                        par[v] = u;
                        dist[v] = dist[u]+1;
                        if (v == t) goto OUT;
                        q.push(v);
                    }
                }
            }
OUT:
            if (dist[t] == 1<<30) puts("connection impossible");
            else { retrieve(t, s); putchar('\n'); }
        }
    }

    return 0;
}
