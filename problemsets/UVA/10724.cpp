/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

double G[55][55];
int X[55], Y[55];

inline int dist(int u, int v) {
    int dx = X[u]-X[v];
    int dy = Y[u]-Y[v];
    return sqrt(dx*dx+dy*dy);
}

int main() {

    int N, M;
    while (scanf("%d %d", &N, &M) && (N|M)) {
        for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) G[i][j] = (i==j) ? 0 : 1E20;
        for (int i = 1; i <= N; i++) scanf("%d %d", X+i, Y+i);
        while (M--) {
            int u, v;
            scanf("%d %d", &u, &v);
            G[u][v] = G[v][u] = dist(u,v);
        }
        for (int k = 1; k <= N; k++) for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++)
            G[i][j] = min(G[i][j], G[i][k]+G[k][j]);
        double retC = -1., retD;
        int retU, retV;
        for (int u = 1; u <= N; u++) for (int v = u+1; v <= N; v++) {
            double c = 0.;
            double d = dist(u,v);
            for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++)
                c += G[i][j] - min(G[i][j], min(G[i][u]+d+G[v][j], G[i][v]+d+G[u][j]));
            if (cmp(c,retC) > 0 || (cmp(c,retC)==0 && cmp(d,retD) < 0))
                retC = c, retD = d, retU = u, retV = v;
        }
        if (cmp(retC,1.) <= 0) puts("No road required");
        else printf("%d %d\n", retU, retV);
    }

    return 0;
}
