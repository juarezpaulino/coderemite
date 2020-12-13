/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>


int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');
    return i;
}

unsigned short seg[1001][1001], dp[1001][1001], aux[1001][1001];

int main() {

    register int i, j, ni, nj, nx, ny, k;
    char x[1001], y[1001];

    while (1) {
        k = get_int(); if(!k) break; gets(x); gets(y);
        for (i = 0; *(x+i); i++) seg[i][0] = dp[i][0] = aux[i][0] = 0; nx = i;
        for (j = 0; *(y+j); j++) seg[0][j] = dp[0][j] = aux[0][j] = 0; ny = j;
        seg[i][0] = dp[i][0] = aux[i][0] = seg[0][j] = dp[0][j] = aux[0][j] = 0;
        for (i = 0; i < nx; i++) { ni = i+1; for (j = 0; j < ny; j++) {
            nj = j+1; seg[ni][nj] = aux[ni][nj] = 0; dp[ni][nj] = dp[ni][j];
            if (dp[ni][nj] < dp[i][nj]) dp[ni][nj] = dp[i][nj];
            if (*(x+i)==*(y+j)) {
                seg[ni][nj] = seg[i][j]+1;
                if (seg[ni][nj] >= k) {
                    aux[ni][nj] = dp[ni-k][nj-k]+k;
                    if (aux[ni][nj] < aux[i][j]+1) aux[ni][nj] = aux[i][j]+1;
                    if (aux[ni][nj] > dp[ni][nj]) dp[ni][nj] = aux[ni][nj];
                }
            }
        } }
        printf("%d\n", dp[nx][ny]);
    }

    return 0;
}

