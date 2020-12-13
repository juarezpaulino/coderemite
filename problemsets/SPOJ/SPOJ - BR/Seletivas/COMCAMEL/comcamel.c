#include <stdio.h>

#define INF 0x3F3F3F3F3F3F3F3FLL

int num[15];
char mul[15];
long long maxi[15][15], mini[15][15];


int main() {
    
    char str[40], ch;
    int i, j, k, l, m, n;
    long long q1, q2;
    
    scanf("%d ", &n);
    while (n--) {
        gets(str);
        i = 0; m = 1; ch = str[0];
        while (ch) {
            for (j = 0; ch>='0' && ch<='9'; ch = str[++i]) j = 10*j + (ch-'0');
            num[m] = j;
            if (ch == '*') { mul[m] = 1; ch = str[++i]; }
            else if (ch == '+') { mul[m] = 0; ch = str[++i]; }
            m++;
        }
        
        for (i = 1; i < m; i++) mini[i][i] = maxi[i][i] = num[i];
        for (l = 2; l <= m; l++)
            for (i = 1; i <= m-l+1; i++) {
                j = i+l-1;
                mini[i][j] = INF; maxi[i][j] = 0;
                for (k = i; k < j; k++) {
                    if (mul[k]) { q1 = mini[i][k] * mini[k+1][j]; q2 = maxi[i][k] * maxi[k+1][j]; }
                    else { q1 = mini[i][k] + mini[k+1][j]; q2 = maxi[i][k] + maxi[k+1][j]; }
                    if (q1 < mini[i][j]) mini[i][j] = q1;
                    if (q2 > maxi[i][j]) maxi[i][j] = q2;
                }
            }
                
        printf("The maximum and minimum are %lld and %lld.\n", maxi[1][m-1], mini[1][m-1]);
    }
    
    return 0;
}
