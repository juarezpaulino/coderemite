/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
#include <queue>

using namespace std;

const int MAXV = 500;

vector<int> adj[MAXV];
int par[MAXV], disc[MAXV];

int augment(int u, int c) {
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (disc[v] != c) {
            disc[v] = c;
            if (par[v]==-1 || augment(par[v], c))
                return (par[v]=u, par[u]=v, 1);
        }
    }
    return 0;
}

int bpm(int M, int N) {
    int ret = 0;
    for (int i = 0; i < M+N; i++) disc[i] = par[i] = -1;
    for (int i = 0; i < M; i++) if (adj[i].size() && par[i]==-1) ret += augment(i, i);
    return ret;
}

vector<int> G[500];
int vis[500][500];

int main() {

    char A[1010], B[1010];
    int T; scanf("%d", &T);
    while (T--) {
        map<string,int> plug;
        int S[110];
        int N, M, K, n;

        scanf("%d", &N); n = N;
        for (int i = 0; i < N; i++) {
            scanf("%s", A); plug[A] = i;
        }

        scanf("%d", &M);
        for (int i = 0; i < M; i++) {
            scanf("%s %s", A, B);
            int x;
            if (!plug.count(B)) x = plug[B] = N++;
            else x = plug[B];
            S[i] = x;
        }
        int n2 = N;

        for (int i = 0; i < N+200; i++) G[i].clear();

        scanf("%d", &K);
        while (K--) {
            int a, b; scanf("%s %s", A, B);
            if (!plug.count(A)) a = plug[A] = N++; else a = plug[A];
            if (!plug.count(B)) b = plug[B] = N++; else b = plug[B];
            G[a].push_back(b);
        }

        for (int k = 0; k < n2; k++) {
            queue<int> q;
            q.push(k);
            for (int j = 0; j < N; j++) vis[k][j] = 0;
            vis[k][k] = 1;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int i = 0; i < G[u].size(); i++) {
                    int v = G[u][i];
                    if (!vis[k][v]) q.push(v), vis[k][v] = 1;
                }
            }
        }

        for (int i = 0; i < M+n; i++) adj[i].clear();
        for (int i = 0; i < M; i++) {
            int u = S[i];
            for (int j = 0; j < n; j++) if (vis[u][j]) adj[i].push_back(M+j), adj[M+j].push_back(i);
        }

        printf("%d\n", M-bpm(M,n));
        if (T) putchar('\n');
    }

    return 0;
}
