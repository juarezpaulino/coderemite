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
#include <queue>

using namespace std;

int M, N;
int A[120], B[120];
int DP[120][120];

int main() {

    int T = 1;
    while (scanf("%d %d", &M, &N)) {
        if (!(M|N)) break;
        for (int i = 0; i < M; i++) scanf("%d", A+i+1);
        for (int i = 0; i < N; i++) scanf("%d", B+i+1);
        for (int i = 0; i <= M; i++) DP[i][0] = 0;
        for (int i = 0; i <= N; i++) DP[0][i] = 0;
        for (int i = 1; i <= M; i++) for (int j = 1; j <= N; j++) {
            DP[i][j] = max(DP[i][j-1], DP[i-1][j]);
            if (A[i]==B[j] && DP[i-1][j-1]+1 > DP[i][j]) DP[i][j] = DP[i-1][j-1]+1;
        }
        printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", T++, DP[M][N]);
    }

    return 0;
}
