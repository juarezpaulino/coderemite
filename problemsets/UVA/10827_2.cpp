/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

int A[210][210];

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) {
            scanf("%d", &A[i][j]);
            A[i+N][j] = A[i][j];
        }

        int ret = 0;
        for (int k = 1; k <= 2*N; k++) {
            int S[210] = {0};
            for (int i = k; i < min(k+N,2*N+1); i++) {
                int tot = 0;
                for (int j = 1; j <= N; j++) tot += S[j] += A[i][j];
                int maxi = 0, mini = 0;
                for (int j = 1; j <= N; j++) {
                    maxi += S[j];
                    mini += S[j];
                    if (maxi < 0) maxi = 0;
                    if (mini > 0) mini = 0;
                    ret = max(ret, max(maxi, tot-mini));
                }
            }
        }
        printf("%d\n", ret);
    }

    return 0;
}
