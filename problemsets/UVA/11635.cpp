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

int N;
vector<int> adj[10101], cost[10101];
vector<int> badj[105];
int vis[10101], marc[105][10101], dist[10101], H[105];
int id = 1;

int main() {

    while (scanf("%d", &N) != EOF) {
        if (!N) break;
        int h, m;
        scanf("%d", &h);
        for (int i = 0; i < h; i++) scanf("%d", H+i), H[i]--;
        H[h] = 0; H[h+1] = N-1;
        h += 2;
        for (int i = 0; i < N; i++) adj[i].clear(), cost[i].clear();
        for (int i = 0; i < h; i++) badj[i].clear();
        scanf("%d", &m);
        while (m--) {
            int x, y, c;
            scanf("%d %d %d", &x, &y, &c);
            x--; y--;
            adj[x].push_back(y); cost[x].push_back(c);
            adj[y].push_back(x); cost[y].push_back(c);
        }

        for (int i = 0; i < h; i++) {
            int s = H[i];
            priority_queue<pair<int,int> > q;
            q.push(make_pair(-(dist[s] = 0), s));
            vis[s] = id;
            while (!q.empty()) {
                int u = q.top().second; q.pop();
                if (dist[u] > 600) break;
                if (marc[i][u] == id) continue;
                marc[i][u] = id;
                for (int i = 0; i < adj[u].size(); i++) {
                    int v = adj[u][i], c = cost[u][i];
                    if (vis[v] != id || (dist[u]+c < dist[v])) {
                        vis[v] = id;
                        q.push(make_pair(-(dist[v] = dist[u]+c), v));
                    }
                }
            }
        }

        for (int i = 0; i < h; i++) for (int j = i+1; j < h; j++) {
            if (marc[i][H[j]] == id) {
                badj[i].push_back(j);
                badj[j].push_back(i);
            }
        }

        id++;
        queue<int> q;

        if (badj[h-1].size() == 0) goto OUT;

        q.push(h-2);
        vis[h-2] = id;
        dist[h-2] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int i = 0; i < badj[u].size(); i++) {
                int v = badj[u][i];
                if (vis[v] != id) {
                    vis[v] = id;
                    dist[v] = dist[u]+1;
                    if (v == h-1) goto OUT;
                    q.push(v);
                }
            }
        }

OUT:
        if (vis[h-1] != id) puts("-1");
        else printf("%d\n", dist[h-1]-1);

        id++;
    }

    return 0;
}
