/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

int X;
int W[10][1010];
int DP[10][1010];

int go(int h, int k) {
    int &ret = DP[h][k];
    if (ret != 1<<30) return ret;
    ret = (1<<30)-1;
    if (k == X) {
        if (h == 0) return ret = 0;
        else return ret;
    }
    if (h < 9) ret = min(ret, 60-W[h][k]+go(h+1,k+1));
    ret = min(ret, 30-W[h][k]+go(h,k+1));
    if (h > 0) ret = min(ret, 20-W[h][k]+go(h-1,k+1));
    return ret;
}

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &X);
        X /= 100;
        for (int i = 9; i >= 0; i--) for (int j = 0; j < X; j++) scanf("%d", &W[i][j]);
        for (int i = 0; i < 10; i++) for (int j = 0; j <= X; j++) DP[i][j] = 1<<30;
        int ret = go(0,0);
        printf("%d\n\n", ret);
    }

    return 0;
}
