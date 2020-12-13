/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
int X[20], Y[20];
double D[20][20];
double DP[1<<20];

double go(int k) {
    double &ret = DP[k];
    if (ret < 1E10-10) return ret;
    if (!k) return ret = 0;
    int i = __builtin_ctz(k);
    for (int j = i+1; j < N; j++) if (k&(1<<j))
        ret = min(ret, D[i][j]+go(k^(1<<i)^(1<<j)));
    return ret;
}


int main() {

    int c = 1;
    while (scanf("%d", &N)) {
        if (!N) break;
        N *= 2;
        for (int i = 0; i < N; i++)
            scanf("%*s %d %d", X+i, Y+i);
        for (int i = 0; i < N; i++) for (int j = i+1; j < N; j++) {
            double dy = Y[i]-Y[j], dx = X[i]-X[j];
            D[i][j] = D[j][i] = sqrt(dx*dx+dy*dy);
        }

        for (int i = 0; i < 1<<N; i++) DP[i] = 1E10;
        double ret = go((1<<N)-1);

        printf("Case %d: %.2lf\n", c++, ret);
    }

    return 0;
}
