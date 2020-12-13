/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <list>
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

#define INF 0x3F3F3F3F
#define MAXV 200001

typedef pair<int,int> pii;

list<pii> adj[MAXV];
int n, mss;

// Soma maxima de uma subarvore com raiz x e predecessor y.
int dfs(int x, int y) {
  int p = 0;
  for (; !adj[x].empty(); adj[x].pop_back())
    if (adj[x].back().first != y) p += max(0, adj[x].back().second + dfs(adj[x].back().first, x));
  mss = max(mss,p); return p;
}

int get_int() {
    int ch, i, s;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    s = (ch=='-') ? (ch = getchar(), -1) : 1;
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return s*i;
}


int main() {
    int n, a, b, p;
    for ( ; n = get_int(), n; ) {
        while (n--) {
            a = get_int(), b = get_int(), p = get_int();
            adj[a].PB(MP(b, p)); adj[b].PB(MP(a, p));
        }
        mss = 0; dfs(b, -1); printf("%d\n", mss);
    }
    return 0;
}
