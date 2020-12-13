/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    int N, T = 1;
    int M[10][10];
    while (scanf("%d", &N)) {
        if (!N) break;
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &M[i][j]);
        printf("Case %d:", T++);
        for (int d = 0; d < (N+1)/2; d++) {
            if ((N&1) && (d==(N+1)/2-1)) { printf(" %d\n", M[d][d]); continue; }
            int ret = 0;
            for (int j = d; j < N-d; j++) ret += M[d][j] + M[N-1-d][j];
            for (int i = d+1; i < N-d-1; i++) ret += M[i][d] + M[i][N-1-d];
            printf(" %d", ret);
        }
        if (N%2==0) putchar('\n');
    }

    return 0;
}
