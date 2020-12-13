/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 0x3F3F3F3F;

int N;
int L[100], W[100], H[100];
int DP[100];

int go(int v) {
    int &ret = DP[v];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0; i < 3*(N+1); i++) {
        if (L[i] < L[v] && W[i] < W[v]) ret = max(ret, go(i));
    }
    ret += H[v];
    return ret;
}

int main() {

    while (1) {
        scanf("%d", &N);
        if (N == 0) break;

        for (int i = 1; i <= N; i++) {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);

            if (x < y) { L[3*i] = x; W[3*i] = y; H[3*i] = z; }
            else { L[3*i] = y; W[3*i] = x; H[3*i] = z; }

            if (x < z) { L[3*i+1] = x; W[3*i+1] = z; H[3*i+1] = y; }
            else { L[3*i+1] = z; W[3*i+1] = x; H[3*i+1] = y; }

            if (y < z) { L[3*i+2] = y; W[3*i+2] = z; H[3*i+2] = x; }
            else { L[3*i+2] = z; W[3*i+2] = y; H[3*i+2] = x; }
        }

        L[0] = W[0] = INF; H[0] = 0;
        L[1] = W[1] = INF; H[1] = 0;
        L[2] = W[2] = INF; H[2] = 0;

        memset(DP, -1, sizeof(DP));

        int ret = go(0);
        printf("%d\n", ret);
    }

    return 0;
}
