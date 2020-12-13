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

int n;
vector<short> grade[10000];
vector<short> counter[10000];

int main() {

    int i, j, k, x;
    int m = -INF, mini, tot;
    for(; scanf("%d", &n) && n;) {
        tot = 0;
        FOR(i,0,n) {
            grade[i].clear();
            scanf("%d\n", &k);
            FOR(j,0,k) { scanf("%d", &x); grade[i].PB(x); m = max(m,x); tot++; }
        }
        FOR(i,0,n) {
            counter[i] = vector<short>(m+1,0);
            FOR(j,0,SI(grade[i])) counter[i][grade[i][j]]++;
            FORE(j,1,m) counter[i][j]+=counter[i][j-1];
        }
        mini = tot;
        FORE(k,1,m) {
            int t = 0;
            FOR(i,0,n) t+=abs(counter[i][k-1]-(int)(SI(grade[i])-counter[i][k-1]));
            mini=min(mini,t);
        }
        FOR(i,0,n) counter[i].clear();
        printf("%d\n", mini);
    }
    return 0;
}
