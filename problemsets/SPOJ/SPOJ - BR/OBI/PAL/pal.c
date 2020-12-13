#include <stdio.h>
#define INF 0x3F3F3F3F
char pali[2010][2010];
int main() {
    int n, part[2010];
    char cad[2010];
    register int i, j, p, m, k = 1;
    while (scanf("%d %s", &n, cad) && n) {
        for (i = 0; i < n; i++) pali[i][i] = 1, pali[i][i+1] = cad[i]==cad[i+1];
        for (j = 2; j <= n; j++) for (i = 0; i < n-j; i++) {
            p = i+j; pali[i][p] = pali[i+1][p-1] & cad[i]==cad[p];
        }
        for (i = 0; i < n; i++) {
            if (pali[0][i]) { part[i] = 1; continue; }
            for (j = 0, m = INF; j < i; j++)
                if (pali[j+1][i] && part[j] < m) m = part[j];
            part[i] = m+1;
        }
        printf("Teste %d\n%d\n\n", k++, part[n-1]);
    }    
    return 0;
}

