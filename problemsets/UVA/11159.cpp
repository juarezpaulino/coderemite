/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXV = 202;

vector<int> adj[MAXV];
int par[MAXV], disc[MAXV], id = 1;

int augment(int u) {
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (disc[v]==id) continue;
        disc[v] = id;
        if (par[v]==-1 || augment(par[v]))
            return (par[v]=u, par[u]=v, 1);
    }
    return 0;
}

int bpm(int M, int N) {
    int ret = 0;
    for (int i = 0; i < M+N; i++) par[i] = -1;
    for (int i = 0; i < M; i++) if (adj[i].size() && par[i]==-1) ++id, ret += augment(i);
    return ret;
}


int A[101], B[101];

int main() {

    int T; scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        printf("Case %d: ", t);
        int M, N;
        scanf("%d", &M); for (int i = 0; i < M; i++) scanf("%d", A+i);
        scanf("%d", &N); for (int i = 0; i < N; i++) scanf("%d", B+i);
        for (int i = 0; i < M+N; i++) adj[i].clear();
        for (int i = 0; i < M; i++) for (int j = 0; j < N; j++)
            if ((!A[i]&&!B[j]) || (A[i]&&B[j]%A[i]==0))
                adj[i].push_back(M+j),
                adj[M+j].push_back(i);
        int ret = bpm(M,N);
        printf("%d\n", ret);
    }

    return 0;
}
