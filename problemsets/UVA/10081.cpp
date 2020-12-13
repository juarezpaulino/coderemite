/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int N, K;
double DP[100][11];

double go(int n, int l) {
    double &ret = DP[n][l];
    if (ret > -0.5) return ret;
    if (n == N) return ret = 1.;
    ret = 0.;
    if (n == 0) for (int i = 0; i <= K; i++) ret += go(n+1, i);
    else {
        if (l > 0) ret += go(n+1, l-1);
        ret += go(n+1, l);
        if (l < K) ret += go(n+1, l+1);
    }
    return ret;
}

int main() {

    while (scanf("%d%d", &K, &N) != EOF) {
        for (int i = 0; i <= N; i++) for (int j = 0; j <= K+1; j++) DP[i][j] = -1.;
        double ret = go(0,K+1) * 100. / pow(K+1, N);
        printf("%.5lf\n", ret);
    }

    return 0;
}
