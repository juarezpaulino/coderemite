/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

int M, N;
char MAPA[105][105];
int DP[101][101], E[101][101], C[101][101], R[101][101];

inline int extend(int i, int j, int r, int c) {
    int ret = E[i][j];
    if (r > R[i][j]) ret -= E[r][j];
    if (c > C[i][j]) ret -= E[i][c];
    return ret;
}

int main() {

    while (scanf("%d %d ", &M, &N) != EOF) {
        if (M==0) break;
        for (int i = 1; i <= M; i++) gets(&MAPA[i][1]);

        for (int i = 0; i < M; i++) DP[i][0] = E[i][0] = 0, R[i][0] = i, C[i][0] = 0;
        for (int j = 0; j < N; j++) DP[0][j] = E[0][j] = 0, R[0][j] = 0, C[0][j] = j;
        if (MAPA[1][1]=='1') {
            DP[1][1] = E[1][1] = 1;
            R[1][1] = R[0][1]; C[1][1] = C[1][0];
        }
        else {
            DP[1][1] = E[1][1] = 0;
            R[1][1] = 1; C[1][1] = 1;
        }

        for (int i = 1; i <= M; i++) for (int j = 1; j <= N; j++) {
            if (i==1 && j==1) continue;
            if (MAPA[i][j]=='1') {
                R[i][j] = R[i-1][j], C[i][j] = C[i][j-1];
                if (E[i-1][j]==0 && E[i][j-1]==0) E[i][j] = 0;
                else E[i][j] = extend(i-1, j, R[i][j], C[i][j]) + extend(i, j-1, R[i][j], C[i][j]) - extend(i-1, j-1, R[i][j], C[i][j]);
                E[i][j]++;
            }
            else {
                R[i][j] = i, C[i][j] = j;
                E[i][j] = 0;
            }
            DP[i][j] = DP[i-1][j] + DP[i][j-1] - DP[i-1][j-1] + E[i][j];
        }
        //for (int i = 0; i <= M; i++, putchar('\n')) for (int j = 0; j <= N; j++) printf("(%d,%d) ", DP[i][j], E[i][j]);
        printf("%d\n", DP[M][N]);
    }

    return 0;
}
