/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int,int> pii;

int N, M, K;
int vis[2020], D[2020], id = 1;
vector<int> adj[2020];
char air[2020];

int main() {

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        printf("Case %d:\n", t);
        scanf("%d %d %d", &N, &M, &K);
        for (int i = 1; i <= N; i++) adj[i].clear(), air[i] = 0;
        for (int i = 0; i < K; i++) { int x; scanf("%d", &x); air[x] = 1; }
        while (M--) {
            int u, v; scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int Q;
        scanf("%d", &Q);
        while (Q--) {
            int u, v; scanf("%d %d", &u, &v);
            if (u == v) { puts("0"); continue; }
            priority_queue<pii> q;
            q.push(pii(-(D[u]=(air[u]?0:1)),u));
            vis[u]=id;
            while (!q.empty()) {
                int u = q.top().second, d = -q.top().first;
                q.pop();
                if (d > D[u]) continue;
                if (u == v) break;
                for (int i = 0; i < adj[u].size(); i++) {
                    int v = adj[u][i];
                    int d = D[u]+(air[v]?0:1);
                    if (vis[v]!=id || (vis[v]==id && D[v] > d)) {
                        vis[v] = id;
                        q.push(pii(-(D[v]=d),v));
                    }
                }
            }
            if (vis[v]!=id) puts("-1");
            else printf("%d\n", D[v]);
            id++;
        }
        putchar('\n');
    }

    return 0;
}
