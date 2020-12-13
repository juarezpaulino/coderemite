/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int t, c, n;
int px[100000], py[100000], w[100000];
// Melhor custo pra levar ate o i-esimo pacote
int dp[100000];
// Vetor auxiliar que armazena as diferencas absolutas entre os pontos.
// para calcular dist[i][j] = dif[j]-dif[i]
int dif[100000];


#define INF 0x3F3F3F3F

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return i;
}


int main() {

    int i, j, k, l, s, tot, f = 0;

    for (t = get_int(); t--; ) {
        if (f) putchar('\n');
        c = get_int(), n = get_int();
        for (i = 0; i < n; i++) px[i] = get_int(), py[i] = get_int(), w[i] = get_int();
        dif[0] = 0;
        for (i = 1; i < n; i++) dif[i] = dif[i-1]+abs(px[i]-px[i-1])+abs(py[i]-py[i-1]);
        for (i = j = tot = 0; i < n; i++) {
            tot += w[i]; while (tot > c) tot-=w[j++];
            /* Calcula o melhor custo para carregar ate o i-esimo. */
            dp[i] = (!i) ? ((px[i]+py[i])<<1) : dp[i-1]+((px[i]+py[i])<<1);
            for (k = j; k < i; k++) {
                s = (!k) ? px[k]+py[k] : dp[k-1]+px[k]+py[k];
                s += dif[i]-dif[k];
                s += px[i]+py[i]; dp[i]=min(dp[i],s);
            }
        }
        printf("%d\n", dp[n-1]); f = 1;
    }
    return 0;
}
