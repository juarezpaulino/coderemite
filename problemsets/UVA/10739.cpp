/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int DP[1010][1010];

int main() {

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        char A[1010], B[1010];
        int N;
        scanf("%s", A+1);
        N = strlen(A+1);
        strcpy(B+1, A+1);
        reverse(B+1, B+1+N);
        for (int i = 1; i <= N; i++) DP[i][0] = DP[0][i] = i;
        for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) {
            DP[i][j] = min(DP[i-1][j], DP[i][j-1]) + 1;
            if (A[i]==B[j]) DP[i][j] = min(DP[i][j], DP[i-1][j-1]);
            else DP[i][j] = min(DP[i][j], DP[i-1][j-1]+1);
        }
        int ret = DP[N][N];
        printf("Case %d: %d\n", t, ret/2);
    }

    return 0;
}
