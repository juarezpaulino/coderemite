/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

const int INF = 0x3F3F3F3F;

int H, W;
int MAT[140][140];
int DP[2][140];
int T;

int main() {

    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i < 140; i++) DP[0][i] = DP[1][i] = 0;
        scanf("%d %d", &H, &W);
        for (int i = 1; i <= H; i++) for (int j = 1; j <= W; j++) scanf("%d", &MAT[i][j]);
        int cur = 1;
        for (int k = 1; k <= H; k++) {
            for (int j = 1; j <= W; j++)
                DP[cur][j] = max(DP[cur^1][j-1], max(DP[cur^1][j], DP[cur^1][j+1])) + MAT[k][j];
            cur ^= 1;
        }
        cur ^= 1;
        int ret = 0;
        for (int j = 1; j <= W; j++) ret = max(ret, DP[cur][j]);
        printf("%d\n", ret);
    }

    return 0;
}
