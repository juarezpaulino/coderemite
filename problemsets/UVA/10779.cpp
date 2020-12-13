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
#include <set>

using namespace std;

const int MAXV = 530;

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


int main() {

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        printf("Case #%d: ", t);
        int N, M;
        scanf("%d %d", &N, &M);
        for (int i = 0; i < 2*N*M+2; i++) for (int j = 0; j < 2*N*M+2; j++) cap[i][j] = 0;
        set<int> bob;
        for (int k = 0; k < N; k++) {
            int u[30] = {0};
            int m; scanf("%d", &m);
            while (m--) {
                int x; scanf("%d", &x); x--;
                u[x]++;
                if (k == 0) bob.insert(x);
            }
            if (k==0) {
                for (int i = 0; i < M; i++) {
                    if (u[i] > 1) cap[2*N*M][2*(k*M+i)] = u[i]-1;
                    else if (u[i]==0) cap[2*(k*M+i)+1][2*(N*M)+1] = 1;
                    cap[2*(k*M+i)][2*(k*M+i)+1] = 1<<29;
                }
            }
            else {
                for (int i = 0; i < M; i++) {
                    if (u[i]==0) {
                        cap[2*(0*M+i)+1][2*(k*M+i)] = 1;
                        cap[2*(k*M+i)][2*(k*M+i)+1] = 1;
                        for (int j = 0; j < M; j++) if (u[j]>1) {
                            cap[2*(k*M+i)+1][2*(k*M+j)] = 1;
                        }
                    }
                    else if (u[i]>1) {
                        cap[2*(k*M+i)][2*(k*M+i)+1] = u[i]-1;
                        cap[2*(k*M+i)+1][2*(0*M+i)] = u[i]-1;
                    }
                }
            }
        }
        int ret = dinic(2*N*M+2, 2*N*M, 2*N*M+1) + bob.size();
        printf("%d\n", ret);
    }

    return 0;
}
