/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

const int MAXC = 10;
const int MAXD = 1001;

vector<int> adj[MAXC*MAXD], cost[MAXC*MAXD];


int main() {

    int n, k;
    int t = 1;
    while (scanf("%d %d", &n, &k) != EOF) {
        if (!(k|n)) break;
        for (int i = 0; i < n*MAXD; i++) adj[i].clear(), cost[i].clear();
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int d; scanf("%d", &d);
            for (int l = 0; l < d; l++) {
                int c; scanf("%d", &c);
                if (c == 0) continue;
                for (int x = l; x < MAXD; x+=d) {
                    int u = i*MAXD + x,
                        v = j*MAXD + x+1;
                    adj[u].push_back(v);
                    cost[u].push_back(c);
                }
            }
        }

        priority_queue<pair<int,int> > q;
        int marc[n*MAXD];
        int dist[n*MAXD];
        for (int i = 0; i < n*MAXD; i++) dist[i] = 1<<30, marc[i] = 0;
        q.push(make_pair(-(dist[0] = 0), 0));
        while (!q.empty()) {
            int u = q.top().second; q.pop();
            if (marc[u]) continue;
            marc[u] = 1;
            if (u == (n-1)*MAXD+k) break;
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i], c = cost[u][i];
                if (dist[v] > dist[u]+c)
                    q.push(make_pair(-(dist[v] = dist[u]+c), v));
            }
        }

        printf("Scenario #%d\n", t++);
        if (dist[(n-1)*MAXD+k] == 1<<30) puts("No flight possible.\n");
        else printf("The best flight costs %d.\n\n", dist[(n-1)*MAXD+k]);
    }

    return 0;
}
