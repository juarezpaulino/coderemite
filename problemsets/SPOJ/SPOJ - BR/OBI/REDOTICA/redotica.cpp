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


int dest[AR<<1];
int adj[VT][VT];
int nadj[VT], ent[VT], nvt, nar;

int marc[VT], custo[AR<<1], dist[VT];


void inic(int n = 0) {
    nvt = n;
    nar = 0;
    memset(nadj, 0, sizeof(nadj));
}

int aresta(int i, int j, int c = 0) {
    int ar = nar;
    custo[nar] = c;
    dest[nar] = j;
    adj[i][nadj[i]++] = nar++;
    custo[nar] = c;
    dest[nar] = i;
    adj[j][nadj[j]++] = nar++;
    return ar;
}

void prim(int ini) {
    int i, j, k, a;
    int d;
    priority_queue<pair<int, int> > heap;
    memset(marc, 0, sizeof(marc));
    for (i = 1; i <= nvt; i++) dist[i] = INF;
    heap.push(make_pair(dist[ini] = 0, ini));
    while (!heap.empty()) {
        i = heap.top().second; heap.pop();
        if (marc[i]) continue; marc[i] = 1;
        if (i != ini) {
            if (i < ent[i]) printf("%d %d\n", i, ent[i]);
            else printf("%d %d\n", ent[i], i);
        }
        for (k = 0; k < nadj[i]; k++) {
            a = adj[i][k]; j = dest[a]; d = custo[a];
            if (d < dist[j]) { 
                heap.push(make_pair( -(dist[j] = d), j));
                ent[j] = i;
            }
        }
    }
}



int main() {
    
    int n, m;
    int x, y, z;
    int c = 1;
    
    while (scanf("%d %d", &n, &m)) {
        if (!n) break;
        inic(n);
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &x, &y, &z);
            aresta(x, y, z);
        }
        
        printf("Teste %d\n", c++);
        prim(1);
        putchar('\n');
    }
    
    return 0;
}
