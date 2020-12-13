/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <utility>
#include <iostream>
#include <sstream>
#include <map>
#include <queue>
#include <list>


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

int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


////////////////////////////////////////////////////////////////////////////////
// Grafos //////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


const int VT = 500;
const int AR = 10000;

int dest[AR], custo[AR], orig[AR], valid[AR];
int adj[VT][VT];
int nadj[VT], nvt, nar;
int marc[VT], dist[VT];
list<int> ent[VT];
char out[1000];

void inic(int n) {
    nvt = n; nar = 0;
    for (int i = 0; i < n; i++) nadj[i] = 0;
}

void aresta(int i, int j, int c) {
    custo[nar] = c;
    dest[nar] = j; orig[nar] = i;
    adj[i][nadj[i]++] = nar++;
}

void dijkstra(int s, int t) {
    register int i, j, k, a, d;
    priority_queue<pair<int, int> > heap;
    for (i = 0; i < nvt; i++) { marc[i] = 0; dist[i] = INF; ent[i].clear(); }
    heap.push(make_pair(dist[s] = 0, s));
    while (!heap.empty()) {
        i = heap.top().second; if (i == t) break; heap.pop();
        if (marc[i]) continue; marc[i] = 1;
        for (k = 0; k < nadj[i]; k++) {
            a = adj[i][k];
            j = dest[a]; d = dist[i] + custo[a];
            if (d < dist[j]) {
                heap.push(make_pair( -(dist[j] = d), j));
                ent[j].clear(); ent[j].push_back(a);
            }
            else if (d == dist[j]) ent[j].push_back(a);
        }
    }
}

void dijkstra2(int s, int t) {
    register int i, j, k, a, d;
    priority_queue<pair<int, int> > heap;
    for (i = 0; i < nvt; i++) { marc[i] = 0; dist[i] = INF; }
    heap.push(make_pair(dist[s] = 0, s));
    while (!heap.empty()) {
        i = heap.top().second; if (i == t) break; heap.pop();
        if (marc[i]) continue; marc[i] = 1;
        for (k = 0; k < nadj[i]; k++) {
            a = adj[i][k]; if (!valid[a]) continue;
            j = dest[a]; d = dist[i] + custo[a];
            if (d < dist[j]) heap.push(make_pair( -(dist[j] = d), j));
        }
    }
}

void disconnect(int u) {
    marc[u] = 1;
    foreach(it, all(ent[u])) if (!marc[orig[*it]]) {
        valid[*it] = 0; disconnect(orig[*it]);
    }
}

int get_int() {
    int ch, i, s;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    if (ch == EOF) return (EOF);
    s = (ch == '-') ? 1, ch = getchar() : 0;
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');
    if (s) return -i;
    return i;
}


int main() {

    int n, m;
    int s, t;
    register int u, v, p, i, j, k;
    char str[15];

    k = 0;
    while (1) {
        n = get_int(); m = get_int();
        if (!n && !m) break;
        inic(n);
        s = get_int(); t = get_int();
        for (i = 0; i < m; i++) {
            u = get_int(); v = get_int(); p = get_int();
            aresta(u, v, p); valid[i] = 1;
        }
        dijkstra(s, t);
        for (i = 0; i < nvt; i++) marc[i] = 0; disconnect(t);
        dijkstra2(s, t);
        p = dist[t];
        if (p==INF) { out[k]='-'; out[k+1]='1'; out[k+2]='\n'; k+= 3; }
        else {
            if (!p) out[k++] = '0';
            else {
                j = 0; while (p) { str[j++] = (p%10)+'0'; p/=10; }
                while (j--) out[k++] = str[j]; out[k++] = '\n';
            }
        }
    }
    out[k-1] = 0; puts(out);

    return 0;
}
