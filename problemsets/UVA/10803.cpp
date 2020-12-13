/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

double D[101][101];
int X[101], Y[101];


int main() {

    int T;
    int N;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        printf("Case #%d:\n", t);
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &X[i], &Y[i]);
            for (int j = 0; j < N; j++) D[i][j] = 1E10;
            D[i][i] = 0;
            for (int j = i-1; j >= 0; j--) {
                int dx = X[i] - X[j];
                int dy = Y[i] - Y[j];
                int d = dx*dx + dy*dy;
                if (d <= 100) D[i][j] = D[j][i] = sqrt(d);
            }
        }
        for (int k = 0; k < N; k++) for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
            double d = D[i][k] + D[k][j];
            if (d < D[i][j]) D[i][j] = d;
        }
        double ret = -1;
        for (int i = 0; i < N; i++) for (int j = i-1; j >= 0; j--)
            if (D[i][j] > 1E9) { ret = -1; goto OUT; }
            else ret = max(ret, D[i][j]);
OUT:
        if (ret < 0) puts("Send Kurdy\n");
        else printf("%.4lf\n\n", ret);
    }

    return 0;
}
