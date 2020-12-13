/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 0x3F3F3F3F;

#define SQR(v) ((v)*(v))

int V[5050];
int T, K, N;
int DP[2000][5010];
int ok = 0;

int go(int k, int n) {
    int &ret = DP[k][n];
    if (ret != -1) return ret;
    if (k == 0) return ret = 0;
    if (N-n < k*3) return ret = INF;
    ret = go(k, n+1);
    int v = go(k-1, n+2);
    if (v != INF) ret = min(ret, v + SQR(V[n]-V[n+1]));
    return ret;
}


int main() {

    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &K, &N);
        for (int i = 0; i < N; i++) scanf("%d", V+i);
        for (int i = 0; i <= K+8; i++) for (int j = 0; j < N; j++) DP[i][j] = -1;
        int ret = go(K+8, 0);
        printf("%d\n", ret);
    }

    return 0;
}
