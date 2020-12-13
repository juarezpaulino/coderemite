/* Historico de Comandos */

#include <stdio.h>

int n;
int p[1001];
int press[1000001];
char used[1000001];


int main() {

    int i, j;
    int c;

    while (scanf("%d", &n)) {
        
        if (!n) break;
        
        for (i = 1; i <= n; i++) { scanf("%d", &p[i]); press[p[i]] = p[i]; }
        
        c = 0;
        for (i = 1; i <= n; i++) {
            c = c+press[p[i]];
            for (j = 1; j <= n; j++) used[p[j]] = 0;
            for (j = 1; j <= n; j++)
                if (!used[p[j]]) {
                    press[p[j]]++;
                    used[p[j]] = 1;
                }
            press[p[i]] = 1;
        }
        
        printf("%d\n", c);
    }  
    
    return 0;
}
