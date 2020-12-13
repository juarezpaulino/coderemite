/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int INF = 0x3F3F3F3F;

int M, N;
int Y, X;
int MAPA[50][50];
int DP[50][50];

int main() {

    while (scanf("%d %d", &M, &N) != EOF) {
        scanf("%d %d", &Y, &X);
        for (int i = 1; i <= M; i++) for (int j = 1; j <= N; j++) scanf("%d", &MAPA[i][j]);

        memset(DP,INF,sizeof(DP));
        DP[Y][X] = 0;
        for (int j = X+1; j <= N; j++) DP[Y][j] = DP[Y][j-1] + MAPA[Y][j];
        for (int i = Y+1; i <= M; i++) for (int j = X; j <= N; j++) {
            if (DP[i-1][j] < DP[i][j-1]) DP[i][j] = DP[i-1][j] + MAPA[i][j];
            else DP[i][j] = DP[i][j-1] + MAPA[i][j];
        }
        if (DP[M][N]  > MAPA[Y][X]) puts("N");
        else printf("Y %d\n", MAPA[Y][X] - DP[M][N]);
    }

    return 0;
}
