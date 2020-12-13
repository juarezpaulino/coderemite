#include <stdio.h>
#include <string.h>


////////////////////////////////////////////////////////////////////////////////
// Reconhecimento de palavras. CYK para FNC O(|w|^3):
// A -> BC  | A -> a
//
#define MAXW 60
#define MAXC 127

char S;
char pred[MAXC][MAXC], fol[MAXC][MAXC], dir[MAXC][MAXC], v[MAXW][MAXW][MAXC];
int npred[MAXC], nfol[MAXC], ndir[MAXC], nv[MAXW][MAXW];
char inv[MAXW][MAXW][MAXC];


void compile() {
    int i; char c1, c2;
    char str[MAXW];
    
    for (i = 0; i < MAXC; i++) {
        npred[i] = 0; nfol[i] = 0; ndir[i] = 0;
    }
    while (gets(str)) {
        if (!strcmp(str, "# -> #")) break;
        if (str[6]) {
            c1 = str[5]; c2 = str[6];
            pred[c1][npred[c1]++] = *str; fol[c1][nfol[c1]++] = c2;
        }
        else {
            c1 = str[5];
            dir[c1][ndir[c1]++] = *str;
        }
    }
}

char CYK(char *word) {
    int n, r, s, k;
    int i, j, l;
    char c1, c2;
    for (r = 1; word[r-1] != '\0'; r++) {
        c1 = word[r-1]; nv[1][r] = ndir[c1]; memset(inv[1][r], 0, sizeof(inv[1][r]));
        for (i = 0; i < ndir[c1]; i++) {
            c2 = dir[c1][i];
            v[1][r][i] = c2; inv[1][r][c2] = 1;
        }
    }
    n = r-1;
    nv[n][1] = 0;
    for (s = 2; s <= n; s++)
        for (r = 1; r <= n-s+1; r++) {
            nv[s][r] = 0; memset(inv[s][r], 0, sizeof(inv[s][r]));
            for (k = 1; k <= s-1; k++)
                for (i = 0; i < nv[k][r]; i++) {
                    c2 = v[k][r][i];
                    for (j = 0; j < nfol[c2]; j++)
                        if (inv[s-k][r+k][fol[c2][j]]) {
                            if (!inv[s][r][pred[c2][j]]) 
                                v[s][r][nv[s][r]++] = pred[c2][j]; 
                            inv[s][r][pred[c2][j]] = 1;
                        }
                }
        }
        
    if (inv[n][1][S]) return 1;
    return 0;
}


int main() {

    int k = 1;
    char str[MAXW];
    char c1, c2;

    while (gets(str)) {
        S = *str;
        gets(str); gets(str);
        compile();

        printf("Instancia %d\n", k++);
        while (gets(str)) {
            if (*str == '#') break;
            if (CYK(str)) printf("%s e uma palavra valida\n", str);
            else printf("%s nao e uma palavra valida\n", str);
        }
        putchar('\n');
    }

    return 0;
}
