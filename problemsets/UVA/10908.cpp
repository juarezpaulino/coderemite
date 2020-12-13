/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

char A[110][110];
int M, N, Q;

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d ", &M, &N, &Q);
        for (int i = 0; i < M; i++) gets(A[i]);
        printf("%d %d %d\n", M, N, Q);
        while (Q--) {
            int r, c;
            scanf("%d %d", &r, &c);
            bool ok = 1;
            int s = 1;
            while (ok) {
                s+=2;
                if (r-s/2 < 0 || r+s/2 >= M || c-s/2 < 0 || c+s/2 >= N) break;
                for (int j = c-s/2; j <= c+s/2; j++) if (A[r-s/2][j] != A[r][c] || A[r+s/2][j] != A[r][c]) ok = 0;
                for (int i = r-s/2; i <= r+s/2; i++) if (A[i][c-s/2] != A[r][c] || A[i][c+s/2] != A[r][c]) ok = 0;
            }
            printf("%d\n", s-2);
        }
    }

    return 0;
}
