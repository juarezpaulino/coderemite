/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>

using namespace std;

char A[200], B[200];
int DP[200][200];

int main() {

    int T = 1;
    while (gets(A+1)) {
        if (*(A+1)=='#') break;
        gets(B+1);
        int M = strlen(A+1), N = strlen(B+1);
        for (int i = 0; i <= M; i++) DP[i][0] = 0;
        for (int i = 0; i <= N; i++) DP[0][i] = 0;
        for (int i = 1; i <= M; i++) for (int j = 1; j <= N; j++)
            DP[i][j] = max(max(DP[i-1][j], DP[i][j-1]), (A[i]==B[j])?DP[i-1][j-1]+1:0);
        printf("Case #%d: you can visit at most %d cities.\n", T++, DP[M][N]);
    }

    return 0;
}
