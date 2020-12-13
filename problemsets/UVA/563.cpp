/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

const int MAXV = 5050;
int cap[MAXV][MAXV];
int adj[MAXV][MAXV], deg[MAXV];
int prev[MAXV];
int dinic(int N, int S, int T) {
    int flow = 0;
    for (int i = 0; i < N; i++) deg[i] = 0;
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


char mapa[55][55];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        int M, N, B;
        scanf("%d %d %d", &N, &M, &B);
        memset(mapa,0,sizeof(mapa));
        for (int i = 0; i < 2*M*N+2; i++) for (int j = 0; j < 2*M*N+2; j++) cap[i][j] = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                cap[2*(i*N+j)][2*(i*N+j)+1] = 1;
                for (int k = 0; k < 4; k++) {
                    int ny = i+dy[k], nx = j+dx[k];
                    if (ny < 0 || nx < 0 || ny >= M || nx >= N)
                        cap[2*(i*N+j)+1][2*M*N+1] = 1;
                    else
                        cap[2*(i*N+j)+1][2*(ny*N+nx)] = 1;
                }
            }
        }
        bool ok = 1;
        for (int i = 0; i < B; i++) {
            int y, x; scanf("%d %d", &x, &y); x--; y--;
            if (mapa[y][x]) ok = 0;
            mapa[y][x] = 1;
            cap[2*M*N][2*(y*N+x)] = 1;
        }
        if (!ok) puts("not possible");
        else if (dinic(2*M*N+2, 2*M*N, 2*M*N+1) == B) puts("possible");
        else puts("not possible");
    }

    return 0;
}
