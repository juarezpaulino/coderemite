/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/*
 ID: juarezp1
 PROG: cryptcow
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

const int MAXV = 80;
const int GLEN = 47;

char GOAL[] = "Begin the Escape execution at the Break of Dawn";

// Input.
char S[MAXV];
int N;

int moves;

char HASH[413683];

inline bool FH(char *S) {
    i64 j, h, n = strlen(S);
    h = 0;
    FOR(i,0,n) {
        h = (h<<4) + S[i];
        j = h & 0xF0000000;
        if (j != 0) h = h^(j>>24);
        h = h & ~j;
    }
    h = h % 413683;
    if (HASH[h]) return 0;
    HASH[h] = 1;
    return 1;
}

bool check(char *U) {
    int k, j, n = strlen(U), m;
    char T[MAXV];
    FOR(i,0,n) if (U[i]=='C' || U[i]=='O' || U[i]=='W') {
        for (j = i+1; j < n; j++) if (U[j]=='C' || U[j]=='O' || U[j]=='W') break;
        m = 0;
        for (k = i+1; k < j; k++) T[m++] = U[k];
        if (m==0) continue;
        k = 0;
        for (j = 0; j < m; j++) {
            if (T[j]=='C' || T[j]=='O' || T[j]=='W') continue;
            T[k++] = T[j];
        }
        T[k] = 0;
        if (strstr(GOAL,T)==NULL) return 0;
    }
    return 1;
}

void run(int k, char *U) {
    int N = strlen(U);
    char T[MAXV];
    if (!strcmp(GOAL,U)) {
        printf("1 %d\n", k);
        exit(0);
    }
    FOR(i,1,N-1) if (U[i]=='O')
    for (int j = i-1; j >= 0; j--) if (U[j]=='C')
    for (int w = N-1; w >= i+1; w--) if (U[w]=='W') {
        int M = 0;
        FOR(l,0,j) T[M++] = U[l];
        FOR(l,i+1,w) T[M++] = U[l];
        FOR(l,j+1,i) T[M++] = U[l];
        FOR(l,w+1,N) T[M++] = U[l];
        T[M] = 0;
        if (!FH(T)) continue;
        if (!check(T)) continue;
        run(k+1, T);
    }
}

int main() {

    freopen("cryptcow.in","r",stdin);freopen("cryptcow.out","w",stdout);

    gets(S); N = strlen(S);

    if (N % 3 != 2) { puts("0 0"); return 0; }

    run(0, S);

    puts("0 0");

    return 0;
}
