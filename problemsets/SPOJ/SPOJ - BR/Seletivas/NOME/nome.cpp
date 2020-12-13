/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <string>

#define MAXM 350
#define MAXW 350

using namespace std;

int m, n;
char nome[MAXM][30];
map<string, int> mapa;
int L[MAXM][MAXW], R[MAXW][MAXM];
int L2R[MAXM], R2L[MAXW];

void stable_marriage() {
    int i, man, wom, h, p[MAXM];
    for (i = 1; i <= n; i++) R2L[i] = -1, p[i] = 1;
    for(i = 1; i <= m; i++ ) {
        man = i;
        while(man>0) {
           while(1) {
               wom = L[man][p[man]++];
               if(R2L[wom]<0 || R[wom][man]>R[wom][R2L[wom]]) break;
           }
           h = R2L[wom];               // Guarda a mulher que ficou sem par.
           R2L[L2R[man] = wom] = man;  // Casa o par
           man = h;                    // Resolve o problema do homem sem par
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
    char str[30];
    for (int t = get_int(); t--; ) {
        n = m = get_int(); mapa.clear();
        for (i = 1; i <= m; i++) {
            scanf(" %s", nome[i]); mapa[nome[i]] = i;
            for (j = 1; j <= n; j++) L[i][j] = get_int();   
        }
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) scanf(" %s", str), R[i][mapa[str]] = m-j;
        }
       stable_marriage();
       for (i = 1; i <= n; i++) printf("%s\n", nome[R2L[i]]);
       putchar('\n');
   }
   return 0;
}

