/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

const int VT = 110;

long long total;
int adj[VT][VT], deg[VT];
int dist[VT], prev[VT];
int cap[VT][VT], flow[VT][VT], cost[VT][VT];
int vis[VT], id = 1;

inline int cf(int i, int j) {
    if (flow[j][i]) return flow[j][i];
    else return cap[i][j] - flow[i][j];
}

inline int costf(int i, int j) {
    if (flow[j][i]) return -cost[j][i];
    else return cost[i][j];
}

inline void pushf(int i, int j, int x) {
    total += costf(i, j) * (long long)x;
    if (flow[j][i]) flow[j][i] -= x;
    else flow[i][j] += x;
}

int augment(int n, int s, int t) {
    for (int i = 0; i < n; i++) deg[i] = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (cap[i][j])
        adj[i][deg[i]++] = j;
    bool ok = vis[s] = ++id;
    dist[s] = 0;
    while (ok) {
        ok = 0;
        for (int i = 0; i < n; i++) if (vis[i]==id) for (int k = 0; k < deg[i]; k++) {
            int j = adj[i][k];
            if (!cf(i, j)) continue;
            if (vis[j]!=id || dist[i]+costf(i,j) < dist[j]) {
                ok = vis[j] = id;
                dist[j] = dist[i] + costf(i,j);
                prev[j] = i;
            }
        }
    }

    if (vis[t]!=id) return 0;

    int bot = cf(prev[t],t);
    for (int i = t; i != s; i = prev[i]) bot = min(bot, cf(prev[i],i));
    for (int i = t; i != s; i = prev[i]) pushf(prev[i], i, bot);
    return bot;
}

int mcmf(int n, int s, int t) {
    for (int i = 0; i < n; i++) for (int j = i; j < n; j++)
        flow[i][j] = flow[j][i] = 0;
    int ret = total = 0;
    int x; while (x = augment(n,s,t)) ret += x;
    return ret;
}


int main() {

    int N, M;
    while (scanf("%d", &N) && N) {
        scanf("%d", &M);
        N++;
        for (int i = 0; i < N; i++) for (int j = i; j < N; j++) cap[i][j] = cap[j][i] = 0;
        while (M--) {
            int u, v, d;
            scanf("%d %d %d", &u, &v, &d);
            u--; v--;
            cap[u][v] = cap[v][u] = 1;
            cost[u][v] = cost[v][u] = d;
        }
        cap[N-1][0] = 2; cost[N-1][0] = 0;
        if (mcmf(N,N-1,N-2)!=2) puts("Back to jail");
        else printf("%d\n", total);
    }

    return 0;
}
