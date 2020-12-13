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


const int VT = 500;
const int AR = 2600;

int dest[AR];
int adj[VT][VT];
int nadj[VT], nvt, nar;
_inline(int inv)(int a) { return a ^ 0x1; }


int cap[AR], fluxo[AR], ent[VT];
_inline(int orig)(int a) { return dest[inv(a)]; }
_inline(int capres)(int a) { return cap[a] - fluxo[a]; }

int padj[VT], lim[VT], nivel[VT], qtd[VT];

void inic(int n = 0) {
    nvt = n;
    nar = 0;
    memset(nadj, 0, sizeof(nadj));
}

int aresta(int i, int j, int u = 0) {
    int ar = nar;
    cap[nar] = u;
    dest[nar] = j;
    adj[i][nadj[i]++] = nar++;
    cap[nar] = 0;
    dest[nar] = i;
    adj[j][nadj[j]++] = nar++;
    return ar;
}

void revbfs(int ini, int fim) {
    int i, no, viz, ar;
    queue<int> fila;
    memset(nivel, NULO, sizeof(nivel));
    memset(qtd, 0, sizeof(qtd));
    nivel[fim] = 0; fila.push(fim);
    while (!fila.empty()) {
        no = fila.front(); fila.pop();
        qtd[nivel[no]]++;
        for (i = 0; i < nadj[no]; i++) {
            ar = adj[no][i]; viz = dest[ar];
            if (cap[ar] == 0 && nivel[viz] == NULO) {
                nivel[viz] = nivel[no] + 1; fila.push(viz);
            }
        }
    }
}

int admissivel(int no) {
    while (padj[no] < nadj[no]) {
        int ar = adj[no][padj[no]];
        if (nivel[no] == nivel[dest[ar]] + 1 && capres(ar) > 0) return ar;
        padj[no]++;
    }
    padj[no] = 0;
    return NULO;
}

int retrocede(int no) {
    int i, ar, viz, menor = NULO;
    if (--qtd[nivel[no]] == 0) return NULO;
    for (i = 0; i < nadj[no]; i++) {
        ar = adj[no][i]; viz = dest[ar];
        if (capres(ar) <= 0) continue;
        if (menor == NULO || nivel[viz] < nivel[menor]) menor = viz;
    }
    if (menor != NULO) nivel[no] = nivel[menor];
    qtd[++nivel[no]]++;
    return ((ent[no] == NULO) ? no : orig(ent[no]));
}

int avanca(int no, int ar) {
    int viz = dest[ar];
    ent[viz] = ar;
    lim[viz] = min(lim[no], capres(ar));
    return viz;
}

int aumenta(int ini, int fim) {
    int ar, no = fim, fmax = lim[fim];
    while (no != ini) {
        fluxo[ar = ent[no]] += fmax;
        fluxo[inv(ar)] -= fmax;
        no = orig(ar);
    }
    return fmax;
}

int maxflow(int ini, int fim) {
    int ar, no = ini, fmax = 0;
    memset(fluxo, 0, sizeof(fluxo));
    memset(padj, 0, sizeof(padj));
    revbfs(ini, fim);
    lim[ini] = INF; ent[ini] = NULO;
    while (nivel[ini] < nvt && no != NULO) {
        if ((ar = admissivel(no)) == NULO) no = retrocede(no);
        else if ((no = avanca(no, ar)) == fim) {
            fmax += aumenta(ini, fim);
            no = ini;
        }
    }
    return fmax;
}


int main() {

    int n, m, k;
    int c, u, v;
    int i, j = 1;
    
    while (scanf("%d %d %d", &n, &m, &k) != EOF) {
        inic(n+m+2);
        for (i = 1; i <= n; i++) { scanf("%d", &c); aresta(0, i, c); }
        for (i = 0; i < k; i++) { scanf("%d %d", &u, &v); aresta(u, v+n, 1); }
        for (i = n+1; i <= n+m; i++) aresta(i, n+m+1, 1);
        printf("Instancia %d\n", j++);
        printf("%d\n\n", maxflow(0, n+m+1));
    }
    
    return 0;
}
