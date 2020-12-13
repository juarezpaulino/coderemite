/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


using namespace std;

#define TRACE(x...)
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x" = " << x << "\n")
#define _inline(f...) f() __attribute__((always_inline)); f
#define _foreach(it, b, e) for (typeof(b) it = (b); it != (e); it++)
#define foreach(x...) _foreach(x)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

const int INF = 0x3F3F3F3F;
const int NULO = -1;
const double EPS = 1e-13;

_inline(int cmp)(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

#define MAXV 1004
#define OFF -2
#define WAT -1
#define FREE 0
#define MAXVAL 8
#define MAXENT 2000
const int ene[5][5] = {
  {7,6,5,6,7},
  {6,3,2,3,6},
  {5,2,0,2,5},
  {6,3,2,3,6},
  {7,6,5,6,7}
};

struct vert {
    int x, y;
};


int custo[MAXV][MAXV];
int board[MAXV][MAXV];
int c, r;

vert val[MAXVAL][MAXENT];
int nval[MAXVAL], min;


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
    } while ((custo[*y][*x] % MAXVAL) != min);
    return 1;
}
 
_inline(int insert)(int x, int y, int k) {
    k %= MAXVAL;
    int i = nval[k]++;
    val[k][i].x = x; val[k][i].y = y;
}

int heur(int rs, int cs, int rt, int ct){
    int i;
    bool flag;
    int dx,dy;
    int sinalx,sinaly;

    dx = abs(cs - ct);
    dy = abs(rs - rt);
    sinalx = 1;
    sinaly = 1;
    if ( cs > ct ) sinalx = -1;
    if ( rs > rt ) sinaly = -1;

    /* diagonal */
    flag = true;
    if (dx == dy){
        i = 1;
        while (i++ < dx) if (board[rs+(i*sinaly)][cs+(i*sinalx)] == WAT) {flag = false; break;}
        if ( flag ) { custo[rt][ct] = dx*3; return 1; }
    }
    
    /* reta  x */
    flag = true;
    if (dy == 0){
    i = 1;
    while (i++ < dx) if (board[rs][cs+(i*sinalx)] == WAT) { flag = false; break;}
    if (flag) { custo[ct][rt] = dx*2; return 1; }
    }
    
    /* reta  y */
    flag = true;
    if (dx == 0){
    i = 1;
    while (i++ < dy) if ( board[rs+(i*sinaly)][cs] == WAT) {flag = false; break;}
    if (flag) { custo[ct][rt] = dy*2; return 1; }
    }
    return 0;
}

void dijkstra(int rs, int cs, int rt, int ct) {
    register int i, j, c1, c2, r1, r2, d;
    bool sim, w1,w2,w3,w4,w5,w6,w7,w8;
    min = 2;
    memset(nval, 0, sizeof(nval));
    custo[rs][cs] = 0;
    for (int rv = rs, cv = cs; (rv != rt || cv != ct) && board[rv][cv] == FREE;) {
        sim = true; w1=w2=w3=w4=w5=w6=w7=w8=false;
        if (board[rv][cv+1] == WAT) { sim = false; w1 = true; }
        if (board[rv][cv-1]) { sim = false; w3 = true; }
        if (board[rv+1][cv]) { sim = false; w2 = true; }
        if (board[rv-1][cv]) { sim = false; w4 = true; }
        if (board[rv-1][cv-1]) { sim = false; w5 = true; }
        if (board[rv+1][cv+1]) { sim = false; w6 = true; }
        if (board[rv-1][cv+1]) { sim = false; w7 = true; }
        if (board[rv+1][cv-1]) { sim = false; w8 = true; }
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
                insert(cv+j, rv+i, custo[rv+i][cv+j]);
            }
        }
        if (!next(&cv, &rv)) break;
    }
}


int main() {
    
    int cs, rs, ct, rt;
    int c1, r1, c2, r2, b;
    int i, j, k;
    
    while (scanf("%d %d", &c, &r) != EOF) {
        if (!c && !r) break;
        for (i = 0; i < c+4; i++) 
            board[0][i] = board[1][i] = board[r+2][i] = board[r+3][i] = OFF;
        for (i = 0; i < r+4; i++) 
            board[i][0] = board[i][1] = board[i][c+2] = board[i][c+3] = OFF;
        for (i = 2; i < r+2; i++) for (j = 2; j < c+2; j++)
            board[i][j] = FREE, custo[i][j] = INF;   
        scanf("%d %d %d %d %d", &cs, &rs, &ct, &rt, &b);
        ++rs, ++cs, ++rt, ++ct;
        for (k = 0; k < b; k++) {
            scanf("%d %d %d %d", &c1, &r1, &c2, &r2);
            ++c1, ++c2, ++r1, ++r2;
            for (int i = r1; i <= r2; ++i) for (int j = c1; j <= c2; ++j)
                board[i][j] = WAT;   
        }
        if (!heur(rs, cs, rt, ct)) dijkstra(rs, cs, rt, ct);
        if (custo[rt][ct] >= INF) printf("impossible\n");
        else printf("%d\n", custo[rt][ct]);
    }
    
    return 0;
}
