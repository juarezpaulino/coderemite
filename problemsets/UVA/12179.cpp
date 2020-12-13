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

#define MAXR 35
#define INF 0x3F3F3F3F
#define MAXV 120


int n, r, q, maxd, dist[MAXV][MAXV];
double dp[MAXV][MAXV*MAXR];

void do_prob() {
    int i, j, k;
    FOR(i, maxd) FOR(j, maxd*r) dp[i][j] = 0.;
    FOR(j, maxd*r) dp[0][j] = 1.;
    for (i = 1; i < maxd; i++) FOR(j, maxd*r) for (k = j-1; k>=0 && j-k<=r; --k)
        dp[i][j] += dp[i-1][k]/(double)r;
}

void floyd_warshall() {
    int i, j, k, d;
    FOR(k, n) FOR(i, n) FOR(j, n) {
        d = dist[i][k] + dist[k][j];
        if (dist[i][j] > d) dist[i][j] = d, maxd = max(maxd,d);
    }
}

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    ungetc(ch, stdin);
    return i;
}


int main() {

    int t, c, i, j;
    int a, b, m;
    char str[1000];
    for (t = get_int(), c = 1; c <= t; c++) {
        printf("Case %d\n", c);
        n = get_int(), r = get_int();
        FOR(i, n) {
            gets(str); FOR(j, n) dist[i][j] = str[j]=='Y'?1:INF; dist[i][i] = 0;
        }
        maxd = 1; floyd_warshall(); maxd++;
        do_prob();
        for (q = get_int(); q--; ) {
            a = get_int()-1, b = get_int()-1, m = get_int();
            m = min(m,(maxd-1)*r); printf("%.8lf\n", dp[dist[a][b]][m]);
        }
        putchar('\n');
    }
    return 0;
}
