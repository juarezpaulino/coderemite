/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/*
 ID: juarezp1
 PROG: fence8
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

const int MAXN = 50;
const int MAXV = 130;

int B[MAXN];
int V[2000];
int U[MAXV];
int S;

int N, M, R;

bool check(int k, int cur, int L, int W) {
    if (k == M) return 1;
    if (W < 0) return 0;
    if (cur == N) return 0;
    for (int i = L; i > 0; i--) if (U[i] > 0) {
        if (B[cur] >= i) {
            B[cur]-=i; U[i]--;
            //printf("k = %d cur = %d L = %d W = %d i = %d\n", k, cur, L, W, i);
            int ret = check(k+1, cur, i, W);
            U[i]++; B[cur]+=i;
            if (ret) return ret;
        }
    }
    return check(k, cur+1, 128, W-B[cur]);
}

int main() {

    freopen("fence8.in","r",stdin);freopen("fence8.out","w",stdout);

    S = 0;
    scanf("%d", &N);
    FOR(i,0,N) scanf("%d", B+i), S += B[i];
    scanf("%d", &R);
    FOR(i,0,R) scanf("%d", V+i);

    sort(B, B+N);
    sort(V, V+R);

    int lo = 0, hi = R+1, ret;
    while (lo < hi) {
        int w;
        M = (hi+lo)/2;
        w = 0; CLR(U,0);
        FOR(i,0,M) U[V[i]]++, w += V[i];
        if (w > S) { hi = M; continue; }
        //printf("%d %d %d\n", lo, hi, M);
        if (check(0,0,128,S-w)) ret = M, lo = M+1; else hi = M;
    }

    printf("%d\n", ret);

    return 0;
}
