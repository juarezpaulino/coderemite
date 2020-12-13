#include <stdio.h>
#include <string.h>

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');
    return i;
}

int main() {
    int n, freq[60][60], dp[60][60];
    register int i, j, p, k, mini, m, c = 1;
    char out[100000], str[100];
    
    *out = 0;
    while (1) {
        n = get_int(); if (!n) break;
        for (i = 0; i < n; i++) freq[i][i] = get_int();
        for (i = 0; i < n; i++) for (j = i+1; j < n; j++)
            freq[i][j] = freq[i][j-1] + freq[j][j];
        for (k = 1; k < n; k++) for (i = 0, j = k; j < n; i++, j++) {
	            mini = dp[i+1][j] + freq[i+1][j];
                for (p = i+1; p < j; p++) {
                    m = dp[i][p-1] + freq[i][p-1] + dp[p+1][j] + freq[p+1][j];
                    if (m < mini) mini = m;
                }
                m = dp[i][j-1] + freq[i][j-1]; if (m < mini) mini = m;
	            dp[i][j] = mini;
	        }
        sprintf(str, "Teste %d\n%d\n\n", c++, dp[0][n-1]); strcat(out, str);
    }
    printf(out);
    return 0;
}

