#include <stdio.h>

char lin[10][10];
char col[10][10];
char reg[10][10];


int main() {
    
    int n, k;
    int i, j, m;
    int num;
    char nao;
    
    scanf("%d", &n);
    for (k = 1; k <= n; k++) {
        for (i = 1; i <= 9; i++)
            for (j = 1; j <= 9; j++)
                lin[i][j] = col[i][j] = reg[i][j] = 0;
        nao = 0;
        for (i = 1; i <= 9; i++) {
            for (j = 1; j <= 9; j++) {
                scanf("%d", &num);
                if (nao) continue;
                m = ((i-1)/3)*3 + ((j-1)/3) + 1;
                if (lin[i][num] || col[j][num] || reg[m][num]) nao = 1;
                lin[i][num] = col[j][num] = reg[m][num] = 1;
            }
        }
        printf("Instancia %d\n", k);
        if (nao) puts("NAO\n");
        else puts("SIM\n");
    }
    
    return 0;
}
