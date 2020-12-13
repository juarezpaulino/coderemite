/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int M, N;
int AX[110], AY[110];
int BX[110], BY[110];

const int MAXV = 300;

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

int main() {

    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &M, &N);
        for (int i = 0; i < M; i++) scanf("%d %d", AX+i, AY+i);
        for (int i = 0; i < N; i++) scanf("%d %d", BX+i, BY+i);
        for (int i = 0; i < M+N; i++) adj[i].clear();
        for (int i = 0; i < M-1; i++) {
            int dy = AY[i+1]-AY[i];
            int dx = AX[i+1]-AX[i];
            double dA = 2.*sqrt(dy*dy+dx*dx);
            for (int j = 0; j < N; j++) {
                double dB = 0.;
                dy = AY[i]-BY[j]; dx = AX[i]-BX[j]; dB += sqrt(dy*dy+dx*dx);
                dy = AY[i+1]-BY[j]; dx = AX[i+1]-BX[j]; dB += sqrt(dy*dy+dx*dx);
                if (dB-dA < 1E-10)
                    adj[i].push_back(M+j),
                    adj[M+j].push_back(i);
            }
        }
        int ret = M+bpm(M,N);
        printf("%d\n", ret);
        printf("%d %d", AX[0], AY[0]);
        for (int i = 0; i < M; i++) {
            if (i) printf(" %d %d", AX[i], AY[i]);
            if (par[i]!=-1) printf(" %d %d", BX[par[i]-M], BY[par[i]-M]);
        }
        putchar('\n');
        if (T) putchar('\n');
    }

    return 0;
}
