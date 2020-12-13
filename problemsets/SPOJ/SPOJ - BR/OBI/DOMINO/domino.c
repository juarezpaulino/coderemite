#include <stdio.h>

int pecas[7][7];
int valor[7][8], in[29];
int sol[7][8], nsol;

void domino(int i, int j) {
    register int k, n, m;
    for (; i < 7; i++, j = 0) for (; j < 8; j++) if (!sol[i][j]) goto HELL;
    nsol++; return;
HELL:
    if (i+1 < 7 && !sol[i+1][j]) {
        if (valor[i][j] <= valor[i+1][j]) { n = valor[i][j]; m = valor[i+1][j]; }
        else { n = valor[i+1][j]; m = valor[i][j]; }
        if (!in[k = pecas[n][m]]) {
            sol[i][j] = sol[i+1][j] = k; in[k] = 1;
            domino(i, j); in[k] = sol[i][j] = sol[i+1][j] = 0;
        }
    }
    if (j+1 < 8 && !sol[i][j+1]) {
        if (valor[i][j] <= valor[i][j+1]) { n = valor[i][j]; m = valor[i][j+1]; }
        else { n = valor[i][j+1]; m = valor[i][j]; }\
        if (!in[k = pecas[n][m]]) {
            sol[i][j] = sol[i][j+1] = k; in[k] = 1;
            domino(i, j); in[k] = sol[i][j] = sol[i][j+1] = 0;
        }
    } 
}


int main() {

    register int i, j, k;
    int c;
    
    for (i = 0, k = 1; i <= 6; i++) for (j = i; j <= 6; j++) pecas[i][j] = k++;
    scanf("%d", &c);
    for (k = 1; k <= c; k++) {
        for (i = 0; i < 7; i++) for (j = 0; j < 8; j++) {
            scanf("%d", &valor[i][j]); sol[i][j] = 0;
        }
        for (i = 1; i <= 28; i++) in[i] = 0; nsol = 0; domino(0, 0);
        printf("Teste %d\n%d\n\n", k, nsol);
    }
    
    return 0;
}

