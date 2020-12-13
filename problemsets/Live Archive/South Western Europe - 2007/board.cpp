/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <vector>

using namespace std;

#define FORIT(it, b, e) for (__typeof(b) it = (b); it != (e); it++)
#define FOR(i,n) for (int i = 0; i < (n); ++i)
#define FORN(i,n) for (int i = (n)-1; i >= 0; ++i)
#define SI(a) ((a).size())
#define PB push_back
#define MP make_pair 
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()


#define MAXV 300
#define INF 0x3F3F3F3F

int t, n, I, F, m;
vector<int> adj[MAXV];
vector<int> custo[MAXV];
int dist[MAXV];

bool bellman_ford(int s) {
    bool negative_cycle = false;
    dist[s] = 0;
    FOR(k,n) FOR(i,n) FOR(j, SI(adj[i]))
        if (dist[adj[i][j]] > dist[i] + custo[i][j]) {
            dist[adj[i][j]] = dist[i] + custo[i][j];
            if (k == n-1) return dist[adj[i][j]] = -INF, negative_cycle = true, false;
        }
    return !negative_cycle;
}

int get_int() {
    int ch, i, s;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    s = (ch=='-') ? ch = getchar(), -1 : 1;
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return s*i;
}


int main() {

    int x, y, c, f = 0;
    for (t = get_int(); t--; ) {
        (f) ? putchar('\n') : f = 1;
        n = get_int(); I = get_int(), F = get_int(); m = get_int();
        FOR(i, n) adj[i].clear(), custo[i].clear(), dist[i] = INF;
        FOR(i, m) {
            x = get_int(), y = get_int(), c = get_int();
            adj[x].PB(y); custo[x].PB(c);
        }
        if (bellman_ford(I) && dist[F]!=INF) printf("%d\n", dist[F]);
        else printf("infinity\n");
    }
    return 0;
}
