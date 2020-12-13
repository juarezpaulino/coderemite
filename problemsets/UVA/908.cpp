/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

vector<int> adj[1010101], cost[1010101];
int D[1010101];
int id = 1;
int N, M;

const int MAXV = 1<<20;

struct Info { int g, key; } info[MAXV];

// G - Minimum heap
int G[MAXV], nheap, ninfo;

void init_heap(int n = 0) {
    nheap = ninfo = n;
    for (int i = 1; i <= n; i++) {
        G[i] = info[i].g = i;
        info[i].key = 1<<30;
    }
}

void up(int u, int *heap) {
    if (u == 1) return;
    int p = u/2;
    bool change = info[heap[u]].key < info[heap[p]].key;
    if (change) {
        int v = heap[u]; heap[u] = heap[p]; heap[p] = v;
        info[heap[p]].g = p, info[heap[u]].g = u;

        up(p, heap);
    }
}

void fix(int u, int *heap) {
    int mini = u, l = u*2, r = u*2+1;
    if (l <= nheap) {
        bool change = info[heap[l]].key < info[heap[mini]].key;
        if (change) mini = l;
    }
    if (r <= nheap) {
        bool change = info[heap[r]].key < info[heap[mini]].key;
        if (change) mini = r;
    }
    if (mini != u){
        int v = heap[u]; heap[u] = heap[mini]; heap[mini] = v;
        info[heap[mini]].g = mini, info[heap[u]].g = u;

        fix(mini, heap);
    }
}

inline void update(int u, int key) {
    int old = info[u].key;
    info[u].key = key;
    // Update minimum/maximum heaps
    if (key < old)  { up(info[u].g, G); }
    else            { fix(info[u].g, G); }
}

inline void insert(int key) {
    nheap++; ninfo++;
    info[ninfo].key = key;
    G[nheap] = ninfo;
    info[ninfo].g = nheap;
    up(nheap, G);
}

inline int minimum(int &u, int &key) {
    u = G[1]; key = info[G[1]].key;
    G[1] = G[nheap]; info[G[1]].g = 1;
    nheap--;
    fix(1, G);
    return key;
}


int prim() {
    int ret = 0;
    for (int i = 1; i <= N; i++) D[i] = 1<<30;
    init_heap(N);
    update(1, D[1] = 0);
    while (nheap) {
        int u, c;
        ret += minimum(u, c);
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            c = cost[u][i];
            if (c < D[v]) update(v, D[v] = c);
        }
    }
    return ret;
}


int main() {

    while (scanf("%d", &N) != EOF) {
        int U = 0, V;
        for (int i = 0; i < N-1; i++) {
            int x;
            scanf("%*d %*d %d", &x);
            U += x;
        }
        for (int i = 1; i <= N; i++) adj[i].clear(), cost[i].clear();
        int K;
        scanf("%d", &K);
        while (K--) {
            int u, v, c;
            scanf("%d %d %d", &u, &v, &c);
            adj[u].push_back(v); cost[u].push_back(c);
            adj[v].push_back(u); cost[v].push_back(c);
        }
        scanf("%d", &M);
        while (M--) {
            int u, v, c;
            scanf("%d %d %d", &u, &v, &c);
            adj[u].push_back(v); cost[u].push_back(c);
            adj[v].push_back(u); cost[v].push_back(c);
        }
        V = prim();
        if (id != 1) putchar('\n');
        printf("%d\n%d\n", U, V);
        id++;
    }

    return 0;
}
