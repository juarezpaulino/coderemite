/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <queue>
#include <cmath>

using namespace std;

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int N;
double adj[1010][1010], X[1010], Y[1010];


bool check(double m) {
    char V[1010] = {0};
    queue<int> q;
    q.push(0);
    V[0] = 1;
    int ret = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        ret++;
        for (int i = 0; i < N; i++) if (!V[i] && i != u && cmp(adj[i][u],m) <= 0) {
            q.push(i); V[i] = 1;
        }
    }
    return ret == N;
}


int main() {


    double x, y;
    while (scanf("%d", &N)) {
        if (!N) break;
        for (int i = 0; i < N; i++) {
            scanf("%lf %lf", &x, &y);
            X[i] = x; Y[i] = y;
        }
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (i != j) {
            x = X[i]-X[j];
            y = Y[i]-Y[j];
            adj[i][j] = adj[j][i] = x*x + y*y;
        }

        double lo = 0., hi = 1E9+10;
        for (int it = 0; it < 100; it++) {
            if (cmp(hi,lo)==0) break;
            double m = (hi+lo)/2.;
            if (check(m)) hi = m; else lo = m;
        }

        printf("%.4lf\n", sqrt((hi+lo)/2));
    }

    return 0;
}
