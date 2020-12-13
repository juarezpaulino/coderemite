/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <string.h>
#include<vector>

using namespace std;

#define FOR(i,n) for((i)=0;(i)<(n);(i)++)
#define FORN(i,n) for((i)=(n)-1;(i)>=0;(i)--)
#define BE(a) ((a).begin()),((a).end())
#define SI(a) ((a).size())
#define PB push_back
#define MP make_pair
#define FORIT(i,a) for((i)=(a).begin();(i)!=(a).end();(i)++)
#define CLR(a,v) memset((a),(v),sizeof(a)) 

#define MAXN 650

int n, m, d;
int cap[MAXN][MAXN], flow[MAXN][MAXN], cost[MAXN][MAXN];
int sink, source, total_cost;

inline int cf(int i, int j) {
    if (flow[j][i]) return flow[j][i];
    else return cap[i][j] - flow[i][j];
}

inline int costf(int i, int j) {
    if (flow[j][i]) return -cost[j][i];
    else return cost[i][j];
}

inline void pushf(int i, int j, int x) {
    total_cost += costf(i, j) * x;
    if (flow[j][i]) flow[j][i] -= x;
    else flow[i][j] += x;
}

int augment(void) {
    int dist[MAXN], prev[MAXN];
    bool reach[MAXN];
    bool changed;
    int i, j;
    for (i = 0; i < n; i++) reach[i] = 0;
    reach[source] = changed = true;
    dist[source] = 0;
    while (changed) {
        changed = false;
        FOR (i,n) if (reach[i]) FOR (j,n) if (cf(i, j))
            if (!reach[j] || dist[i] + costf(i, j) < dist[j]) {
                reach[j] = changed = true;
                dist[j] = dist[i] + costf(i, j);
                prev[j] = i;
            }
    }
    if (!reach[sink]) return 0;
    for (i = sink; i != source; i = prev[i]) pushf(prev[i], i, 1);
    return 1;
}

int mcmf() {
    int ret, x, i, j;
    for (i = 0; i < n; i++) for (j = 0; j < n; j++) flow[i][j] = 0;
    ret = total_cost = 0;
    while (x = augment()) ret += x;
    return ret;
}

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return i;
}


int main() {
    
    int i, j, k, x, y, c;
    for (int t = get_int(), f = 0; t--; ) {
        (f)?putchar('\n'):(f=1);
        m = get_int(); d = get_int(); k = get_int();
        n = m+d+2; source = n-2; sink = n-1;
        for (i = 0; i < n; i++) for (j = 0; j < n; j++) cap[i][j]=cost[i][j]=0;
        for (i = 0; i < m; i++) cap[source][i] = 1;
        for (i = 0; i < d; i++) cap[m+i][sink] = 1;
        for (i = 0; i < k; i++) {
            x = get_int(); y = get_int(); c = get_int();
            cap[x][m+y] = 1; cost[x][m+y] = c;
        }
        mcmf();
        printf("%d\n", total_cost);
    }
    return 0;
}
