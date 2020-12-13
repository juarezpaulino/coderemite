#include <stdio.h>
#include <stdlib.h>



int n;
char card1[5000], card2[5000];
int ncard1, ncard2;
char c1[30], c2[30];
int nc1, nc2;
int pf1, pf2, cm1, cm2;
int h1;

int cmp(char *a, char *b) {
    
    return (*a - *b);
}

void triples(char c[], int nc, int k, int pos, char hand[], char inperm[], int *cm) {
    
    int st, end;
    int i, j;
    char h2;
    
    if (*cm == nc/3) return;

    if (!(k%3)) {
        if (k/3 > *cm) *cm = k/3;
        if (nc-k < 3) return;
    }
    
    if (!k) { st = 0; end = nc-3; }
    else if (!(k%3)) {
        for (i = h1; i < nc; i++) if (!inperm[i]) break;
        st = i; end = nc-3;
    }
    else {
        st = pos+1; end = nc-(3-(k%3));
    }
    
    for (i = st; i <= end; i++) {
        if (!k) h1 = i;
        if (!inperm[i]) {
            if ((k%3 == 2) && (c[i] >= hand[k-1] + hand[k-2])) continue;
            if ((i != st) && (c[i] == hand[k])) continue;
            if (k/3) {
                for (j = k%3; j > 0; j--) {
                    if (hand[k-j] > hand[(k-j)-3]) { h2 = 0; break; }
                    else if (hand[k-j] < hand[(k-j)-3]) { h2 = 1; break; }
                }
                if (j == 0) { h2 = ((c[i] >= hand[k-3]) ? 0 : 1); }
                if (h2) continue;
            }
            inperm[i] = 1;
            hand[k] = c[i];
            triples(c, nc, k+1, i, hand, inperm, cm);
            inperm[i] = 0;
        }
    }
    hand[k] = -1;
}



int main() {
    
    int x;
    int i;
    char inperm[30];
    char hand[30];
    int cmp();

    while (scanf("%d", &n)) {
        if (!n) break;
        
        ncard1 = ncard2 = 0;
        for (i = 0; i < n; i++) {
            scanf("%d", &x);
            if (i & 1) card2[ncard2++] = x;
            else card1[ncard1++] = x;   
        }
        
        qsort(card1, ncard1, 1, cmp);
        qsort(card2, ncard2, 1, cmp);
        
        /* Retira as triplas perfeitas. */
        pf1 = pf2 = nc1 = nc2 = 0;
        
        for (i = 0; i < ncard1-2; i++) {
            if ((card1[i] == card1[i+1]) && (card1[i] == card1[i+2])) {
                pf1++;
                i += 2;
            }
            else c1[nc1++] = card1[i];
        }
        if (i == ncard1-2) { c1[nc1++] = card1[i++]; c1[nc1++] = card1[i]; }
        else if (i == ncard1-1) { c1[nc1++] = card1[i]; }
        
        for (i = 0; i < ncard2-2; i++) {
            if ((card2[i] == card2[i+1]) && (card2[i] == card2[i+2])) {
                pf2++;
                i += 2;
            }
            else c2[nc2++] = card2[i];
        }
        if (i == ncard2-2) { c2[nc2++] = card2[i++]; c2[nc2++] = card2[i]; }
        else if (i == ncard2-1) { c2[nc2++] = card2[i]; }
        
        if (pf1 > pf2) { puts("1"); continue; }
        if (pf2 > pf1) { puts("2"); continue; }
        
        /* Calcula as triplas comuns. */
        cm1 = cm2 = 0;
        for (i = 0; i < nc1; i++) { inperm[i] = 0; hand[i] = -1; }
        triples(c1, nc1, 0, -1, hand, inperm, &cm1);
        triples(c2, nc2, 0, -1, hand, inperm, &cm2);
        
        if (cm1 > cm2) { puts("1"); continue; }
        if (cm2 > cm1) { puts("2"); continue; }
        puts("0");
    }
    
    return 0;
}
