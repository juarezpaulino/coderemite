#include <stdio.h>
#define min(a, b) ((a)<(b)?(a):(b)) 
int main() {
    char s1[101], s2[101], s[201], *p1 = s1-1, *p2 = s2-1;
    int dp[101][101];
    register int i, j, m, k = 1, ns1, ns2;
    while (scanf("%s %s ", s1, s2) == 2) {    
        for (i = 0; s1[i]; i++) dp[i][0] = i; dp[ns1 = i][0] = i;
        for (i = 0; s2[i]; i++) dp[0][i] = i; dp[0][ns2 = i] = i;
        for (i = 1; i <= ns1; i++) for (j = 1; j <= ns2; j++)
            if (p1[i] == p2[j]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
        i = ns1; j = ns2; m = dp[i][j]; s[m] = 0;
        while (--m >= 0) {
            if (i>0 && j>0 && p1[i]==p2[j]) s[m] = p1[i], i--, j--;
            else if (j>0 && dp[i][j]==dp[i][j-1]+1) s[m] = p2[j--];
            else s[m] = p1[i--];
        }
        printf("Teste %d\n%s\n\n", k++, s);
    }
    return 0;
}

