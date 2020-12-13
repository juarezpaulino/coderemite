/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

int mat[1010][1010];
char in[1010101];

int main() {

    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        scanf("%d", &mat[i][j]);
        if (mat[i][j] < 1 || mat[i][j] > N*N || in[mat[i][j]]) { puts("0"); return 0; }
        in[mat[i][j]] = 1;
    }
    int c = 0, v = 0, d = 0;
    for (int i = 0; i < N; i++) {
        c = 0;
        for (int j = 0; j < N; j++) c += mat[i][j];
        if (i == 0) v = c;
        if (c != v) { puts("0"); return 0; }
        c = 0;
        for (int j = 0; j < N; j++) c += mat[j][i];
        if (c != v) { puts("0"); return 0; }
        d += mat[i][i];
    }
    if (d != v) { puts("0"); return 0; }
    printf("%d\n", v);

    return 0;
}
