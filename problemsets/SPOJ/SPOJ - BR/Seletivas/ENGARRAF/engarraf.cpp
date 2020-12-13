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


////////////////////////////////////////////////////////////////////////////////
// Grafos //////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


const int VT = 101;
const int AR = 10000;
    
////////////////////////////////////////////////////////////////////////////
// Definições compartilhadas.
//
int dest[AR], custo[AR];
int adj[VT][VT];
int nadj[VT], nvt, nar, dist[VT], marc[VT];

////////////////////////////////////////////////////////////////////////////
// Inicializa o grafo.
//
_inline(void inic)(int n = 0) {
    nvt = n;
    nar = 0;
    for (int i = 1; i <= n; i++) nadj[i] = 0;
}

////////////////////////////////////////////////////////////////////////////
// Adiciona uma aresta ao grafo.
//
_inline(int aresta)(int i, int j, int c = 0) {
    int ar = nar;
    custo[nar] = c;
    dest[nar] = j;
    adj[i][nadj[i]++] = nar++;
    return ar;
}
    

////////////////////////////////////////////////////////////////////////////
// Algoritmo de Dijkstra: O(m * log n)
//
void dijkstra(int ini, int t) {
    int i, j, k, a;
    int d;
    priority_queue<pair<int, int> > heap;
    for (i = 1; i <= nvt; i++) { marc[i] = 0; dist[i] = INF; }
    heap.push(make_pair(dist[ini] = 0, ini));
    while (!heap.empty()) {
        i = heap.top().second; heap.pop(); if (i==t) break;
        if (marc[i]) continue; marc[i] = 1;
        for (k = 0; k < nadj[i]; k++) {
            a = adj[i][k]; j = dest[a]; d = dist[i] + custo[a];
            if (d < dist[j]) heap.push(make_pair( -(dist[j] = d), j));
        }
    }
}


int main() {
    
    int n, m;
    int i, j, k, s, t;
    
    while (scanf("%d %d", &n, &m)) {
        if (!n && !m) break;
        inic(n);
        for (k = 0; k < m; k++) { scanf("%d %d %d", &i, &j, &t); aresta(i, j, t); }
        scanf("%d %d", &s, &t); dijkstra(s, t);
        if (dist[t]==INF) puts("-1");
        else printf("%d\n", dist[t]);
    }
    
    return 0;   
}
