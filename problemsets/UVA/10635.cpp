/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;


int main() {

    int A[101010], B[101010];
    int DP[101010];
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int N, P, Q, x;
        scanf("%d %d %d", &N, &P, &Q); P++; Q++;
        for (int i = 0; i < N*N; i++) A[i] = 0;
        for (int i = 1; i <= P; i++) scanf("%d", &x), A[x] = i;
        for (int i = 0; i < Q; i++) scanf("%d", &x), B[i] = A[x];

        int ret = 1;
        DP[0] = B[0];
        for (int i = 1; i < Q; i++) {
            if (B[i] > DP[ret-1])
                DP[ret++] = B[i];
            else {
                int p = lower_bound(DP, DP+ret, B[i])-DP;
                DP[p] = B[i];
            }
        }

        printf("Case %d: %d\n", t, ret);
    }

    return 0;
}
