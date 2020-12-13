/* Pebbles */


#include <stdio.h>
#include <stdlib.h>

#define MAX 32768

#define SET(a,p) ((a) | (1 << (p)))


typedef struct {
    int val;
    int bmp;
} pebble;

pebble pb[2][MAX];
int board[15][15];
int n, m;
int nk[2];
int max;

void place(int l, int k, int val, int bmp) {
    
    int i;
    int v, b;
    
    for (i = k; i < n; i++) {
        v = val+board[l][i];
        b = SET(bmp, i);
        pb[m][nk[m]].val = v;
        pb[m][nk[m]++].bmp = b;
        place(l, i+2, v, b);
    }
}

int cmp(pebble *a, pebble *b) {

    return (b->val - a->val);    
}


void solve(int l) {

    int i, j;
    int cmp();
    int x;
    
    nk[m] = 1;
    pb[m][0].val = pb[m][0].bmp = 0;
    
    place(l, 0, 0, 0);
    
    if (l) {
        qsort(pb[m^1], nk[m^1], sizeof(pebble), cmp);
        for (i = 0; i < nk[m]; i++) {
            for (j = 0; j < nk[m^1]; j++) 
                if (!(pb[m][i].bmp & pb[m^1][j].bmp) && 
                    !(pb[m][i].bmp & (pb[m^1][j].bmp<<1)) &&
                    !(pb[m][i].bmp & (pb[m^1][j].bmp>>1)) ) {
                    
                    x = pb[m][i].val + pb[m^1][j].val;
                    if (x > pb[m][i].val) pb[m][i].val = x;
                    if (x > max) max = x;
                    break;
                }
        }
    }
    else for (i = 0; i < nk[m]; i++) if (pb[m][i].val > max) max = pb[m][i].val;
    
    m^=1;
}


int main() {
    
    char ch;
    int i, j;
    int x;
    
    while (1) {
        n = 0; ch = 0;
        while (ch != '\n') {
            if (scanf("%d%c", &x, &ch) == EOF) return 0;
            board[0][n] = x;
            n++;   
        }
        for (i = 1; i < n; i++)
            for (j = 0; j < n; j++)
                scanf("%d ", &board[i][j]);
            
        m = max = 0;
        for (i = 0; i < n; i++) solve(i);
        printf("%d\n", max);
    }
    
    return 0;   
}
