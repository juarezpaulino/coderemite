/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/*
 ID: juarezp1
 PROG: milk3
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
const double DINF = 1E14;
const double EPS = 1E-14;
const double PI = 3.1415926535897932384626433832795;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

template<class T> T SQR(T x) { return x*x; }

template <class T> T gcd(T a, T b) { return (b!=0) ? gcd(b, a % b) : a; }

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

const int MAXV = 21;

int A, B, C;
VI RET;

char DISC[MAXV*MAXV*MAXV];

inline int encode(int X, int Y, int Z) {
    return X*MAXV*MAXV+Y*MAXV+Z;
}

inline void decode(int V, int &X, int &Y, int &Z) {
    Z = V%MAXV; V/=MAXV;
    Y = V%MAXV; V/=MAXV;
    X = V;
}

void milk(int X, int Y, int Z) {
    int e = encode(X,Y,Z);
    if (DISC[e]) return;
    DISC[e] = 1;
    if (X == 0) RET.PB(Z);

    int v;
    if (X) {
        v = B-Y; (X > v) ? milk(X-v,B,Z) : milk(0,Y+X,Z);
        v = C-Z; (X > v) ? milk(X-v,Y,C) : milk(0,Y,Z+X);
    }
    if (Y) {
        v = A-X; (Y > v) ? milk(A,Y-v,Z) : milk(X+Y,0,Z);
        v = C-Z; (Y > v) ? milk(X,Y-v,C) : milk(X,0,Z+Y);
    }
    if (Z) {
        v = A-X; (Z > v) ? milk(A,Y,Z-v) : milk(X+Z,Y,0);
        v = B-Y; (Z > v) ? milk(X,B,Z-v) : milk(X,Y+Z,0);
    }
}

int main() {

    freopen("milk3.in","r",stdin);freopen("milk3.out","w",stdout);

    scanf("%d%d%d",&A,&B,&C);

    milk(0,0,C);

    UNIQUE(RET);

    FOR(i,0,SI(RET)) printf(i==SI(RET)-1 ? "%d\n" : "%d ", RET[i]);

    return 0;
}
