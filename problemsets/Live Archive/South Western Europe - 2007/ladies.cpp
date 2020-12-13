/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXM 1001
#define MAXW 1001

int m, n;
int L[MAXM][MAXW], R[MAXW][MAXM];
int L2R[MAXM], R2L[MAXW];

void stable_marriage() {
    int i, man, wom, h, p[MAXM];
    for (i = 1; i <= m; i++) L2R[i] = -1, p[i] = 1;
    // Pra cada mulher.
    for(i = 1; i <= n; i++ ) {
        wom = i;
        while(wom>0) {
            // Busca o proximo homem na lista de preferencias ou troca com um
            // par ja feito.
            while(1) {
                man = R[wom][p[wom]++];
                if(L2R[man]<0 || L[man][wom]>L[man][L2R[man]]) break;
            }
            h = L2R[man];               // Guarda a mulher que ficou sem par.
            L2R[R2L[wom] = man] = wom;  // Casa o par
            wom = h;                    // Resolve o problema do homem sem par
        }
    }
}

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return i;
}

int main() {
    
    int i, j;
    for (int t = get_int(), f = 0; t--; ) {
        (f)?putchar('\n'):(f=1);
        n = m = get_int();
        for (i = 1; i <= n; i++) for (j = 1; j <= m; j++) R[i][j] = get_int();
        for (i = 1; i <= m; i++) for (j = 1; j <= n; j++) L[i][(get_int())] = n-j;
        stable_marriage();
        for (i = 1; i <= n; i++) printf("%d\n", R2L[i]);
    }
    return 0;
}
