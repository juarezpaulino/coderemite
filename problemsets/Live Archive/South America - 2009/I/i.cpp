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

i64 nCm(int n, int m) {
    int k = (m > (n-m)) ? m : (n-m);
    i64 c = 1, d = 1, i, j;
    for (j = 1, i = k+1; i <= n; i++, j++) {
        c *= i; d *= j;
        if (!(c%d) && (d != 1)) { c /= d; d = 1;}
    }
    return c;
}


int n;
int X[1000], Y[1000];


int main() {
    
    int i, j, k, c;
    i64 dx, dy, ret;
    for(; scanf("%d", &n) && n; ) {
        FOR(i,0,n) scanf("%d %d", &X[i], &Y[i]);
        vector<vector<i64> > D(n, vector<i64>(n));
        FOR(i,0,n) FOR(j,i,n) {
            dx = X[i]-X[j], dy = Y[i]-Y[j];
            D[i][j] = D[j][i] = dx*dx+dy*dy;
        }
        FOR(i,0,n) SORT(D[i]);
        c = 0; dx = -1; ret = 0;
        FOR(i,0,n) {
            FOR(j,0,n) {
                if (D[i][j]!=dx) {
                    if (c>=2) { ret+=nCm(c,2); }
                    dx = D[i][j]; c = 1;
                }
                else c++;
            }
            if (c>=2) { ret+=nCm(c,2); c = 0; dx = -1;}
        }
        printf("%lld\n", ret);
    }

    return 0;
}
