/* Shuffle'm Up */

#include <stdio.h>

int n, c;
char S12[202];
char S1[101], S2[101];

int cmp(char S1[], char S2[]) {
    
    int i;
    
    for (i = 0; i < 2*c; i++) if (S1[i] != S2[i]) return 0;
    return (1);
}

void shuffle(char D[], char S[]) {
    
    int i;
    
    for (i = 0; i < c<<1; i+=2) D[i] = S[c+(i>>1)];
    for (i = 1; i < c<<1; i+=2) D[i] = S[i>>1];
}


int main() {
    
    int i, j;
    int k;
    int num;
    char solved;
    char S[2][202];
    char F[202];
    
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d ", &c);
        for (j = 0; j < c-1; j++) scanf("%c", &S1[j]);
        scanf("%c ", &S1[j]);
        for (j = 0; j < c-1; j++) scanf("%c", &S2[j]);
        scanf("%c ", &S2[j]);
        for (j = 0; j < 2*c; j++) scanf("%c", &S12[j]);
        
        printf("%d ", i);
        for (j = 0; j < c; j++) S[0][j<<1] = F[j<<1] = S2[j]; 
        for (j = 0; j < c; j++) S[0][(j<<1)+1] = F[(j<<1)+1] = S1[j];
        if (cmp(S[0], S12)) { printf("1\n"); continue; }
        k = 1; solved = 0;
        for (num = 2; ; num++) {
            shuffle(S[k], S[k^1]);
            if (cmp(S[k], F)) break;
            if (cmp(S[k], S12)) { solved = 1; break; }
            k = k^1;
        }
        
        if (solved) printf("%d\n", num);
        else printf("-1\n");
    }
    
    return 0;
}
