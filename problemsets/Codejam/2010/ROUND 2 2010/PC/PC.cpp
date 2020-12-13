/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
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
const double EPS = 1E-10;
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
    template<> struct hash<VI> {
		size_t operator()(const VI& S) const {
            size_t p = 0;
            FOR(i,0,SI(S)) p = (p*10) + S[i];
            return p;
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

const int MAXV = 140;
int R;
char MAPA[MAXV][MAXV];


void run() {
    char M2[MAXV][MAXV];
    CLR(M2,0);
    FOR(i,1,MAXV) FOR(j,1,MAXV) {
        if (MAPA[i][j]==0 && MAPA[i-1][j] && MAPA[i][j-1])
            M2[i][j] = 1;
        else if (MAPA[i][j]==1 && (MAPA[i-1][j] || MAPA[i][j-1]))
            M2[i][j] = 1;
    }
    FOR(i,0,MAXV) FOR(j,0,MAXV) MAPA[i][j] = M2[i][j];
}

int main() {

//	freopen("C.in","r",stdin);
//  freopen("C-small-practice.in","r",stdin);freopen("C-small-practice.out","w",stdout);
//	freopen("C-large-practice.in","r",stdin);freopen("C-large-practice.out","w",stdout);
	freopen("C-small-attempt0.in","r",stdin);freopen("C-small-attempt0.out","w",stdout);
//	freopen("C-small-attempt1.in","r",stdin);freopen("C-small-attempt1.out","w",stdout);
//	freopen("C-small-attempt2.in","r",stdin);freopen("C-small-attempt2.out","w",stdout);
//	freopen("C-large.in","r",stdin);freopen("C-large.ans","w",stdout);

    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        // Read input.
        CLR(MAPA,0);
        scanf("%d", &R);
        FOR(i,0,R) {
            int x1, x2, y1, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            x1+=20; x2+=20; y1+=20; y2+=20;
            if (x1 > x2) swap(x1,x2);
            if (y1 > y2) swap(y1,y2);
            FOR(i,x1,x2+1) FOR(j,y1,y2+1) MAPA[j][i] = 1;
        }

        int ret = 0;
        while (1) {
            bool ok = false;
            FOR(i,0,MAXV) FOR(j,0,MAXV) if (MAPA[i][j]==1) { ok = true; break; }
            if (!ok) break;
            ret++;
            run();
        }

        // Prints result.
        printf("Case #%d: %d\n", tc, ret);
    }

	return 0;
}
