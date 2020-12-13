/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef pair<int,int> PII;

const int INF = 0x3F3F3F3F;

int N;
vector<int> adj[20], cost[20];
int par[20], dist[20], tree[20];
int s, t;

int main() {

    int T = 1;
    while (scanf("%d", &N)) {
        if (!N) break;
        for (int i = 1; i <= N; i++) {
            adj[i].clear(); cost[i].clear();
            par[i] = -1; dist[i] = INF; tree[i] = 0;
            int M; scanf("%d", &M);
            while (M--) {
                int v, c;
                scanf("%d %d", &v, &c);
                adj[i].push_back(v); cost[i].push_back(c);
            }
        }
        scanf("%d %d", &s, &t);
        priority_queue<PII> q;
        q.push(PII(-(dist[s] = 0), s));
        while (!q.empty()) {
            int u = q.top().second; q.pop();
            if (u == t) break;
            if (tree[u]) continue;
            tree[u] = 1;
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i], c = cost[u][i];
                if (dist[v] > dist[u]+c) {
                    q.push(PII(-(dist[v] = dist[u]+c), v));
                    par[v] = u;
                }
            }
        }
        vector<int> RET;
        int v = t;
        RET.push_back(v);
        while (par[v] != -1) {
            v = par[v];
            RET.push_back(v);
        }
        printf("Case %d: Path =", T++);
        for (int i = RET.size()-1; i >= 0; i--) printf(" %d", RET[i]);
        printf("; %d second delay\n", dist[t]);
    }

    return 0;
}
