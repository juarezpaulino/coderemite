/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

///////////////////////////////////////////////////////////////////////////////
// Simultaneous Min/Max heap (G/H - easily adapt to just one type).
//
// To reduce to minheap only, remove all references to h, H.
// To reduce to maxheap only, remove all references to g, G.
//
// All indexes begin from 1.
//
// G - Minimum heap
// H - Maximum heap
//
// Use:
// - init_heap(), insert(), update(), minimum(), maximum().
//
const int MAXV = 1<<20;

struct Info { int g, h, key; } info[MAXV];

int G[MAXV], H[MAXV], nheap, ninfo;

void init_heap(int n = 0) {
    nheap = ninfo = n;
    for (int i = 1; i <= n; i++) {
        G[i] = info[i].g = H[i] = info[i].h = i;
        info[i].key = 1<<30;
    }
}

void up(int u, int *heap, bool heapMin) {
    if (u == 1) return;
    int p = u/2;
    bool change = heapMin ? info[heap[u]].key < info[heap[p]].key :
                            info[heap[u]].key > info[heap[p]].key;
    if (change) {
        int v = heap[u]; heap[u] = heap[p]; heap[p] = v;
        if (heapMin) info[heap[p]].g = p, info[heap[u]].g = u;
        else         info[heap[p]].h = p, info[heap[u]].h = u;

        up(p, heap, heapMin);
    }
}

void fix(int u, int *heap, bool heapMin) {
    int mini = u, l = u*2, r = u*2+1;
    if (l <= nheap) {
        bool change = heapMin ? info[heap[l]].key < info[heap[mini]].key :
                                info[heap[l]].key > info[heap[mini]].key;
        if (change) mini = l;
    }
    if (r <= nheap) {
        bool change = heapMin ? info[heap[r]].key < info[heap[mini]].key :
                                info[heap[r]].key > info[heap[mini]].key;
        if (change) mini = r;
    }
    if (mini != u){
        int v = heap[u]; heap[u] = heap[mini]; heap[mini] = v;
        if (heapMin) info[heap[mini]].g = mini, info[heap[u]].g = u;
        else         info[heap[mini]].h = mini, info[heap[u]].h = u;

        fix(mini, heap, heapMin);
    }
}

inline void update(int u, int key) {
    int old = info[u].key;
    info[u].key = key;
    // Update minimum/maximum heaps
    if (key < old)  { up(info[u].g, G, true); fix(info[u].h, H, false); }
    else            { up(info[u].h, H, false); fix(info[u].g, G, true); }
}

inline void insert(int key) {
    nheap++; ninfo++;
    info[ninfo].key = key;
    G[nheap] = H[nheap] = ninfo;
    info[ninfo].g = info[ninfo].h = nheap;
    up(nheap, G, true);
    up(nheap, H, false);
}

inline int minimum(int &u, int &key) {
    u = G[1]; key = info[G[1]].key;
    int h = info[u].h;
    G[1] = G[nheap]; info[G[1]].g = 1;
    H[h] = H[nheap]; info[H[h]].h = h;
    nheap--;
    fix(1, G, true);
    fix(h, H, false);
    return key;
}

inline int maximum(int &u, int &key) {
    u = H[1]; key = info[H[1]].key;
    int g = info[u].g;
    H[1] = H[nheap]; info[H[1]].h = 1;
    G[g] = G[nheap]; info[G[g]].g = g;
    nheap--;
    fix(1, H, false);
    fix(g, G, true);
    return key;
}


int main() {

    int n;
    while (scanf("%d", &n)) {
        if (!n) break;
        init_heap();
        long long ret = 0;
        for (int k = 0; k < n; k++) {
            int a, b, c, d;
            scanf("%d", &c);
            for (int i = 0; i < c; i++) { int x; scanf("%d", &x); insert(x); }
            ret += maximum(a, b) - minimum(c, d);
        }
        printf("%lld\n", ret);
    }

    return 0;
}
