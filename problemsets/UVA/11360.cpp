/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

char M[2][55][55];
int N;

int main() {

    int T;
    char c[55];
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) scanf("%s", M[0][i]);
        int K;
        scanf("%d", &K);
        int p = 1, a, b;
        while (K--) {
            memcpy(M[p], M[1-p], sizeof(M[0]));
            scanf("%s", c);
            if (c == string("row")) {
                scanf("%d %d", &a, &b);
                a--; b--;
                for (int j = 0; j < N; j++) M[p][a][j] = M[1-p][b][j], M[p][b][j] = M[1-p][a][j];
            }
            else if (c == string("col")) {
                scanf("%d %d", &a, &b);
                a--; b--;
                for (int i = 0; i < N; i++) M[p][i][a] = M[1-p][i][b], M[p][i][b] = M[1-p][i][a];
            }
            else if (c == string("inc")) {
                for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
                    M[p][i][j] = (M[p][i][j]-'0'+11)%10+'0';
            }
            else if (c == string("dec")) {
                for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
                    M[p][i][j] = (M[p][i][j]-'0'+9)%10+'0';
            }
            else if (c == string("transpose")) {
                for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
                    M[p][i][j] = M[1-p][j][i];
            }
            p = 1-p;
        }
        printf("Case #%d\n", t);
        for (int i = 0; i < N; i++) printf("%s\n", M[1-p][i]);
        putchar('\n');
    }

    return 0;
}
