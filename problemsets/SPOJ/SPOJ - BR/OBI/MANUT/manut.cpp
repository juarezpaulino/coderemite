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

const int VT = 400;
const int AR = VT * VT;

////////////////////////////////////////////////////////////////////////////
// Defini??es compartilhadas.
//
int dest[AR<<1]; // "2 *" apenas para CFC.
int adj[VT][VT]; // "2 *" apenas para Fluxos e CFC.
int nadj[VT], nvt, nar;
_inline(int inv)(int a) { return a ^ 0x1; } // Apenas para Fluxos e PP.


////////////////////////////////////////////////////////////////////////////
// Defini??es espec?ficas para Pontos de Articula??o e Pontes.
//
char part[VT], ponte[AR<<1];
int menor[VT], npart, nponte;

////////////////////////////////////////////////////////////////////////////
// Defini??o espec?fica para Conexidade.
//
int prof[VT];

////////////////////////////////////////////////////////////////////////////
// Inicializa o grafo.
//
void inic(int n = 0) {
    nvt = n;
    nar = 0;
    memset(nadj, 0, sizeof(nadj));
}

////////////////////////////////////////////////////////////////////////////
// Adiciona uma aresta ao grafo.
//
// "int u" apenas para Fluxos; "double c" apenas para FCM.
//
int aresta(int i, int j) {
    int ar = nar;
    dest[nar] = j;
    adj[i][nadj[i]++] = nar++;
    dest[nar] = i;
    adj[j][nadj[j]++] = nar++;
    return ar;
}

////////////////////////////////////////////////////////////////////////////
// Fun??o espec?fica para Pontos de Articula??o e Pontes.
//
int dfs_partponte(int no, int ent) {
    int i, ar, viz, nf = 0;
    for (i = 0; i < nadj[no]; i++) {
        ar = adj[no][i]; viz = dest[ar];
        if (prof[viz] == NULO) {
            menor[viz] = prof[viz] = prof[no] + 1;
            dfs_partponte (viz, ar); nf++;
            if (menor[viz] >= prof[no]) {
                part[no] = 1;
                if (menor[viz] == prof[viz]) ponte[ar] = ponte[inv(ar)] = 1;
            }
            else menor[no] = min(menor[no], menor[viz]);
        }
        else if (inv(ar) != ent) menor[no] = min(menor[no], prof[viz]);
    }
    return nf;
}

////////////////////////////////////////////////////////////////////////////
// Encontra os Pontos de Articulação e as Pontes.
//
void partponte() {
    memset(part, 0, sizeof(part));
    memset(ponte, 0, sizeof(ponte));
    memset(prof, NULO, sizeof(prof));
    memset(menor, NULO, sizeof(menor));
    npart = nponte = 0;
    for (int i = 0; i < nvt; i++)
        if (prof[i] == NULO) {
            menor[i] = prof[i] = 0;
            if (dfs_partponte(i, NULO) < 2) part[i] = 0;
        }
    for (int i = 0; i < nvt; i++) if (part[i]) npart++;
    for (int i = 0; i < nar; i++) if (ponte[i]) nponte++;
    nponte /= 2;
}

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');
    return i;
}


int main() {

    int n, m;
    register int i, j, x, y, k = 1, sp;
    
    while (1) {
        n = get_int(); m = get_int(); if (!n && !m) break;
        inic(n);
        for (i = 0; i < m; i++) { x = get_int(); y = get_int(); aresta(x-1, y-1); }
        partponte();
        if (!npart) printf("Teste %d\nnenhum\n\n", k++);
        else {
            printf("Teste %d\n", k++);
            for (i = sp = 0; i < n; i++) if (part[i]) {
                if (sp) putchar(' ');
                printf("%d", i+1); sp = 1;
            }
            printf("\n\n");
        }
    }
    
    return 0;
}

