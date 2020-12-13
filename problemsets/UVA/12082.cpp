/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int t, n;
char mapa[50][50][7], isforced[50][50], iscontr[50][50];
int viz[50][50][7][2];
char piece[7];

const int dx[] = {0, 1, 1, 0, -1, -1};
const int dy[] = {1, 0, -1, -1, 0, 1};

#define FILLED(y,x) (*mapa[y][x]?1:0)

/* retorna o numero de vizinhos de uma peca. */
int nviz(int i, int j) {
    int s = 0;
    for (int k = 0; k < 6; k++) if (FILLED(viz[i][j][k][0], viz[i][j][k][1])) s++;
    return s;
}

/* Encontra espacos forcados e controlados. */
void get_forced() {
    int i, j, k, ax;
    int vy, vx;
    memset(isforced, 0, sizeof(isforced)); memset(iscontr, 0, sizeof(iscontr));
    for (i = 1; i < 47; i++) for (j = 1; j < 47; j++) if (!FILLED(i,j)) {
        if (nviz(i, j) >= 3) {
            isforced[i][j] = 1;
            for (k = 0; k < 6; k++) {
                vy = viz[i][j][k][0], vx = viz[i][j][k][1];
                while (!FILLED(vy, vx) && nviz(vy,vx)>=1) {
                    iscontr[vy][vx] = 1;
                    ax = vy; vy = viz[ax][vx][k][0]; vx = viz[ax][vx][k][1];
                }
            }
        }
    }
}

/* Testa se a peca se encaixa e se nao cria forced com tres de mesma cor. */
bool place(int y, int x) {
    int i, k;
    int vx, vy, vvy, vvx, c;
    for (k = 0; k < 6; k++) {
        vy = viz[y][x][k][0], vx = viz[y][x][k][1];
        if (FILLED(vy, vx)) { if (mapa[vy][vx][(k+3)%6]!=piece[k]) return false; }
        else {
            for (i = 0, c = 1; i < 6; i++) {
                vvy = viz[vy][vx][i][0], vvx = viz[vy][vx][i][1];
                if (mapa[vvy][vvx][(i+3)%6]==piece[k]) c++;
            }
            if (c>=3) return false;
        }
    }
    return true;
}

int main() {

    int i, j, k;
    int x, y, vx, vy;
    int total[2];

    /* Gera grafo de vizinhos para cada posicao na matriz. */
    for (i = 0; i < 50; i++) for (j = 0; j < 50; j++) for (k = 0; k < 6; k++)
        viz[i][j][k][0] = i+dy[k], viz[i][j][k][1] = j+dx[k];
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        memset(mapa, 0, sizeof(mapa));
        for (i = 0; i < n; i++) { scanf("%d%d", &x, &y); scanf("%s", mapa[25+y][25+x]); }
        get_forced(); total[0] = total[1] = 0;
        for (i = 0; i < 5; i++) {
            scanf("%s", piece);
            for (j=0; j < 6; j++) {
                for (y = 2; y < 46; y++) for (x = 2; x < 46; x++)
                    if (FILLED(y, x) || (iscontr[y][x]&&!isforced[y][x]) || !nviz(y, x)) continue;
                    else total[isforced[y][x]] += place(y, x);
                rotate(piece, piece+1, piece+6);
            }
        }
        if (total[1]) printf("%d\n", total[1]); else printf("%d\n", total[0]);
    }
    return 0;
}
