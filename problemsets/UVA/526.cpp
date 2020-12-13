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

int DP[110][110];
char A[110], B[110];
int M, N, K;

int trace(int i, int j) {
    if (!i && !j) return 1;
    if (i && DP[i][j] == DP[i-1][j]+1) {
        int p = trace(i-1, j);
        printf("%d Insert %d,%c\n", K++, p, B[i]);
        return p+1;
    }
    if (j && DP[i][j] == DP[i][j-1]+1) {
        int p = trace(i, j-1);
        printf("%d Delete %d\n", K++, p);
        return p;
    }
    int p = trace(i-1,j-1);
    if (B[i]!=A[j]) printf("%d Replace %d,%c\n", K++, p, B[i]);
    return p+1;
}

int main() {

    bool f = 1;
    while (gets(A+1) && gets(B+1)) {
        if (!f) putchar('\n');
        f = 0;
        M = strlen(A+1), N = strlen(B+1);
        for (int j = 0; j <= M; j++) DP[0][j] = j;
        for (int i = 0; i <= N; i++) DP[i][0] = i;
        for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) {
            DP[i][j] = min(DP[i-1][j], DP[i][j-1]) + 1;
            DP[i][j] = min(DP[i][j], DP[i-1][j-1] + (B[i]!=A[j]));
        }
        printf("%d\n", DP[N][M]);
        K = 1;
        trace(N, M);
    }

    return 0;
}
