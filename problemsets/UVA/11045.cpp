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
#include <string>

using namespace std;


const int MAXV = 50;
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

    int N, M, T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &M);
        for (int i = 0; i < M+8; i++) for (int j = 0; j < M+8; j++) cap[i][j] = 0;
        for (int i = 1; i <= M; i++) cap[0][i] = 1;
        for (int i = 0; i < M; i++) {
            char A[5], B[5];
            int a, b;
            scanf("%s %s", A, B);
            if (A == string("XXL")) a = M+1;
            else if (A == string("XL")) a = M+2;
            else if (A == string("L")) a = M+3;
            else if (A == string("M")) a = M+4;
            else if (A == string("S")) a = M+5;
            else if (A == string("XS")) a = M+6;
            if (B == string("XXL")) b = M+1;
            else if (B == string("XL")) b = M+2;
            else if (B == string("L")) b = M+3;
            else if (B == string("M")) b = M+4;
            else if (B == string("S")) b = M+5;
            else if (B == string("XS")) b = M+6;
            cap[i+1][a]++; cap[i+1][b]++;
        }
        for (int i = M+1; i <= M+6; i++) cap[i][M+7] = N/6;
        if (dinic(M+8, 0, M+7) == M) puts("YES");
        else puts("NO");
    }

    return 0;
}
