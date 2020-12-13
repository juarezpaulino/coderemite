/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/*
 ID: juarezp1
 PROG: ratios
 LANG: C++
*/

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>


using namespace std;

#define FOR(i,a,b) for (int (i) = (a); (i) < (b); (i)++)
#define _FORIT(it, b, e) for (__typeof(b) it = (b); it != (e); it++)
#define FORIT(x...) _FORIT(x)
#define ALL(M) (M).begin(), (M).end()
#define CLR(M, v) memset(M, v, sizeof(M))
#define SI(V) (int)(V.size())
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SORT(M) sort(ALL(M))
template<class T> inline void SORTG(vector<T> &M) { sort(ALL(M), greater<T>()); }
#define UNIQUE(v) SORT(v),(v).resize(unique(ALL(v))-(v).begin())

typedef long long i64;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;

const int INF = 0x3F3F3F3F;
const i64 LINF = 0x3F3F3F3F3F3F3F3FLL;
const double DINF = 1E16;
const double EPS = 1E-14;
const double PI = 3.1415926535897932384626433832795;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

template<class T> T SQR(T x) { return x*x; }

template <class T> T gcd(T a, T b) { return (b!=0) ? gcd(b, a % b) : a; }

inline string ITOA(int a) { char c[500]; sprintf(c,"%d",(a)); return string(c); }

inline int POPC(int a) { return __builtin_popcount(a); }

/*******************************************************************************
 * HASH
 ******************************************************************************/
struct STATE {
    int X[20], Y[20], deg;
    bool operator==(const STATE& S) const {
        for (int i = 0; i < 20; i++)
            if (X[i]!=S.X[i] || Y[i]!=S.Y[i]) return false;
        return true;
    }
};
#ifdef VCC
#include<hash_map>
#include<hash_set>
using namespace stdext;
#else
#include<ext/hash_map>
#include<ext/hash_set>
using namespace __gnu_cxx;
namespace __gnu_cxx {
	template<> struct hash<string> {
		size_t operator()(const string& X) const {
			return hash<const char*>() (X.c_str());
		}
	};
	template<> struct hash<STATE> {
		size_t operator()(const STATE& S) const {
            size_t p = 0;
            for (int i = 0; i < 20; i++) { p |= 1<<(S.Y[i]*6 + S.X[i]); }
            return p;
		}
	};
}
#endif

////////////////////////////////////////////////////////////////////////////////

int G[3];
int V[3][3];

int mod(int A, int m) { return m==0 ? 0 : A%m; }

int main() {

    freopen("ratios.in","r",stdin);freopen("ratios.out","w",stdout);

    FOR(i,0,3) scanf("%d", G+i);
    FOR(i,0,3) FOR(j,0,3) scanf("%d", &V[i][j]);

    // Try everytihng.
    int A, B, C, D = -1;
    int ca, cb, cc, cd;
    for (ca=0;ca<100;ca++) for (cb=0;cb<100;cb++) for (cc=0;cc<100;cc++) {
        if (ca==0 && cb==0 && cc==0) continue;
        int b = ca*V[0][0]+cb*V[1][0]+cc*V[2][0];
        int o = ca*V[0][1]+cb*V[1][1]+cc*V[2][1];
        int w = ca*V[0][2]+cb*V[1][2]+cc*V[2][2];
        cd = G[0]!=0 ? b/G[0] : G[1]!=0 ? o/G[1] : w/G[2];
        if (mod(b,G[0])==0 && mod(o,G[1])==0 && mod(w,G[2])==0 &&
            cd*G[0]==b && cd*G[1]==o && cd*G[2]==w) {
            if (D==-1 || A+B+C > ca+cb+cc) {
                A = ca; B = cb; C = cc; D = cd;
            }
        }
    }

    if (D==-1) printf("NONE\n");
    else printf("%d %d %d %d\n", A, B, C, D);

    return 0;
}
