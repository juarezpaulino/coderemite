/* Visible Lattice Points */

#include <stdio.h>

int n;
int lattice[1001];
char v[1001][1001];

int main() {
    
    int i, j;
    int x, y;
    int c;
   
    for (i = 0; i <= 1000; i++) { v[0][i] = 1; v[i][0] = 1; }
    c = 2; 
    for (n = 1; n <= 1000; n++) {
        for (i = 1; i <= n; i++)
            if (!v[i][n]) {
                c++;
                for (j = i; (j <= 1000) && ((y = n*(j/i)) <= 1000); j += i) 
                    v[j][y] = 1;
            }
        for (i = 1; i <= n-1; i++)
            if (!v[n][i]) {
                c++;
                for (j = i; (j <= 1000) && ((x = n*(j/i)) <= 1000); j += i) 
                    v[x][j] = 1;
            }
        lattice[n] = c;
    }
   
    scanf("%d", &c);
    for (i = 1; i <= c; i++) {
        scanf("%d", &n);    
        printf("%d %d %d\n", i, n, lattice[n]);
    }
    
    return 0;
}
