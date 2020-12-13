/* Cutting sticks */

#include <stdio.h>

#define MAXCUTS 52
#define MAXVALUE 10000


int main() {

    unsigned m[MAXCUTS][MAXCUTS];
    unsigned sticks[MAXCUTS][MAXCUTS];
    unsigned L, n, x, y;
    int i, j, k, l, q, t;

    while (scanf("%u", &L)) {
        
        if (L == 0)
            break;
    
        scanf("%u", &n);
        y = 0;
        for (i = 1; i <= n; i++) {
            scanf("%u", &x);
            sticks[i][i] = x - y;
            y = x;
        }
        sticks[i][i] = L - y;
        n++;
        
        for (i = 1; i <= n; i++)
            for (j = i+1; j <= n; j++)
                sticks[i][j] = sticks[i][j-1] + sticks[j][j];
        
        m[0][0] = 0;
        for (i = 1; i <= n; i++) {
            m[i][i+1] = sticks[i][i] + sticks[i+1][i+1];
            m[i][i] = 0;
        }
        
        for (l = 3; l <= n; l++)
            for (i = 1; i <= n-l+1; i++) {
                j = i + l - 1;
                m[i][j] = MAXVALUE;
                for (k = i; k <= j-1; k++) {
                    q = m[i][k] + m[k+1][j] + sticks[i][j];
                    if (q < m[i][j])
                        m[i][j] = q;
                }
            }
        
        printf("The minimum cutting is %u.\n", m[1][n]);
    }
    
    return 0;
}
