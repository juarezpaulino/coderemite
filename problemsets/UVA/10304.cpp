/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int F[300];
int DP[300][300];
int R[300][300];
int S[300][300];


int go(int i, int j) {
    int &ret = DP[i][j];
    if (ret != (1<<30)) return ret;
    if (i == j) {
        R[i][j] = i;
        return ret = S[i][j];
    }
    go(i,j-1); go(i+1, j);
    for (int k = R[i][j-1]; k <= R[i+1][j]; k++) {
        int c = S[i][j];
        if (k != i) c += go(i, k-1);
        if (k != j) c += go(k+1, j);
        if (c < ret) {
            R[i][j] = k;
            ret = c;
        }
    }
    return ret;
}


int main() {

    int N;
    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i < N; i++)
            scanf("%d", F+i);
        for (int i = 0; i < N; i++) {
            int s = 0;
            for (int j = i; j < N; j++) {
                s += F[j];
                S[i][j] = s;
                DP[i][j] = (1<<30);
            }
        }

        int ret = go(0,N-1)-S[0][N-1];

        printf("%d\n", ret);
    }

    return 0;
}
