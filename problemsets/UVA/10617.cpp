/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>

typedef long long ll;

char A[101];
ll DP[66][66];

ll go(int i, int j) {
    if (i > j) return 1;
    ll &ret = DP[i][j];
    if (ret != -1) return ret;
    return ret = go(i+1, j) + go(i, j-1) - (A[i]!=A[j])*go(i+1, j-1);
}


int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        memset(DP, -1, sizeof(DP));
        scanf("%s", A);
        ll ret = go(0, strlen(A)-1);
        printf("%lld\n", ret-1);
    }

    return 0;
}
