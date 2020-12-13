/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <algorithm>

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


using namespace std;

#define MAXR 100000
#define MAXV 3000

int n, r, q;
int from[MAXR], to[MAXR], len[MAXR], ord[MAXR];
vector<pair<int,int> > adj[MAXV];
int up[MAXV];           // Union-find

int cmp(const void *a, const void *b) { return len[*(int *)a]-len[*(int *)b]; }

int root(int k) { return up[k] < 0 ? k : (up[k] = root(up[k])); }

bool join(int k, int m) {
    if ((k = root(k)) == (m = root(m))) return false;
    if (up[k] < up[m]) up[k] += up[m], up[m] = k;
    else up[m] += up[k], up[k] = m;
    return true;
}

void kruskal() {
    int i, j, a, b;
    qsort(ord, r, sizeof(int), cmp);
    FOR(i, n) up[i] = -1, adj[i].clear();
    for (i = n-1, j = 0; i; j++) {
        a = from[ord[j]], b = to[ord[j]];
        if (join(a, b))
            adj[a].PB(MP(b, len[ord[j]])), adj[b].PB(MP(a, len[ord[j]])), --i;
    }
}

int dfs(int a, int b, int p) {
    int ret;
    if (a==b) return 0;
    FORIT(it, all(adj[a])) {
        if (it->first!=p && (ret = dfs(it->first, b, a))>=0) return max(ret, it->second);
    }
    return -1;
}

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return i;
}

int main() {

    int t, c, i, a, b;
    for (t = get_int(), c = 1; c <= t; c++) {
        printf("Case %d\n", c);
        n = get_int(); r = get_int();
        FOR(i, r) {
            from[i] = get_int()-1, to[i] = get_int()-1, len[i] = get_int();
            ord[i] = i;
        }
        kruskal();
        for (q = get_int(); q--; ) {
            a = get_int()-1, b = get_int()-1;
            printf("%d\n", dfs(a, b, -1));
        }
        putchar('\n');
    }
    return 0;
}
