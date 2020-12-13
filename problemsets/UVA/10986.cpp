/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cstring>

using namespace std;

typedef pair<int,int> PII;

int main() {

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int N, M, a, b;
        scanf("%d %d %d %d", &N, &M, &a, &b);
        vector<int> adj[20202], cost[20202];
        for (int i = 0; i < M; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            adj[u].push_back(v); cost[u].push_back(w);
            adj[v].push_back(u); cost[v].push_back(w);
        }
        priority_queue<PII, vector<PII>, greater<PII> > q;
        char V[20202] = {0};
        int D[20202];
        memset(D, 0x3F, sizeof(D));
        q.push(PII(D[a] = 0,a));
        while (!q.empty()) {
            int u = q.top().second; q.pop();
            if (V[u]) continue;
            V[u] = 1;
            if (u == b) break;
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i], w = cost[u][i];
                if (D[v] > D[u]+w) q.push(PII(D[v] = D[u]+w, v));
            }
        }
        printf("Case #%d: ", t);
        if (D[b]==0x3F3F3F3F) puts("unreachable");
        else printf("%d\n", D[b]);
    }

    return 0;
}
