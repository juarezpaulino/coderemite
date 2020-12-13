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

int main() {

    int T, N;
    char S[10000], R[10000];
    int DP[2][10000];
    scanf("%d", &T);
    while (T--) {
        scanf("%s", S+1);
        N = strlen(S+1);
        strcpy(R+1, S+1);
        reverse(R+1, R+N+1);

        int k = 1;
        for (int i = 0; i <= N; i++) DP[0][i] = DP[1][i] = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                DP[k][j] = max(DP[k][j-1], DP[k^1][j]);
                if (S[j]==R[i]) DP[k][j] = max(DP[k][j],DP[k^1][j-1]+1);
            }
            k^=1;
        }
        printf("%d\n", N-DP[k^1][N]);
    }

    return 0;
}
