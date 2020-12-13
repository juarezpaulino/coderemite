/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

const int MAXV = 55;

int N, M;
int cap[MAXV][MAXV];
int adj[MAXV][MAXV], deg[MAXV];
int prev[MAXV];

int dinic(int N, int S, int T) {
    int flow = 0;
    for (int i = 0; i < N; i++) deg[i] = 0;
    for (int i = 0; i < N; i++) for (int j = i+1; j < N; j++) if (cap[i][j] || cap[j][i])
        adj[i][deg[i]++] = j, adj[j][deg[j]++] = i;
    while(1) {
        for (int i = 0; i < N; i++) prev[i] = -1;
        queue<int> q;
        q.push(S); prev[S] = -2;
        while(!q.empty() && prev[T]==-1) {
            int u = q.front(), v; q.pop();
            for (int i = 0; i < deg[u]; i++) if (prev[v=adj[u][i]]==-1 && cap[u][v])
                q.push(v), prev[v] = u;
        }
        if (prev[T] == -1) break;
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

int main() {

    while (scanf("%d %d", &N, &M) && (N|M)) {
        for (int i = 0; i < N; i++) for (int j = i+1; j < N; j++) cap[i][j] = cap[j][i] = 0;
        while (M--) {
            int u, v, c;
            scanf("%d %d %d", &u, &v, &c);
            cap[u-1][v-1] = cap[v-1][u-1] = c;
        }
        dinic(N,0,1);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) if (i != j) {
                if ((cap[i][j]||cap[j][i]) && prev[i]!=-1 && prev[j]==-1) printf("%d %d\n", i+1, j+1);
            }
        }
        puts("");
    }

    return 0;
}
