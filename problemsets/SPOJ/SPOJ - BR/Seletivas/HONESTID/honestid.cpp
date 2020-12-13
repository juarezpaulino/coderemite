/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <queue>
#include <list>

using namespace std;

struct aresta { int u, v, c; char label; };


int n, m, k;
aresta orc[10000];
int pai[10000];
list<int> f1[200];
char color[200];
int adj[100][100], nadj[100];
set<int> I;
queue<int> q;

#define _inline(f...) f() __attribute__((always_inline)); f
#define _foreach(it, b, e) for (typeof(b) it = (b); it != (e); it++)
#define foreach(x...) _foreach(x)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()


////////////////////////////////////////////////////////////////////////////////
// Disjoint set Union-Find.
//
struct uf_set { int parent, rank; };

uf_set st[100];

void make_set(int x) { st[x].parent = x; st[x].rank = 0; }

int find_set(int x) {
     if (st[x].parent == x) return x;
     else { st[x].parent = find_set(st[x].parent); return st[x].parent; }
}
 
int union_set(int x, int y) {
    int xr = find_set(x);
    int yr = find_set(y);
    if (st[xr].rank > st[yr].rank) st[yr].parent = st[xr].parent;
    else if (st[xr].rank < st[yr].rank) st[xr].parent = st[yr].parent;
    else if (xr != yr) { st[yr].parent = xr; st[xr].rank = st[xr].rank+1; }
}


int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    if (ch == EOF) return EOF;
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');
    return i;
}

void augment(int a) {
    if (a == -1) return;
    if (orc[a].label == '+') { augment(pai[a]); I.insert(a); }
    else { augment(pai[a]); I.erase(a); }
}

int init() {
    register int i, j, u, v;
    while (!q.empty()) q.pop();
    for (i = 0; i < k; i++) color[i] = 0;
    for (i = 0; i < m; i++) orc[i].label = 0, pai[i] = -1;
    for (i = 0; i < n; i++) make_set(i);
    foreach(it, all(I)) {
        union_set(orc[*it].u, orc[*it].v); color[orc[*it].c] = 1;
    }
    
    for (i = 0; i < k; i++) if (!color[i]) foreach(it, all(f1[i])) {
        orc[*it].label = '+'; 
        if (find_set(orc[*it].u) != find_set(orc[*it].v)) {
            augment(*it); return 1;
        }
        q.push(*it);
    }
    
    /* Constroi o grafo. */
    for (i = 0; i < n; i++) nadj[i] = 0;
    foreach(it, all(I)) {
        u = orc[*it].u; v = orc[*it].v;
        adj[u][nadj[u]++] = *it; adj[v][nadj[v]++] = *it;
    }
    
    return 0;
}

void detect_cycle(int s, int t, int p) {
    register int i, j;
    int u, v;
    aresta a;
    int par[100], disc[100];
    queue<int> bfs;
    
    /* Caminhos. */
    for (i = 0; i < n; i++) par[i] = -1, disc[i] = 0;
    disc[s] = 1; bfs.push(s);
    while (!bfs.empty()) {
        u = bfs.front(); if (u == t) break; bfs.pop();
        for (i = 0; i < nadj[u]; i++) {
            a = orc[adj[u][i]];
            if (!disc[a.u]) { par[a.u] = adj[u][i]; disc[a.u] = 1; bfs.push(a.u); }
            if (!disc[a.v]) { par[a.v] = adj[u][i]; disc[a.v] = 1; bfs.push(a.v); }
        }
    }
    
    /* Identifica o ciclo. */
    i = t;
    while (par[i] != -1) {
        j = par[i];
        if (!orc[j].label) { orc[j].label = '-'; pai[j] = p; q.push(j); }
        if (orc[j].u == i) i = orc[j].v; else i = orc[j].u;
    }
}


int main() {

    int u, v, c, a;
    register int i, j;
    int K = 1;

    while (1) {
        n = get_int(); if (n == EOF) break; m = get_int(); k = get_int();
        for (i = 0; i < k; i++) f1[i].clear();
        for (i = 0; i < m; i++) {
            u = get_int()-1; v = get_int()-1; c = get_int()-1;
            orc[i].u = u; orc[i].v = v; orc[i].c = c;
            f1[c].push_back(i);
        }
        if (k < n-1) { printf("Instancia %d\nnao\n\n", K++); continue; }
        I.clear();
        while (1) {
            if (init()) continue;
            while (1) {
                if (q.empty()) goto OUT;
                a = q.front(); q.pop();
                if (orc[a].label == '+') {
                    u = orc[a].u; v = orc[a].v;
                    if (find_set(u) != find_set(v)) { 
                        augment(a); break;
                    }
                    detect_cycle(u, v, a);
                }
                else if (orc[a].label == '-') {
                    c = orc[a].c;
                    foreach(it, all(f1[c])) if (!orc[*it].label) {
                        orc[*it].label = '+'; pai[*it] = a;
                        q.push(*it);
                    }
                }
            }
        }
        
OUT:    if (I.size() == n-1) printf("Instancia %d\nsim\n\n", K++);
        else printf("Instancia %d\nnao\n\n", K++);
        /*printf("\nMax Cardinality\n");
        foreach(it, all(I)) {
            printf("%d %d %d\n", orc[*it].u+1, orc[*it].v+1, orc[*it].c+1);
        }*/
    }    
    
    return 0;
}

