#include <stdio.h>

int in[101][101], nin[101];
int deg[101], dep[101];
char marc[101][101];
int n;


int main() {
    
    int i, j, v, k, max, num;
    int t, x;
    
    while (scanf("%d", &n)) {
        if (!n) break;
        for (i = 1; i <= n; i++) { 
            nin[i] = dep[i] = 0; for (j = 1; j <= n; j++) marc[i][j] = 0;
            marc[i][i] = 1;
        }
        for (i = 1; i <= n; i++) {
            scanf("%d", &t); deg[i] = t;
            for (j = 0; j < t; j++) { scanf("%d", &x); in[x][nin[x]++] = i; }
        }
        k = max = 0;
        while (k < n) {
            for (i = 1; i <= n; i++) if (!deg[i]) {
                if (max < dep[i]) { max = dep[i]; num = i; } deg[i]--; k++;
                for (j = 0; j < nin[i]; j++) {
                    for (v = 1; v <= n; v++) if (marc[i][v] && !marc[in[i][j]][v]) {
                        marc[in[i][j]][v] = 1; dep[in[i][j]]++;
                    }
                    deg[in[i][j]]--;
                }
            }
        }
        printf("%d\n", num);
    }
    
    return 0;
}
