/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 0x3F3F3F3F;

const int MAXV = 250;
int cap[MAXV][MAXV];
int adj[MAXV][MAXV], deg[MAXV];
int prev[MAXV];
int dinic(int N, int S, int T) {
    int flow = 0;
    memset(deg,0,sizeof(deg));
    for (int i = 0; i < N; i++) for (int j = i+1; j < N; j++) if (cap[i][j] || cap[j][i])
        adj[i][deg[i]++] = j, adj[j][deg[j]++] = i;
    while(1) {
        // an augmenting path
        for (int i = 0; i < N; i++) prev[i] = -1;
        queue<int> q;
        q.push(S); prev[S] = -2;
        while(!q.empty() && prev[T]==-1) {
            int u = q.front(), v; q.pop();
            for (int i = 0; i < deg[u]; i++) if (prev[v=adj[u][i]]==-1 && cap[u][v])
                q.push(v), prev[v] = u;
        }
        // done?
        if (prev[T] == -1) break;
        // try finding more paths
        for (int z = 0; z < N; z++) if (cap[z][T] && prev[z]!=-1) {
            int bot = cap[z][T];
            for (int v = z, u = prev[v]; u >= 0; v = u, u = prev[v])
                bot = min(bot,cap[u][v]);
            if (!bot) continue;
            cap[z][T]-=bot; cap[T][z]+=bot;
            for (int v = z, u = prev[v]; u >= 0; v = u, u = prev[v])
                cap[u][v]-=bot, cap[v][u]+=bot;
            flow+=bot;
        }
    }
    return flow;
}


int N, M;
int B, D;

int main() {

    while (scanf("%d", &N) != EOF) {
        memset(cap, 0, sizeof(cap));
        for (int i = 0; i < N; i++) {
            int x;
            scanf("%d", &x);
            cap[i<<1][(i<<1)+1] = x;
        }
        scanf("%d", &M);
        for (int i = 0; i < M; i++) {
            int u, v, c;
            scanf("%d %d %d", &u, &v, &c);
            u--; v--;
            cap[(u<<1)+1][v<<1] = c;
        }
        scanf("%d %d", &B, &D);
        for (int i = 0; i < B; i++) {
            int x;
            scanf("%d", &x);
            x--;
            cap[N<<1][x<<1] = INF;
        }
        for (int i = 0; i < D; i++) {
            int x;
            scanf("%d", &x);
            x--;
            cap[(x<<1)+1][(N<<1)+1] = INF;
        }
        int ret = dinic((N<<1)+2, N<<1, (N<<1)+1);
        printf("%d\n", ret);
    }

    return 0;
}
