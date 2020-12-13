/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>

using namespace std;

typedef pair<int,int> pii;

int N, M;
int marc[404], D[404];
vector<int> adj[404], cost[404];
map<string,int> mapa;

int main() {

    char S[10101], T[10101];
    while (scanf("%d %d", &N, &M) && (N|M)) {
        mapa.clear();
        for (int i = 0; i < N; i++) adj[i].clear(), cost[i].clear();
        for (int i = 0; i < N; i++) {
            scanf("%s", S);
            mapa[S] = i;
        }
        while (M--) {
            int c;
            scanf("%s %s %d", S, T, &c);
            int u = mapa[S], v = mapa[T];
            adj[u].push_back(v);
            adj[v].push_back(u);
            cost[u].push_back(c);
            cost[v].push_back(c);
        }
        for (int i = 0; i < N; i++) marc[i] = 0, D[i] = 1<<30;
        scanf("%s", S);
        int s = mapa[S];
        priority_queue<pii> q;
        q.push(pii(-(D[s] = 0),s));
        int ret = 0, tot = 0;
        while (!q.empty()) {
            int u = q.top().second; q.pop();
            if (marc[u]) continue;
            marc[u] = 1;
            ret += D[u];
            tot++;
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i], c = cost[u][i];
                if (c < D[v]) q.push(pii(-(D[v] = c),v));
            }
        }
        if (tot != N) puts("Impossible");
        else printf("%d\n", ret);
    }

    return 0;
}
