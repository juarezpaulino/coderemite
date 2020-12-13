/* Jogo dos 8-numeros */
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

/* O valor '0' representa o vazio. */
int sol[SIZE][SIZE];          /* Estado solucao */
int ini[SIZE][SIZE];          /* Estado inicial definido */
char str[100000];
int ns;

int f_h1(int est[][SIZE]) {
    int f;
    int i, j;
    f = 0;
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            if (sol[i][j] != est[i][j]) f++;
    return (f);
}
char get_dir(int est[][SIZE], int k, int x, int y) {
    int i, j;
    int m = 1000000;
    int f;
    char dir;
    int e[4][SIZE][SIZE];
    if (((k == 0) || ((k>0)&&(str[k-1] != 'B'))) && (x > 0)) {
        for (i = 0; i < SIZE; i++) for (j = 0; j < SIZE; j++) e[0][i][j] = est[i][j];
        e[0][x][y] = e[0][x-1][y]; e[0][x-1][y] = 0;
        f = f_h1(e[0]);
        if (m > f) { m = f; dir = 'C'; }
    }
    if (((k == 0) || ((k>0)&&(str[k-1] != 'C'))) && (x < SIZE-1)) {
        for (i = 0; i < SIZE; i++) for (j = 0; j < SIZE; j++) e[1][i][j] = est[i][j];
        e[1][x][y] = e[1][x+1][y]; e[1][x+1][y] = 0;
        f = f_h1(e[1]);
        if (m > f) { m = f; dir = 'B'; }
    }
    if (((k == 0) || ((k>0)&&(str[k-1] != 'D'))) && (y > 0)) {
        for (i = 0; i < SIZE; i++) for (j = 0; j < SIZE; j++) e[2][i][j] = est[i][j];
        e[2][x][y] = e[2][x][y-1]; e[2][x][y-1] = 0;
        f = f_h1(e[2]);
        if (m > f) { m = f; dir = 'E'; }
    }
    if (((k == 0) || ((k>0)&&(str[k-1] != 'E'))) && (y < SIZE-1)) {
        for (i = 0; i < SIZE; i++) for (j = 0; j < SIZE; j++) e[3][i][j] = est[i][j];
        e[3][x][y] = e[3][x][y+1]; e[3][x][y+1] = 0;
        f = f_h1(e[3]);
        if (m > f) { m = f; dir = 'D'; }
    }
    if (dir == 'C') m = 0;
    else if(dir == 'B') m = 1;
    else if (dir == 'E') m = 2;
    else m = 3;
    
    for (i = 0; i < 3; i++) for (j = 0; j < 3; j++) est[i][j] = e[m][i][j];
    return (dir);
}
int ehSolucao(int est[][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) 
        for (j = 0; j < SIZE; j++) 
            if (est[i][j] != sol[i][j])
                return (0);
    return (1);
}
void backtrack(int est[][SIZE], int k, int x, int y) {
    
    char dir;
    if (ehSolucao(est)) {
        ns = k;
        return;
    }
    dir = get_dir(est, k, x, y);
    if (dir == 'C') x = x-1;
    else if(dir == 'B') x = x+1;
    else if (dir == 'E') y = y-1;
    else y = y+1;
    str[k] = dir;
    printf("%d %c\n", k, str[k]);
    backtrack(est, k+1, x, y);
}

int main() {
    int i;
    sol[0][0] = 1; sol[0][1] = 2; sol[0][2] = 3; sol[0][3] = 4; sol[0][4] = 5;
    sol[1][0] = 6; sol[1][1] = 7; sol[1][2] = 8; sol[1][3] = 9; sol[1][4] = 10;
    sol[2][0] = 11; sol[2][1] = 12; sol[2][2] = 13; sol[2][3] = 14; sol[2][4] = 15;
    sol[3][0] = 16; sol[3][1] = 17; sol[3][2] = 18; sol[3][3] = 19; sol[3][4] = 20;
    sol[4][0] = 21; sol[4][1] = 22; sol[4][2] = 23; sol[4][3] = 24; sol[4][4] = 0;
    
    ini[0][0] = 6; ini[0][1] = 12; ini[0][2] = 21; ini[0][3] = 8; ini[0][4] = 16;
    ini[1][0] = 1; ini[1][1] = 17; ini[1][2] = 11; ini[1][3] = 13; ini[1][4] = 19;
    ini[2][0] = 5; ini[2][1] = 20; ini[2][2] = 0; ini[2][3] = 10; ini[2][4] = 18;
    ini[3][0] = 3; ini[3][1] = 4; ini[3][2] = 7; ini[3][3] = 9; ini[3][4] = 22;
    ini[4][0] = 2; ini[4][1] = 24; ini[4][2] = 14; ini[4][3] = 23; ini[4][4] = 15;
        
    printf("-----> Resolvendo o Jogo dos 24 Numeros com A* (h1):\n\n");
    printf("\t\t-------------------------------\n");
    printf("\t\t|  6  | 12  | 21  |  8  | 16  |\n");
    printf("\t\t|-----|-----|-----|-----|-----|\n");
    printf("\t\t|  1  | 17  | 11  | 13  | 19  |\n");
    printf("\t\t|-----|-----|-----|-----|-----|\n");
    printf("\t\t|  5  | 20  |  0  | 10  | 18  |\n");
    printf("\t\t|-----|-----|-----|-----|-----|\n");
    printf("\t\t|  3  |  4  |  7  |  9  | 22  |\n");
    printf("\t\t|-----|-----|-----|-----|-----|\n");
    printf("\t\t|  2  | 24  | 14  | 23  | 15  |\n");
    printf("\t\t-------------------------------\n\n");
    printf("Legenda: C - vazio cima\n");
    printf("         B - vazio baixo\n");
    printf("         E - vazio esquerda\n");
    printf("         D - vazio direita\n\n");
    printf("-----> Sequencia de Movimentos para a solucao: ");
    backtrack(ini, 0, 2, 2);
    putchar(str[0]);
    for (i = 1; i < ns; i++) printf(" %c", str[i]);
    return 0;
}
