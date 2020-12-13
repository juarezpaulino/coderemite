/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/***********************************************************************************************************/
/*                                 Declarations, macros, parser functions                                  */
/***********************************************************************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>

using namespace std;

#define FOR(i,m,n) for((i)=(m);(i)<(n);(i)++)
#define FORE(i,m,n) for((i)=(m);(i)<=(n);(i)++)
#define ROF(i,m,n) for((i)=(m);(i)>=(n);(i)--)
#define _FORIT(it, b, e) for (__typeof(b) it = (b); it != (e); it++)
#define FORIT(x...) _FORIT(x)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define SI(a) ((a).size())
#define PB push_back
#define MP make_pair
#define CLR(a,v) memset((a),(v),sizeof(a))
#define SORT(v) sort(ALL(v))
#define UNIQUE(v) SORT(v),(v).resize(unique(ALL(v))-(v).begin())


inline string ITOA(int a) {
    char c[500]; sprintf(c, "%d", (a)); return string(c);
}

typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VD> VVD;
typedef vector<VS> VVS;
typedef pair<int,int> PII;
typedef signed long long i64;
typedef unsigned long long u64;

#define EPS 1E-9
#define INF 0x3F3F3F3F
#define DINF 1E16
#define NULO -1
#define PI 3.1415926535897932384626433832795

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

VI adj[100010];
int val[100010], deg[100010];
int n, t;

int dfs(int v) {
    int i, x;
    VI filhos;
    if (SI(adj[v])==0) return (val[v] = 1);
    FOR(i,0,SI(adj[v])) {
        x = adj[v][i]; filhos.PB(dfs(x));
    }
    SORT(filhos);
//    printf("%d %d %d: ", v, n, t); FOR(i,0,SI(filhos)) printf("%d ", filhos[i]); putchar('\n');
    double p; int ret = 0;
    FOR(i,0,SI(filhos)) {
        ret+=filhos[i];
        p = i+1; p/=deg[v]; if (p*100.+EPS > t) return ret;
    }
}

int main() {

    int i, x;
    for(; scanf("%d %d", &n, &t) && n+t; ) {
        FORE(i,0,n) deg[i] = 0, val[i] = 0, adj[i].clear();
        FORE(i,1,n) { scanf("%d", &x); adj[x].PB(i); deg[x]++; }
        printf("%d\n", dfs(0));
    }

    return 0;
}

