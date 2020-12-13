/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>

#define FOR(i,n) for((i)=0;(i)<(n);(i)++)
#define FORN(i,n) for((i)=(n)-1;(i)>=0;(i)--)
#define _FORIT(it, b, e) for (__typeof(b) it = (b); it != (e); it++)
#define FORIT(x...) _FORIT(x)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define SI(a) ((a).size())
#define PB push_back
#define MP make_pair
#define CLR(a,v) memset((a),(v),sizeof(a)) 
#define TLE while(1);
#define RTE printf("%d", 1/0);

#define MAXV 100
#define INF 0x3F3F3F3F

using namespace std;

int adj[MAXV][MAXV], custo[MAXV][MAXV];
int nadj[MAXV], prof[MAXV], dist[MAXV], marc[MAXV];
int n, m, mini;

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return i;
}

void dijkstra(int ini) {
    int i, j, k, d;
    priority_queue<pair<int, int> > heap;
    FOR(i, n) dist[i] = INF, marc[i] = 0;
    heap.push(make_pair(dist[ini] = 0, ini)); prof[ini] = 0;
    while (!heap.empty()) {
        i = heap.top().second; heap.pop();
        if (marc[i]) continue; marc[i] = 1;
        for (k = 0; k < nadj[i]; k++) {
            j = adj[i][k]; d = dist[i] + custo[i][j];
            if (marc[j] && (prof[i]+prof[j])%2==0)
                mini<?=dist[i]+dist[j]+custo[i][j];
            if (d < dist[j])
                heap.push(make_pair( -(dist[j] = d), j)), prof[j] = prof[i]+1;
        }
    }
}


int main() {
    
    int i, j, k, u, v, c;
    for (int t = get_int(); t--; ) {
        n = get_int(), m = get_int();
        FOR(i, n) nadj[i] = 0;
        FOR(i, m) {
            u = get_int()-1, v = get_int()-1, c = get_int();
            adj[u][nadj[u]++] = v; adj[v][nadj[v]++] = u;
            custo[u][v] = custo[v][u] = c;
        }
        mini = INF;
        FOR(i, n) dijkstra(i);
        mini==INF?printf("impossivel\n"):printf("%d\n", mini);
    }
    return 0;
}

