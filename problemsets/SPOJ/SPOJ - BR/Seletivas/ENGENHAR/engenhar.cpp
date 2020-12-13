/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <inttypes.h>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <utility>
#include <iostream>
#include <sstream>
#include <map>
#include <queue>


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

const int VT = 101;
const int AR = VT*VT;

int dest[AR];
int adj[VT][VT];
int nadj[VT], nvt, nar;

int livre[VT], ptr[VT], lig[VT], mate[VT];
int npair, bas[2][VT>>1], topo[VT>>1];
queue<int> lk;

_inline(int primeiro) (int v) {
    return livre[mate[v]] ? mate[v] : topo[lig[ptr[v] ? mate[v] : v]];
}

int get_int() {

    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));

    if (ch == EOF) return (EOF);

    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');

    return i;
}

void inic(int n = 0) {
    nvt = n;
    nar = 0;
    memset(nadj, 0, sizeof(nadj));
}

int aresta(int i, int j) {
    int ar = nar;
    dest[nar] = j;
    adj[i][nadj[i]++] = nar++;
    return ar;
}

void ligar(int v, int e) { livre[e] = 0; lig[e] = v; lk.push(e); }

void rematch(int x, int v) {
    int i, j, y;
    y = mate[v]; mate[v] = x;
    j = lig[v];
    if (mate[y] == v) {
        if (ptr[v]) { mate[y] = j; rematch(y, j); }
        else {
            rematch(bas[0][j], bas[1][j]);
            rematch(bas[1][j], bas[0][j]);
        }
    }
}

void pairlink(int b0, int b1) {
    int tip, evt[2];
    int i, j, x;
    evt[0] = primeiro(b0);
    if (evt[0] == (x = primeiro(b1))) return;
    ptr[evt[0]] = 0; evt[1] = x; j = 1;
    while (ptr[x]) {
        ptr[x] = 0; if (evt[j^1]) j^=1;
        evt[j] = x = primeiro(lig[mate[evt[j]]]);
    }
    topo[npair] = tip = x; bas[0][npair] = b0; bas[1][npair] = b1;
    ptr[x] = 1; while (!ptr[(x = primeiro(lig[mate[x]]))]) ptr[x] = 1;
    for (i = 0; i < 2; i++)
    if ((x = primeiro(bas[i][npair])) != tip) {
        ligar(npair, x);
        while ((x = primeiro(lig[mate[x]])) != tip) ligar(npair, x);
    }
    for (i = 0; i < npair; i++) if (!livre[topo[i]]) topo[i] = tip;
    npair++;
}

void match_augment(int e) {
    int i, j, k, a;
    for (i = 0; i <= nvt; i++) livre[i] = ptr[i] = 1;
    while (!lk.empty()) lk.pop();
    livre[e] = 0; npair = 0;
    lk.push(e);
    while (!lk.empty()) {
        i = lk.front(); lk.pop();
        for (k = 0; k < nadj[i]; k++) {
            a = adj[i][k]; j = dest[a];
            if (!livre[j]) pairlink(i, j);
            else if (!mate[j]) { mate[j] = i; rematch(j, i); return; }
            else if (livre[mate[j]]) ligar(i, mate[j]);
        }
    }
}

int matching() {
    int i, c = 0;
    for (i = 0; i <= nvt; i++) mate[i] = 0; lig[0] = 0;
    for (i = 1; i <= nvt; i++) if (!mate[i]) match_augment(i);
    for (i = 1; i <= nvt; i++) if (mate[i]) c++;
    return (c>>1);
}


int main() {
    
    int c, k;
    int n, p, x;
    int i, j, xp;
    
    c = get_int();
    for (k = 1; k <= c; k++) {
        printf("Instancia %d\n", k);
        n = get_int();
        inic(n);
        xp = 0;
        for (i = 1; i <= n; i++) {
            p = get_int(); if (!p) xp = 1;
            for (j = 0; j < p; j++) {
                x = get_int();
                aresta(i, x);   
            }
        }
        if (xp) { puts("extreme programming\n"); continue; }
        if (matching() == n>>1) puts("pair programming\n");
        else puts("extreme programming\n");
    }
    
    return 0;
}
