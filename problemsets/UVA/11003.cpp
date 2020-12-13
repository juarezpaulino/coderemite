/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

int DP[1010][3030];
int W[1010], L[1010];
int N;

int go(int k, int l) {
    int &ret = DP[k][l+1];
    if (ret != -1) return ret;
    ret = 0;
    if (k == N) return ret;
    ret = go(k+1, l);
    if (l == -1)
        ret = max(ret, 1+go(k+1,L[k]));
    else if (l >= W[k])
        ret = max(ret, 1+go(k+1, min(l-W[k],L[k])));
    return ret;
}


int main() {

    while (scanf("%d", &N)) {
        if (!N) break;
        int maxi = 0;
        for (int i = 0; i < N; i++) scanf("%d %d", W+i, L+i);
        for (int i = 0; i <= N; i++) for (int j = 0; j <= 3001; j++) DP[i][j] = -1;
        int ret = go(0,-1);
        printf("%d\n", ret);
    }

    return 0;
}
