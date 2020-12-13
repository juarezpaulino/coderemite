/*
 ID: juarezp1
 PROG: packrec
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
typedef pair<short,short> PII;

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

int A;
set<PII> RET;
int W[4], H[4], P[4];


void insert(int w, int h) {
    if (w*h < A) { A = w*h; RET.clear(); }
    else if (w*h == A) RET.insert(PII(min(w,h),max(w,h)));
}

// Check all 6 possible configurations.
void check(int *W, int *H) {
    int w, h;

    // Case 0: All alligned.
    w = h = 0;
    FOR(i,0,4) w += W[i], h = max(h, H[i]);
    insert(w,h);

    // Case 1: Three aligned, fourth on bottom.
    w = h = 0;
    FOR(i,0,3) w += W[i], h = max(h, H[i]);
    w = max(w, W[3]); h += H[3];
    insert(w,h);

    // Case 2: Two alligned, third bottom, fourth aligned.
    w = h = 0;
    FOR(i,0,2) w += W[i], h = max(h, H[i]);
    w = max(w, W[2]); h += H[2];
    w += W[3]; h = max(h, H[3]);
    insert(w,h);

    // Case 3,4: Two alligned, two stacked.
    w = h = 0;
    FOR(i,0,2) w += W[i], h = max(h, H[i]);
    w = w + max(W[2], W[3]); h = max(h, H[2]+H[3]);
    insert(w,h);

    // Case 5: first two pressed, next two on top.
    w = W[0] + W[1];
    h = max(H[0]+H[2], H[1]+H[3]);
    if(H[0] < H[1]) w = max(w, W[2]+W[1]);
    if(H[1] < H[0]) w = max(w, W[0]+W[3]);
    if(H[0]+H[2] > H[1]) w = max(w, W[2]+W[3]);
    w = max(w, W[2]);
    w = max(w, W[3]);
    insert(w,h);
}

int main() {

    freopen("packrec.in","r",stdin);freopen("packrec.out","w",stdout);

    FOR(i,0,4) P[i] = i, scanf("%d %d", W+i, H+i);

    A = INF;
    do {
        int W2[4], H2[4];
        FOR(i,0,4) W2[i] = W[P[i]], H2[i] = H[P[i]];
        FOR(k,0,1<<4) {
            FOR(i,0,4) if (k&(1<<i)) swap(W2[i],H2[i]);
            check(W2, H2);
            FOR(i,0,4) if (k&(1<<i)) swap(W2[i],H2[i]);
        }
    } while (next_permutation(P, P+4));

    printf("%d\n", A);
    FORIT(it, ALL(RET)) printf("%d %d\n", it->FI, it->SE);

    return 0;
}
