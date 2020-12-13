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


// execute "act", and return "val" as an expression result
#define CLC(act,val) ({act; val;})

// find the first k in [a,b) that satisfies cond, or b if none
// using binary search
#define BINFIRST(k,a,b,cond)                \
 CLC(                                       \
   int k##mIn = a; int k##mAx = b; int k;   \
   while(k##mIn != k##mAx) {                \
     k = ((k##mIn)+(k##mAx))>>1;            \
     if(cond) k##mAx = k;                   \
     else k##mIn = k+1;                     \
     },                                     \
   k##mIn                                   \
   )

int n, m, q;
int M[500][500];

int get_int() {
    int ch, i, s;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    s = (ch=='-') ? (ch=getchar(),-1) : 1;
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return s*i;
}


int main() {

    int i, j, k, last;
    int l, u;
    int maxi;
    for(; n = get_int(), m = get_int(), n+m; ) {
        FOR(i,0,n) FOR(j,0,m) M[i][j] = get_int();
        q = get_int();
        while (q--) {
            l = get_int(); u = get_int(); maxi = 0;
            FOR(i,0,n) {
                j = BINFIRST(v,0,m,M[i][v]>=l);
                if (j >= m || M[i][j] > u) continue;
                last = min(n-i,m-j);
                k = BINFIRST(v,0,last,M[i+v][j+v]>u);
                maxi = max(maxi,k);
            }
            printf("%d\n", maxi);
        }
        printf("-\n");
    }

    return 0;
}

