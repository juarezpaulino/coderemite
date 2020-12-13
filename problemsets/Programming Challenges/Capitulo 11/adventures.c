/* Adventures in Moving Part IV */

#include <stdio.h>
#include <stdlib.h>

#define MAXG 102
#define MAXL 201
#define FULL 200
#define HALF 100
#define MAXINT 1000000000;


typedef struct {
    int p;
    int d;
} gas;

gas g[MAXG];
int loc;
int c[MAXG][MAXL];

int possible(int n) {
    
    register int i;
    
    if (n > 0) {
        if (g[0].d > HALF)
            return 0;
        if (g[n].d > HALF)
            return 0;
    }
    else if (loc != 0) return 0;
    for (i = 1; i < n; i++)
        if (g[i].d > FULL)
            return 0;
    
    return 1;
}

int main() {
    
    int cases;
    int des, d, p;
    char str[80];
    int n;
    register int i, j, k;
    register int kmin, kmax, kmaxj;
    register int custo, min;

    scanf("%d", &cases);
    while (cases) {    
        
        scanf("%d%*c", &loc);
        des = 0;
        n = 0;
        while (gets(str)) {
            if (*str == '\0')
                break;
            sscanf(str, "%d %d", &d, &p);
            if (d > loc)
                continue;
            if ((d-des == 0) && (n != 0)) {
                if (p < g[n-1].p)
                    g[n-1].p = p;
            }
            else {
                g[n].d = d - des;
                g[n].p = p;
                des = d;
                n++;
            }
        }
        g[n].d = loc-des;
        
        if (possible(n)) {
            
            if (n == 0)
                printf("0\n");
            else {
                
                for (i = 0; i <= n; i++)
                    for (j = 0; j < MAXL; j++)
                        c[i][j] = MAXINT;
                
                c[0][HALF-g[0].d] = 0;
                kmin = HALF-g[0].d-g[1].d;
                if (kmin < 0) kmin = 0;
                kmax = FULL-g[1].d;
                
                if (n > 1)
                    for (i = kmin; i <= kmax; i++)
                        c[1][i] = (g[1].d+i-(HALF-g[0].d))*g[0].p;
                
                for (i = 2; i < n; i++) {
                    if (kmin) {
                        kmin = kmin-g[i].d;
                        if (kmin < 0) kmin = 0;
                    }   
                    kmax = FULL-g[i].d;
                    for (j = kmin; j <= kmax; j++) {
                        kmaxj = j+g[i].d;
                        min = MAXINT;
                        for (k = kmin; k <= kmaxj; k++) {
                            custo = c[i-1][k] + (g[i].d+j-k)*g[i-1].p;
                            if (custo < min)
                                min = custo;
                        }
                        c[i][j] = min;
                    }
                }
                
                kmaxj = HALF+g[n].d;
                min = MAXINT;
                for (k = kmin; k <= kmaxj; k++) {
                    custo = c[n-1][k] + (g[n].d+HALF-k)*g[n-1].p;
                    if (custo < min)
                        min = custo;
                }
                
                printf("%d\n", min);
                /*for (i = 0; i < n; i++) {
                    for (j = 0; j < MAXL; j++)
                        printf("%11d", c[i][j]);
                    putchar('\n');
                }*/
            }
        }
        else
            printf("Impossible\n");
        
        cases--;
        if (cases)
            putchar('\n');
    }
    
    return 0;
}
