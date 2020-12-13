/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

long long F[14];
long long P[14][14];
long long DP[14][14];

long long go(int N, int L) {
    long long &ret = DP[N][L];
    if (ret!=-1) return ret;
    if (N==L) return ret = 1;
    if (L>N) return ret = 0;
    if (L<=0) return ret = 0;
    ret = 0;
    for (int i = 1; i <= N; i++) ret += go(i-1, L-1)*F[N-i]*P[N-1][i-1];
    return ret;
}

int main() {

    P[0][0] = 1;
    for (int i = 1; i < 14; i++) {
        P[i][0] = P[i][i] = 1;
        for (int j = 1; j < 14; j++) P[i][j] = P[i-1][j]+P[i-1][j-1];
    }
    F[0] = F[1] = 1;
    for (int i = 2; i < 14; i++) F[i] = F[i-1]*i;
    memset(DP,-1,sizeof(DP));
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, L, R;
        scanf("%d %d %d", &N, &L, &R);
        long long ret = 0;
        for (int i = 1; i <= N; i++)
            ret += go(i-1, L-1) * go(N-i, R-1) * P[N-1][i-1];
        printf("%lld\n", ret);
    }

    return 0;
}
