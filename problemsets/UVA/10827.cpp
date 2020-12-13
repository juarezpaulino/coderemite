/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

int A[210][210];

inline int sum(int y1, int x1, int y2, int x2) {
    return  A[y2][x2] -
            A[y1-1][x2] -
            A[y2][x1-1] +
            A[y1-1][x1-1];
}

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);

        for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) {
            scanf("%d", &A[i][j]);
            A[i+N][j] = A[i][j+N]= A[i+N][j+N] = A[i][j];
        }
        int M = 2*N;

        for (int i = 1; i <= M; i++) for (int j = 1; j <= M; j++)
            A[i][j] += A[i-1][j] + A[i][j-1] - A[i-1][j-1];

        int ret = 0;
        for (int k = 1; k <= M; k++) for (int l = 1; l <= M; l++)
            for (int i = k; i <= M && i < k+N; i++) for (int j = l; j <= M && j < l+N; j++)
                ret = max(ret, sum(k,l,i,j));
        printf("%d\n", ret);
    }

    return 0;
}
