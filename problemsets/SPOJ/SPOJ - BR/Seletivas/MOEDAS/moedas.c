#include <stdio.h>

#define INF 0x3F3F3F3F

int coin[100];
int m, n;
int dp[50001];

int get_int() {

    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));

    if (ch == EOF) return (EOF);

    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');

    return i;
}


int main() {
    
    int i, j, k;
    
    while (1) {
        m = get_int(); n = get_int();
        if (!m) break;
        for (i = 0; i < n; i++) coin[i] = get_int();
        dp[0] = 0;
        for (i = 1; i <= m; i++) {
            dp[i] = INF;
            for (j = 0; j < n; j++) {
                k = i-coin[j];
                if (k>=0 && dp[k]+1<dp[i])  dp[i] = dp[k]+1;
            }
        }
        if (dp[m] == INF) puts("Impossivel");
        else printf("%d\n", dp[m]);
    }
    
    return 0;
}
