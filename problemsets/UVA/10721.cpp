/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long i64;

int N, K, M;
i64 DP[51][51];

i64 go(int n, int k) {
    i64 &ret = DP[n][k];
    if (ret != -1) return ret;
    if (n <= 0 || k <= 0) return ret = 0;
    if (k == 1) {
        if (n <= M) return ret = 1;
        else return ret = 0;
    }
    ret = 0;
    for (int i = 1; i <= M; i++) if (n-i >= 0)
        ret += go(n-i, k-1);
    return ret;
}


int main() {

    while (scanf("%d %d %d", &N, &K, &M) != EOF) {
        for (int n = 0; n <= N; n++) for (int k = 0; k <= K; k++) DP[n][k] = -1;
        i64 ret = go(N,K);
        printf("%lld\n", ret);
    }

    return 0;
}
