/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/*
 ID: juarezp1
 PROG: rect1
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

const int MAXV = 5000;
const int MAXC = 2500;

int A, B, N;
int C[MAXC];

struct Rect { int x1,y1,x2,y2,c; };

Rect R[MAXV];
int NR;

////////////////////////////////////////////////////////////////////////////////
// cut_intersect
//
// Decide how many intersections between two squares A and B.
//
// In case of intersections, cut rect A on smaller rectangles and return on RET.
//
// Returns -1/0/n on case of A inside/no_intersection/n intersections relate
// to B.
////////////////////////////////////////////////////////////////////////////////
int cut_intersect(Rect &A, Rect &B, Rect RET[4]) {
    // No intersection.
    if (B.x2 <= A.x1 || B.x1 >= A.x2) return 0;
    if (B.y2 <= A.y1 || B.y1 >= A.y2) return 0;

    // A inside B.
    if (B.x1<=A.x1 && B.x2>=A.x2 && B.y1<=A.y1 && B.y2>=A.y2) return -1;

    // Cut A processing his left/right/down/up parts.
    int n = 0;
    Rect r;
    if (B.x1 > A.x1) {
        r = A; r.x2 = B.x1;
        RET[n++] = r;
        A.x1 = B.x1;
    }
    if (B.x2 < A.x2) {
        r = A; r.x1 = B.x2;
        RET[n++] = r;
        A.x2 = B.x2;
    }
    if (B.y1 > A.y1) {
        r = A; r.y2 = B.y1;
        RET[n++] = r;
        A.y1 = B.y1;
    }
    if (B.y2 < A.y2) {
        r = A; r.y1 = B.y2;
        RET[n++] = r;
        A.y2 = B.y2;
    }

    return n;
}

int main() {

    freopen("rect1.in","r",stdin);freopen("rect1.out","w",stdout);

    scanf("%d%d%d", &A, &B, &N);

    R[0] = (Rect){0,0,A,B,0};
    Rect CUT[4];
    NR = 1;
    FOR(i,0,N) {
        int x1, x2, y1, y2, c; scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
        Rect r = (Rect){x1,y1,x2,y2,c-1};
        FOR(j,0,NR) {
            int k = cut_intersect(R[j],r,CUT);
            if (k == 0) continue;
            if (k == -1) {
                memmove(R+j, R+j+1, sizeof(Rect)*NR-j-1);
                NR--; j--;
                continue;
            }
            R[j] = CUT[--k];
            while (k) { R[NR++] = CUT[--k]; }
        }
        R[NR++] = r;
    }

    CLR(C,0);
    FOR(i,0,NR) C[R[i].c] += (R[i].x2-R[i].x1)*(R[i].y2-R[i].y1);

    FOR(i,0,MAXC) if (C[i]) printf("%d %d\n", i+1, C[i]);

    return 0;
}
