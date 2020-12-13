/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int N, T, P;
int DP[77][77];

int go(int k, int v) {
    int &ret = DP[k][v];
    if (ret != -1) return ret;
    if (k == N-1) {
        if (T-v >= P) return ret = 1;
        else return ret = 0;
    }
    ret = 0;
    for (int u = P; T-u-v >= (N-k-1)*P; u++) ret += go(k+1, v+u);
    return ret;
}

int main() {

    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &N, &T, &P);
        for (int i = 0; i <= N; i++) for (int j = 0; j <= T; j++) DP[i][j] = -1;
        int ret = go(0, 0);
        printf("%d\n", ret);
    }

    return 0;
}
