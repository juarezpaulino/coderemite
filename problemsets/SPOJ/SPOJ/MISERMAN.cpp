/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
int MAT[150][150];

const int INF = 0x3F3F3F3F;

int main() {

    while (scanf("%d %d", &N, &M) != EOF) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                scanf("%d", &MAT[i][j]);
        int DP[2][150];
        for (int i = 0; i < M; i++) DP[0][i] = MAT[0][i];
        int k = 1;
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < M; j++) DP[k][j] = INF;
            for (int j = 0; j < M; j++) {
                if (j) DP[k][j] = min(DP[k][j], DP[k^1][j-1]+MAT[i][j]);
                DP[k][j] = min(DP[k][j], DP[k^1][j]+MAT[i][j]);
                if (j < M-1) DP[k][j] = min(DP[k][j], DP[k^1][j+1]+MAT[i][j]);
            }
            k = k^1;
        }
        int ret = INF;
        for (int i = 0; i < M; i++) ret = min(ret, DP[k^1][i]);
        printf("%d\n", ret);
    }

    return 0;
}
