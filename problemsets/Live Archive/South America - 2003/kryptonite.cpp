/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <queue>

#define MAXV 200

using namespace std;

const double EPS = 1E-13;
const double INF = 1E14;

int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


struct point {
    int x, y;
    point(int x = 0, int y = 0) : x(x), y(y) {}
    point operator -(point q) { return point(x - q.x, y - q.y); }
    double operator %(point q) { return x * q.y - y * q.x; }
    int cmp(point q) const { int t; return (t = ::cmp(x, q.x)) ? t : ::cmp(y, q.y); }
    bool operator ==(point q) const { return cmp(q) == 0; }
    bool operator < (point q) const { return cmp(q) < 0; }
};

struct triple {
    double d; int t, v;
    triple(double d = 0., int t = 0, int v = 0) : d(d), t(t), v(v) {}
    bool operator <(triple tr) const {
        return (d < tr.d) ? true :
               (tr.d < d) ? false :
               (t <= tr.t) ? true : false;
    }
};

int n, m, l, nvt;
int adj[MAXV][MAXV], nadj[MAXV];
double cost[MAXV][MAXV], dist[MAXV][51];
char marc[MAXV][51];
point mine[MAXV];


double distance(point p) { return sqrt(p.x*p.x + p.y*p.y); }

////////////////////////////////////////////////////////////////////////////////
// Decide se os segmentos fechados pq e rs têm pontos em comum.
//
bool seg_intersect(point p, point q, point r, point s) {
    if (p==r || p==s || q==r || q==s || p==q) return 0;
    point A = q - p, B = s - r, C = r - p, D = s - q;
    int a = cmp(A % C), b = cmp(A % D), c = cmp(B % C), d = cmp(B % D);
    if ((a*b < 0) && (c*d < 0)) return 1;
    if (!a && !b && !c && !d) return 1;
    if ((!a && ((p<r) ^ (q<r))) || (!b && ((p<s) ^ (q<s)))) return 1;
    return 0;
}

int connect_node(point &a, point &b) {
    int i, v;
    for (i = 0; v = i<<1, i < m; i++)
        if (seg_intersect(a, b, mine[v], mine[v|1])) return 0;
    return 1;
}

double dijkstra(int s) {
    int i, j, k, t, x;
    double d;
    priority_queue<triple> heap;
    for(i = 0; i < nvt; i++) for (j = 0; j < l; j++) dist[i][j] = INF, marc[i][j] = 0;
    heap.push(triple(dist[s][0] = 0.0, 0, s));
    while (!heap.empty()) {
        i = heap.top().v; t = heap.top().t; heap.pop(); if (i==nvt-1) return dist[i][t];
        if (marc[i][t]) continue; marc[i][t] = 1;
        for (k = 0; k < nadj[i]; k++) {
            j = adj[i][k]; d = dist[i][t]+cost[i][k];
            x = (i >= (m<<1) && i < nvt-2 && j >= (m<<1) && j < nvt-2) ? t+1 : t;
            if (d < dist[j][x] && x <= n) heap.push(triple(-(dist[j][x] = d), x, j));
        }
    }
    return INF;
}

int get_int() {
    int ch, i, s;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    s = (ch == '-') ? ch = getchar(), 1 : 0;
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar()) i = (i<<3)+(i<<1)+(ch - '0');
    if (s) return -i; return i;
}


int main() {
    
    int i, j, x, y;
    
    for (; n = get_int(), m = get_int(), l = get_int(), n+m+l;) {
        /* Leitura dos pontos. */
        for (i = 0; i < m<<1; i++) x = get_int(), y = get_int(), mine[i] = point(x, y);
        for (j = i+l; i < j; i++) x = get_int(), y = get_int(), mine[i] = point(x, y);
        x = get_int(), y = get_int(), mine[i] = point(x, y);
        x = get_int(), y = get_int(), mine[i+1] = point(x, y);
        
        /* Conecta o grafo. */
        nvt = (m<<1)+l+2; for (i = 0; i < nvt; i++) nadj[i] = 0;
        for (i = 0; i < (m<<1); i++) for (j = i+1; j < (m<<1); j++)
            if (connect_node(mine[i], mine[j]))
                adj[i][nadj[i]] = j, adj[j][nadj[j]] = i,
                cost[i][nadj[i]++] = cost[j][nadj[j]++] = distance(mine[i]-mine[j]);
        for (i = 0; i < (m<<1); i++) for (j = (m<<1); j < nvt-2; j++)
            if (connect_node(mine[i], mine[j]))
                adj[i][nadj[i]] = j, adj[j][nadj[j]] = i,
                cost[i][nadj[i]++] = cost[j][nadj[j]++] = distance(mine[i]-mine[j]);
        for (i = (m<<1); i < nvt-2; i++) for (j = i+1; j < nvt-2; j++)
            if (connect_node(mine[i], mine[j]))
                adj[i][nadj[i]] = j, adj[j][nadj[j]] = i,
                cost[i][nadj[i]++] = cost[j][nadj[j]++] = 0.;
        for (i = 0; i < nvt-2; i++) {
            if (connect_node(mine[i], mine[nvt-2]))
                adj[i][nadj[i]] = nvt-2, adj[nvt-2][nadj[nvt-2]] = i,
                cost[i][nadj[i]++] = cost[nvt-2][nadj[nvt-2]++] = distance(mine[i]-mine[nvt-2]);
            if (connect_node(mine[i], mine[nvt-1]))
                adj[i][nadj[i]] = nvt-1, adj[nvt-1][nadj[nvt-1]] = i,
                cost[i][nadj[i]++] = cost[nvt-1][nadj[nvt-1]++] = distance(mine[i]-mine[nvt-1]);
        }
        
        /* Dijkstra. */
        printf("%.0lf\n", dijkstra(nvt-2));
    }

    return 0;
}
