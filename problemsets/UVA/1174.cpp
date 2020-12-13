/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <map>
#include <list>
#include <queue>


using namespace std;

#define _foreach(it, b, e) for (__typeof(b) it = (b); it != (e); it++)
#define foreach(x...) _foreach(x)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

const int INF = 0x3F3F3F3F;

const int VT = 2000;
const int AR = 100000;


int dest[AR], custo[AR];
int nadj[VT], marc[VT], dist[VT];
int adj[VT][VT];
map<string, int> cit;
int t, n, m, tot;

void prim(int s) {
    int i, j, k, a;
    int d;
    priority_queue<pair<int, int> > heap;
    heap.push(make_pair(dist[s] = 0, s));
    while (!heap.empty()) {
        i = heap.top().second; heap.pop();
        if (marc[i]) continue; marc[i] = 1; tot += dist[i];
        for (k = 0; k < nadj[i]; k++) {
            a = adj[i][k]; j = dest[a]; d = custo[a];
            if (d < dist[j]) heap.push(make_pair( -(dist[j] = d), j));
        }
    }
}



int main() {

    int i, j, k, x, y, c, f = 0;
    char B[10], E[10];

    for (scanf("%d", &t); t--; ) {
        if (f) putchar('\n');
        scanf("%d %d ", &n, &m);
        for (i = 0; i < n; i++) nadj[i] = 0; cit.clear();
        for (i = k = 0; j = i<<1, i < m; i++) {
            scanf("%s %s %d ", B, E, &c);
            x = (cit.count(B))? cit[B] : cit[B] = k++;
            y = (cit.count(E))? cit[E] : cit[E] = k++;
            adj[x][nadj[x]++] = j; adj[y][nadj[y]++] = j|1;
            dest[j] = y; dest[j|1] = x; custo[j] = custo[j|1] = c;
        }
        for (i = 0; i < n; i++) dist[i] = INF, marc[i] = 0;
        for (tot = i = 0; i < n; i++) if (!marc[i]) prim(i);
        printf("%d\n", tot); f = 1;
    }

    return 0;
}

