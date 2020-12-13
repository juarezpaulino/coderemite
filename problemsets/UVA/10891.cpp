/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

int A[110];
int DP[110][110];

int go(int l, int r) {
    int &ret = DP[l][r];
    if (ret != -(1<<30)) return ret;
    if (l > r) return ret = 0;
    if (l == r) return ret = A[l];
    int v = 0;
    for (int i = l; i <= r; i++) {
        v += A[i];
        ret = max(ret, v-go(i+1,r));
    }
    v = 0;
    for (int i = r; i >= l; i--) {
        v += A[i];
        ret = max(ret, v-go(l,i-1));
    }
    return ret;
}

int main() {

    int N;
    while (scanf("%d", &N)) {
        if (!N) break;
        for (int i = 0; i < N; i++) scanf("%d", A+i);
        for (int i = 0; i < N; i++) for (int j = i; j < N; j++) DP[i][j] = -(1<<30);
        int ret = go(0,N-1);
        printf("%d\n", ret);
    }

    return 0;
}
