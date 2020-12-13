/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <numeric>

using namespace std;

int N;
int X[100], Y[100], Z[100];

int M;
vector<int> adj[100];
int prof[100], ord[100], nord;
void dfs_topsort(int u) {
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (prof[v]==-1) {
            prof[v] = prof[u]+1;
            dfs_topsort(v);
        }
    }
    ord[--nord] = u;
}
void topsort() {
    for (int i = 0; i < M; i++) prof[i] = -1;
    nord = M;
    for (int i = 0; i < M; i++) if (prof[i]==-1) {
        prof[i] = 0;
        dfs_topsort(i);
    }
}
int longest() {
    int ret = 0;
    int DP[100];
    for (int i = 0; i < M; i++) DP[i] = Z[i];
    topsort();
    for (int i = 0; i < M; i++) {
        int u = ord[i];
        for (int j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j];
            if (DP[v] < DP[u] + Z[v]) DP[v] = DP[u] + Z[v];
        }
        ret = max(ret, DP[u]);
    }
    return ret;
}


int main() {

    int T = 1;
    while (scanf("%d", &N)) {
        if (!N) break;
        M = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d %d %d", X+M, Y+M, Z+M);
            if (X[M] > Y[M]) swap(X[M], Y[M]);
            M++;

            X[M] = X[M-1]; Y[M] = Z[M-1]; Z[M] = Y[M-1];
            if (X[M] > Y[M]) swap(X[M], Y[M]);
            M++;

            X[M] = Y[M-2]; Y[M] = Z[M-2]; Z[M] = X[M-2];
            if (X[M] > Y[M]) swap(X[M], Y[M]);
            M++;
        }
        for (int i = 0; i < M; i++) {
            adj[i].clear();
            for (int j = 0; j < M; j++) {
                if (X[j] < X[i] && Y[j] < Y[i])
                    adj[i].push_back(j);
            }
        }
        printf("Case %d: maximum height = %d\n", T++, longest());
    }

    return 0;
}
