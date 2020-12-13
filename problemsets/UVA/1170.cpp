/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <map>
#include <queue>
#include <set>
#include <cstdlib>

#define MAXD 400

#define FOR(i,n) for((i)=0;(i)<(n);(i)++)
#define FORN(i,n) for((i)=(n)-1;(i)>=0;(i)--)
#define BE(a) ((a).begin()),((a).end())
#define SI(a) ((a).size())
#define PB push_back
#define MP make_pair
#define CLR(a,v) memset((a),(v),sizeof(a))
#define _FORIT(it, b, e) for (__typeof(b) it = (b); it != (e); it++)
#define FORIT(x...) _FORIT(x)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define TLE while(1);
#define RTE printf("%d", 1/0);


using namespace std;

#define MAX_ESTADO 127597

struct estado {
    estado *prox;
    int x, y, f, m;
    estado(int y = 0, int x = 0, int f = 0, int m = 0) :
    y(y), x(x), f(f), m(m) {}
};

estado *hash[MAX_ESTADO];
int mapa[MAXD][MAXD];
int l, c;
int sx, sy, tx, ty;
int font[MAXD][MAXD], fontv[5000];


void inic_hash() {
    for (int i = 0; i < MAX_ESTADO; i++) hash[i] = NULL;
}

bool cmp_hash(estado *a, estado *b) {
    return a->y==b->y && a->x==b->x && a->f==b->f && a->m==b->m;
}

int func_hash(estado *v) {
    return (v->y*c+v->x+(v->f+1)*13+v->m*29) % MAX_ESTADO;
}

estado *cria_hash(estado *v) {
    estado *pt = (estado *) malloc(sizeof(estado));
    *pt = *v; pt->prox = NULL; return pt;
}
estado *insere_hash(estado *v) {
    int p = func_hash(v); estado *pt = hash[p], *ant = NULL;
    if (hash[p] == NULL) { hash[p] = cria_hash(v); return NULL; }
    while (pt != NULL) {
        if (cmp_hash(v, pt)) return pt;
        ant = pt;  pt = pt->prox;
    }
    ant->prox = cria_hash(v); return NULL;
}

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return i;
}

int BFS() {
    int d, k;
    estado u, v;
    queue<pair<estado, int> >q;
    u = estado(sy, sx, -1, 0); insere_hash(&u); q.push(MP(u, 0));
    while (!q.empty()) {
        u = q.front().first; d = q.front().second; q.pop();
        if (u.y==ty && u.x==tx) return d;
        if (u.m) { k = fontv[u.f]; v.m = u.m-1; } else { k = 1; v.m = 0; }
        v.y = u.y-k; v.x = u.x; v.f = (!v.m) ? -1 : u.f;
        if (v.y>=0 && mapa[v.y][v.x]>0) {
            if (mapa[v.y][v.x]>1 && font[v.y][v.x]!=u.f) {
                v.f = font[v.y][v.x]; v.m = mapa[v.y][v.x]/10;
            }
            if (!insere_hash(&v)) q.push(MP(v, d+1));
        }
        if (u.m) { k = fontv[u.f]; v.m = u.m-1; } else { k = 1; v.m = 0; }
        v.y = u.y+k; v.x = u.x; v.f = (!v.m) ? -1 : u.f;
        if (v.y<l && mapa[v.y][v.x]>0) {
            if (mapa[v.y][v.x]>1 && font[v.y][v.x]!=u.f) {
                v.f = font[v.y][v.x]; v.m = mapa[v.y][v.x]/10;
            }
            if (!insere_hash(&v)) q.push(MP(v, d+1));
        }
        if (u.m) { k = fontv[u.f]; v.m = u.m-1; } else { k = 1; v.m = 0; }
        v.y = u.y; v.x = u.x-k; v.f = (!v.m) ? -1 : u.f;
        if (v.x>=0 && mapa[v.y][v.x]>0) {
            if (mapa[v.y][v.x]>1 && font[v.y][v.x]!=u.f) {
                v.f = font[v.y][v.x]; v.m = mapa[v.y][v.x]/10;
            }
            if (!insere_hash(&v)) q.push(MP(v, d+1));
        }
        if (u.m) { k = fontv[u.f]; v.m = u.m-1; } else { k = 1; v.m = 0; }
        v.y = u.y; v.x = u.x+k; v.f = (!v.m) ? -1 : u.f;
        if (v.x<c && mapa[v.y][v.x]>0) {
            if (mapa[v.y][v.x]>1 && font[v.y][v.x]!=u.f) {
                v.f = font[v.y][v.x]; v.m = mapa[v.y][v.x]/10;
            }
            if (!insere_hash(&v)) q.push(MP(v, d+1));
        }
    }
    return -1;
}


int main() {

    int t, i, j, k, f = 0;
    for (t = get_int(); t--; ) {
        (f)?putchar('\n'):(f=1);
        l = get_int(); c = get_int(); k = 0;
        FOR(i, l) FOR(j, c) {
            mapa[i][j] = get_int();
            if (mapa[i][j]>1) fontv[k] = mapa[i][j]%10, font[i][j] = k++;
        }
        inic_hash();
        sy = get_int(), sx = get_int(), ty = get_int(), tx = get_int();
        k = BFS(); if (k==-1) printf("IMPOSSIBLE\n"); else printf("%d\n", k);
    }
    return 0;
}
