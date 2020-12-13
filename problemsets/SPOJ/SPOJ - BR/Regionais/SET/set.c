#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM(x) ((x) & 3)
#define FIG(x) ((x) & 12)

int n;
int card[16];       /* Conjunto inicial de cartas. */
char dif_set[30][3];    /* Conjuntos válidos com cartas diferentes. */
int n_dif_set;
int max;

int valida(char c1, char c2, char c3) {

    char fig, num;

    fig = (FIG(c1) == FIG(c2)) && (FIG(c1) == FIG(c3));
    if (!fig) fig = (FIG(c1) != FIG(c2)) && (FIG(c1) != FIG(c3)) && (FIG(c2) != FIG(c3));

    num = (NUM(c1) == NUM(c2)) && (NUM(c1) == NUM(c3));
    if (!num) num = (NUM(c1) != NUM(c2)) && (NUM(c1) != NUM(c3)) && (NUM(c2) != NUM(c3));

    return (fig && num);
}


void permutate(int k, int s) {
    
    int i, j;
    
    if (max == n/3) return;
    
    if (k == n_dif_set) {
        for (i = 0; i < 16; i++) s += card[i]/3;
        if (s > max) max = s;
        return;
    }
    
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++)
            if (card[dif_set[k][j]] >= i)
                card[dif_set[k][j]] -= i;
            else break;
        if (j == 3) permutate(k+1, s+i);
        for (j = j-1; j >= 0; j--) card[dif_set[k][j]] += i;
    }
}


int main() {

    char num[15], sim[15];
    char hand[50];
    int i, j, k;
    char x;
    char val[] = { 5, 6, 7, 9, 10, 11, 13, 14, 15 };

    /* Gera os conjuntos diferentes possiveis. */
    n_dif_set = 0;
    for (i = 0; i < 9; i++)
        for (j = i+1; j < 9; j++)
            for (k = j+1; k < 9; k++)
                if (valida(val[i], val[j], val[k])) {
                    dif_set[n_dif_set][0] = val[i];
                    dif_set[n_dif_set][1] = val[j];
                    dif_set[n_dif_set][2] = val[k];
                    n_dif_set++;
                }
                
    while (scanf("%d ", &n)) {

        if (!n) break;

        for (i = 0; i < 16; i++) card[i] = 0;

        for (i = 0; i < n; i++) {
            scanf("%s %s ", num, sim);
            if (!strcmp(num, "um")) x = 1;
            else if (!strcmp(num, "dois")) x = 2;
            else x = 3;
            if (!strcmp(sim, "circulo") || !strcmp(sim, "circulos")) x |= 4;
            else if (!strcmp(sim, "quadrado") || !strcmp(sim, "quadrados")) x |= 8;
            else x |= 12;
            card[x]++;
        }
                
        max = 0;
        permutate(0, 0);
        
        printf("%d\n", max);
    }

    return 0;
}
