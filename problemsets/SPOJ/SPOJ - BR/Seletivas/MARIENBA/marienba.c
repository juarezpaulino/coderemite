#include <stdio.h>

char game[2][4][6][8][10][12];


int main() {

    int i, j, k, l, m, n, o;
    char st;
    int z, c;
    
    game[0][0][0][0][0][0] = 1;
    for (i = 0; i < 2; i++)
    for (j = 0; j < 4; j++)
    for (k = 0; k < 6; k++)
    for (l = 0; l < 8; l++)
    for (m = 0; m < 10; m++)
    for (n = 0; n < 12; n++) {
        if (!i&&!j&&!k&&!l&&!m&&!n) continue;
        st = 1;
        for (o = i-1; (o >= 0) && st; o--) st &= game[o][j][k][l][m][n];
        for (o = j-1; (o >= 0) && st; o--) st &= game[i][o][k][l][m][n];
        for (o = k-1; (o >= 0) && st; o--) st &= game[i][j][o][l][m][n];
        for (o = l-1; (o >= 0) && st; o--) st &= game[i][j][k][o][m][n];
        for (o = m-1; (o >= 0) && st; o--) st &= game[i][j][k][l][o][n];
        for (o = n-1; (o >= 0) && st; o--) st &= game[i][j][k][l][m][o];
        game[i][j][k][l][m][n] = st^1;
    }
    
    scanf("%d", &z);
    for (c = 1; c <= z; c++) {
        printf("Instancia %d\n", c);
        scanf("%d %d %d %d %d %d", &i, &j, &k, &l, &m, &n);
        if (game[i][j][k][l][m][n]) puts("sim\n");
        else puts("nao\n");
    }
    
    return 0;
}
