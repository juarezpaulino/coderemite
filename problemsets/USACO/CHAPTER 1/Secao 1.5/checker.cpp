/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/*
 ID: juarezp1
 PROG: checker
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

inline string ITOA(int a) { char c[500]; sprintf(c,"%d",(a)); return string(c); }

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

const int MAXV = 13;

int N, ret;
int CAND[MAXV];
int V[MAXV];
char D1[2*MAXV];
char D2[2*MAXV];
char C[MAXV];

void checker1(int r) {
    if (r == N) {
        if (ret < 3) FOR(i,0,N) printf((i == N-1) ? "%d\n" : "%d ", V[i]+1);
        ret++;
        return;
    }
    FOR(i,0,N) if (!C[i] && !D1[r+i] && !D2[r+N-i]) {
        if (ret < 3) V[r] = i;
        C[i] = D1[r+i] = D2[r+N-i] = 1;
        checker1(r+1);
        C[i] = D1[r+i] = D2[r+N-i] = 0;
        if (ret >= 3) return;
    }
}

void checker2(int r) {
    if (r == N) { ret++; return; }
    FOR(i,0,N-r) {
        int x = CAND[i];
        if (!C[x] && !D1[r+x] && !D2[r+N-x]) {
            swap(CAND[i], CAND[N-r-1]);
            C[x] = D1[r+x] = D2[r+N-x] = 1;
            checker2(r+1);
            C[x] = D1[r+x] = D2[r+N-x] = 0;
            swap(CAND[i], CAND[N-r-1]);
        }
    }
}


int main() {

    freopen("checker.in","r",stdin);freopen("checker.out","w",stdout);

    scanf("%d", &N);

    checker1(0);

    ret = 0; FOR(i,0,N) CAND[i] = i;
    checker2(0);

    printf("%d\n", ret);

    return 0;
}
