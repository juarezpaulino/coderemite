/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef pair<int,int> PII;

int main() {

    int M, N;
    while (scanf("%d %d", &M, &N)) {
        if (!(M|N)) break;
        vector<int> adj[M], custo[M];
        int ret = 0;
        for (int i = 0; i < N; i++) {
            int u, v, c; scanf("%d %d %d",&u, &v, &c);
            adj[u].push_back(v), custo[u].push_back(c);
            adj[v].push_back(u), custo[v].push_back(c);
            ret += c;
        }
        int dist[M];
        memset(dist, 0x3F3F3F3F, sizeof(dist));
        priority_queue<PII> q;
        q.push(PII(dist[0] = 0, 0));
        set<int> marc;
        while (!q.empty()) {
            int u = q.top().second; q.pop();
            if (marc.count(u)) continue;
            marc.insert(u);
            ret -= dist[u];
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i], c = custo[u][i];
                if (c < dist[v]) q.push(PII(-(dist[v] = c), v));
            }
        }
        printf("%d\n", ret);
    }

    return 0;
}
