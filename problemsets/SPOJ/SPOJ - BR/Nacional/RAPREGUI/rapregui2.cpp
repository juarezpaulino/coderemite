/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define INF 0x3F3F3F3F
#define NULO -1
#define EPS 1e-13


#define MAXV 1004
#define OFF -2
#define WAT -1
#define FREE 0
#define MAXVAL 1800
#define MAXENT 2000
const int ene[5][5] = {
  {7,6,5,6,7},
  {6,3,2,3,6},
  {5,2,0,2,5},
  {6,3,2,3,6},
  {7,6,5,6,7}
};

typedef struct {
    short x, y;
} vert;


int custo[MAXV][MAXV];
char board[MAXV][MAXV];
int c, r;
int xf, yf;

vert val[MAXVAL][MAXENT];
short nval[MAXVAL], min;


/* Heuristica A* */
int h(int xi, int yi) {
	int nL, nC, diag;

	nL = abs(xf-xi);
	nC = abs(yf-yi);
	diag = nL<nC ? nL : nC;
	nL -= diag;
	nC -= diag;

	return diag*3 + 2*abs(nL-nC);
}


int next(int* x, int* y) {
    int i, t = 0;
    min = min % MAXVAL;
    do {
        while (!nval[min]) {
            min = (min + 1) % MAXVAL;
            if (++t == MAXVAL) return 0;
        }
        i = --nval[min];
        *x = val[min][i].x;
        *y = val[min][i].y;
    } while (((custo[*y][*x]+h(*y, *x)) % MAXVAL) != min);
    return 1;
}

int insert(int x, int y, int k) {
    k %= MAXVAL;
    int i = nval[k]++;
    val[k][i].x = x; val[k][i].y = y;
}

void dijkstra(int rs, int cs, int rt, int ct) {
    register int i, j, c1, c2, r1, r2, d;
    int rv, cv;
    char sim, w1,w2,w3,w4,w5,w6,w7,w8;
    min = 2;
    memset(nval, 0, sizeof(nval));
    custo[rs][cs] = 0;
    for (rv = rs, cv = cs; (rv != rt || cv != ct) && board[rv][cv] == FREE;) {
        sim = 1; w1=w2=w3=w4=w5=w6=w7=w8=0;
        if (board[rv][cv+1] == WAT) { sim = 0; w1 = 1; }
        if (board[rv][cv-1]) { sim = 0; w3 = 1; }
        if (board[rv+1][cv]) { sim = 0; w2 = 1; }
        if (board[rv-1][cv]) { sim = 0; w4 = 1; }
        if (board[rv-1][cv-1]) { sim = 0; w5 = 1; }
        if (board[rv+1][cv+1]) { sim = 0; w6 = 1; }
        if (board[rv-1][cv+1]) { sim = 0; w7 = 1; }
        if (board[rv+1][cv-1]) { sim = 0; w8 = 1; }
        c1 = r1 = -2; c2 = r2 = 2;
        if (sim) { c1++,c2--,r1++,r2--; }
        else {
            if (!w8 && !w3 && !w5) c1++;
            if (!w6 && !w1 && !w7) c2--;
            if (!w5 && !w4 && !w7) r1++;
            if (!w8 && !w2 && !w6) r2--;
        }
        for (i = r1; i <= r2; ++i) for (j = c1; j <= c2; ++j) {
            d = custo[rv][cv] + ene[i+2][j+2];
            if (board[rv+i][cv+j]==FREE && custo[rv+i][cv+j]> d) {
                custo[rv+i][cv+j] = d;
                insert(cv+j, rv+i, d+h(rv+i, cv+j));
            }
        }
        if (!next(&cv, &rv)) break;
    }
}

char buff[1000000];
int pos;


int get_int() {
    int ch = buff[pos++], i;
    while ((ch == ' ') || (ch == '\n')) ch = buff[pos++];
    if (ch == 0) exit(0);
    for (i = 0; ch >= '0' && ch <= '9'; ch = buff[pos++]) i = 10*i + (ch-'0');
    return i;
}


int main() {

    int cs, rs, ct, rt;
    int c1, r1, c2, r2, b;
    int i, j, k;

    fread(buff, 1, 1000000, stdin);
    while (1) {
        c = get_int(); r = get_int();
        if (!c && !r) break;
        for (i = 0; i < c+4; i++)
            board[0][i] = board[1][i] = board[r+2][i] = board[r+3][i] = OFF;
        for (i = 0; i < r+4; i++)
            board[i][0] = board[i][1] = board[i][c+2] = board[i][c+3] = OFF;
        for (i = 2; i < r+2; i++) for (j = 2; j < c+2; j++)
            board[i][j] = FREE,
            custo[i][j] = INF;
        cs = get_int(); rs = get_int(); ct = get_int(); rt = get_int(); b = get_int();
        ++rs, ++cs, ++rt, ++ct; xf = rt; yf = ct;
        for (k = 0; k < b; k++) {
            c1 = get_int(); r1 = get_int(); c2 = get_int(); r2 = get_int();
            ++c1, ++c2, ++r1, ++r2;
            for (i = r1; i <= r2; ++i) for (j = c1; j <= c2; ++j)
                board[i][j] = WAT;
        }
        dijkstra(rs, cs, rt, ct);
        if (custo[rt][ct] >= INF) printf("impossible\n");
        else printf("%d\n", custo[rt][ct]);
    }

    return 0;
}

