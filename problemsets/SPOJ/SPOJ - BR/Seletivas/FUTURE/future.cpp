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
const int AR = (5001<<1)+(VT<<2);

int dest[AR];
int adj[VT][VT<<1];
int nadj[VT], nvt, nar;
_inline(int inv)(int a) { return a ^ 0x1; }

int cap[AR], fluxo[AR], ent[VT];
_inline(int orig)(int a) { return dest[inv(a)]; }
_inline(int capres)(int a) { return cap[a] - fluxo[a]; }

int imb[VT], marc[VT], delta;
double custo[AR], pot[VT], dist[VT];
_inline(double custores)(int a) {
    return custo[a] - pot[orig(a)] + pot[dest[a]];
}

void inic(int n = 0) {
    nvt = n;
    nar = 0;
    memset(nadj, 0, sizeof(nadj));
    memset(imb, 0, sizeof(imb)); // Apenas para FCM
}

int aresta(int i, int j, int u = 0, double c = 0) {
    int ar = nar;
    custo[nar] = c; // Apenas para FCM.
    cap[nar] = u; // Apenas para Fluxos.
    dest[nar] = j;
    adj[i][nadj[i]++] = nar++;
    custo[nar] = -c; // Apenas para FCM.
    cap[nar] = 0; // Apenas para Fluxos.
    dest[nar] = i;
    adj[j][nadj[j]++] = nar++;
    return ar;
}

void dijkstra(int ini) {
    int i, j, k, a;
    double d;
    priority_queue<pair<double, int> > heap;
    memset(ent, NULO, sizeof(ent));
    memset(marc, 0, sizeof(marc));
    for (i = 0; i < nvt; i++) dist[i] = INFINITY;
    heap.push(make_pair(dist[ini] = 0.0, ini));
    while (!heap.empty()) {
        i = heap.top().second; heap.pop();
        if (marc[i]) continue; marc[i] = 1;
        for (k = 0; k < nadj[i]; k++) {
            a = adj[i][k]; j = dest[a]; d = dist[i] + custores(a);
            if (capres(a) >= delta && cmp(d, dist[j]) < 0) {
                heap.push(make_pair( -(dist[j] = d), j));
                ent[j] = a;
            }
        }
    }
}

double mincostflow() {
    int a, i, j, k, l, U = 0;
    int t = imb[0];
    double C = 0.;
    memset(pot, 0, sizeof(pot));
    memset(fluxo, 0, sizeof(fluxo));
    for (a = 0; a < nar ; a++) {
        if (cmp(custo[a]) > 0) C += custo[a];
        U = max(cap[a], U);
    }
    for (i = 0; i < nvt; i++) U = max(imb[i], max(-imb[i], U));
    for (delta = 0x40000000; delta > U; delta /= 2);
    imb[nvt] = nadj[nvt] = 0; U *= 2 * nvt; C *= 2;
    for (i = 0; i < nvt; i++) {
        aresta(i, nvt, U, C);
        aresta(nvt, i, U, C);
    }
    nvt++;
    while (delta >= 1) {
        for (a = 0; a < nar ; a++) {
            i = orig(a); j = dest[a];
            if (delta <= capres(a) && capres(a) < 2 * delta &&
                cmp(custores(a)) < 0) {
                fluxo[inv(a)] -= capres(a);
                imb[i] -= capres(a); imb[j] += capres(a);
                fluxo[a] = cap[a];
            }
        }
        while (true) {
            for (k = 0 ; k < nvt && imb[k] < delta; k++);
            for (l = nvt - 1 ; l >= 0 && imb[l] > -delta; l--);
            if (k == nvt || l < 0) break;
            dijkstra(k);
            for (i = 0 ; i < nvt ; i++) pot[i] -= dist[i];
            for (a = ent[l]; a != NULO; a = ent[orig(a)]) {
                fluxo[a] += delta; fluxo[inv(a)] -= delta;
            }
            imb[k] -= delta; imb[l] += delta;
        }
        delta /= 2;
    }
    C = 0.;

    for (i = nar-((nvt-1)<<2); i < nar; i++) if (fluxo[i]) return (-1.0);

    for (a = 0; a < nar; a++) if (fluxo[a] > 0) C += fluxo[a] * custo[a];

    return C;
}



int main() {

    int n, m;
    int a, b, c;
    int k, d;
    double cost;
    int j = 1;
    
    while (scanf("%d %d", &n, &m) != EOF) {
        inic(n);
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &a, &b, &c);
            aresta(a-1, b-1, 0, c);
            aresta(b-1, a-1, 0, c);
        }
        scanf("%d %d", &d, &k);
        imb[0] = d; imb[n-1] = -d;
        for (int i = 0; i < nar; i+=2) cap[i] = k;
        printf("Instancia %d\n", j++);
        cost = mincostflow();
        if (cost < 0) puts("impossivel\n");
        else printf("%.0lf\n\n", cost);
    }
    
    return 0;
}
