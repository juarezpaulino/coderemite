/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/* Seletiva USP 2009 - Problema K - monopolio.cpp 
 *
 * Tecnica: Simulacao.
 *
 * Entrada: Numero de lados no dado e tabuleiro.
 * Saida: Probabilidade de convergencia para cada casa no tabuleiro. 
 *
 * Tecnica: Simular as casas atingiveis ate que a diferenca de probabilidades
 * seja de acordo com as casas decimais exigidas.
 *
 */ 


#include <stdio.h>
#include <math.h>

#define EPS 1E-6

double p[2][1000]; int e;
int tab[1000];
int n, d;

int get_int() {
    int ch, i, s;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    s = (ch=='-') ? ch=getchar(),-1 : 1;
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return s*i;
}

int main() {
    
    int i, j;
    double q;
    for (; n = get_int(), d = get_int(), n+d;) {
        for (i = 0; i < n; i++) { tab[i] = get_int(); if (tab[i]==-1) tab[i]=i; }
        for (i = 1; i < n; i++) p[0][i] = 0.; p[0][0] = 1.0;
        e = 1; q = 1./d;
HELL:
        for (i = 0; i < n; i++) p[e][i] = 0.;
        for (i = 0; i < n; i++) if (tab[i]==i && p[e^1][tab[i]]>EPS)
            for (j = 1; j <= d; j++)
                p[e][tab[(i+j)%n]] += p[e^1][i]*q;
        for (i = 0; i < n; i++) if (fabs(p[e][i]-p[e^1][i]) > EPS) break;
        if (i < n) { e^=1; goto HELL; }
        
        printf("%.3lf", p[e][0]*100.);
        for (i = 1; i < n; i++) printf(" %.3lf", p[e][i]*100.);
        putchar('\n');
    }
    
    return 0;
}
