#include <stdio.h>

#define max(a, b) ((a)>(b)?(a):(b))

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');
    return i;
}

int main() {

    int ci[51], vi[51], dp[51][1001];
    register int i, j, k = 1, c, f, d;
    while (1) {
        c = get_int(); f = get_int(); if (!c && !f) break;
        for (i = 1; i <= f; i++) { ci[i] = get_int(); vi[i] = get_int(); }
        for (i = 0; i <= f; i++) dp[i][0] = 0;
        for (j = 0; j <= c; j++) dp[0][j] = 0;
        for (i = 1; i <= f; i++)
            for (j = 1; j <= c; j++) {
                if (ci[i] > j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = max(dp[i-1][j] , dp[i-1][j-ci[i]]+vi[i]);
            }
        printf("Teste %d\n%d\n\n", k++, dp[f][c]);
    }
    
    return 0;
}

