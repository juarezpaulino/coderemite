#include <stdio.h>

#define max(a,b) ((a)>(b)?(a):(b))

int get_int() {
    int ch, i, s;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    s = (ch == '-') ? 1, ch = getchar() : 0;
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');
    if (s) return -i;
    return i;
}


int main() {

    int dp[1000], left[1000], right[1000], cell[1000];
    register int n, m, i, j, k = 1;
    while (1) {
        n = get_int(); m = get_int(); if (!n && !m) break;
        dp[0] = get_int(); for (j = 1; j < m; j++) dp[j] = dp[j-1]+get_int();
        for (i = 1; i < n; i++) {
            for (j = 0; j < m; j++) cell[j] = get_int();
            right[0] = dp[0]+cell[0];
            for (j = 1; j < m; j++) right[j] = max(dp[j], right[j-1])+cell[j];
            left[m-1] = dp[m-1] + cell[m-1];
            for (j = m-2; j >= 0; j--) left[j] = max(dp[j], left[j+1])+cell[j];
            for (j = 0; j < m; j++) dp[j] = max(right[j], left[j]);
        }
        printf("Teste %d\n%d\n\n", k++, dp[m-1]);
    }    
    return 0;
}

