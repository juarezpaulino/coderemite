/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

int LCS(char A[], char B[]) {
    int M = strlen(A)+1, N = strlen(B)+1;
    int DP[M][N];
    for (int i = 0; i < M; i++) DP[i][0] = 0;
    for (int i = 0; i < N; i++) DP[0][i] = 0;
    for (int i = 1; i < M; i++) for (int j = 1; j < N; j++) {
        DP[i][j] = max(DP[i-1][j],DP[i][j-1]);
        if (A[i-1] == B[j-1]) DP[i][j] = max(DP[i][j], DP[i-1][j-1]+1);
    }
    return DP[M-1][N-1];
}

int main() {

    char A[1010], B[1010];

    while (gets(A)) {
        gets(B);
        int ret = LCS(A, B);
        printf("%d\n", ret);
    }

    return 0;
}
