/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/*
 ID: juarezp1
 PROG: fence4
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

struct point {
    double x, y;
    point(double x = 0, double y = 0): x(x), y(y) {}
    point operator +(point q) { return point(x + q.x, y + q.y); }
    point operator -(point q) { return point(x - q.x, y - q.y); }
    point operator *(double t) { return point(x * t, y * t); }
    point operator /(double t) { return point(x / t, y / t); }
    double operator *(point q) { return x * q.x + y * q.y; }
    double operator %(point q) { return x * q.y - y * q.x; }
    int cmp(point q) const {
        if (int t = ::cmp(x, q.x)) return t;
        return ::cmp(y, q.y);
    }
    bool operator ==(point q) const { return cmp(q) == 0; }
    bool operator !=(point q) const { return cmp(q) != 0; }
    bool operator < (point q) const { return cmp(q) < 0; }
    friend ostream& operator <<(ostream& o, point p) {
        return o << "(" << p.x << ", " << p.y << ")";
    }
    static point pivot;
};
point point::pivot;

template<class P> double dist(P A, P B = P()) { return sqrt((A-B)*(A-B)); }
template<class P> double sqrdist(P A, P B = P()) { return (A-B)*(A-B); }
template<class P> double arg(P p) { return atan2(p.y, p.x); }

inline int ccw(point p, point q, point r) {
    return cmp((p - r) % (q - r));
}

bool between(point p, point q, point r) {
    return ccw(p, q, r)==0 && cmp((p - q)*(r - q)) <= 0;
}

////////////////////////////////////////////////////////////////////////////////
// seg_intersect
//
// Verify if AB intersects CD, and return possible intersection on P.
// Return 0 / 1 / 2 - No_intersection / cross / lie_on.
//
////////////////////////////////////////////////////////////////////////////////
point cross_point;
int seg_intersect(point A, point B, point C, point D, point& P = cross_point) {
    if (A==C || A==D || B==C || B==D) return 2;
	double s1,s2,s3,s4;
	int d1 = cmp(s1=(A-C)%(B-C));
	int d2 = cmp(s2=(A-D)%(B-D));
	int d3 = cmp(s3=(C-A)%(D-A));
	int d4 = cmp(s4=(C-B)%(D-B));
	if(d1*d2 < 0 && d3*d4 < 0) {
	    P.x = (C.x*s2 - D.x*s1) / (s2-s1);
	    P.y = (C.y*s2 - D.y*s1) / (s2-s1);
		return 1;
	}
	if ((d1==0 && between(A,C,B)) ||
        (d2==0 && between(A,D,B)) ||
        (d3==0 && between(C,A,D)) ||
        (d4==0 && between(C,B,D)) )
		return 2;
	return 0;
}

const int MAXV = 210;

int N;
point O;
point P[MAXV];
bool V[MAXV];

int first_intersect(point &O, point &E) {
    int p = N; double d = DINF;
    FOR(i,0,N) {
        int j = (i+1)%N;
        int c = seg_intersect(O,E,P[i],P[j]);
        if (c == 0) continue;
        if (c == 2) return N;
        double cur = sqrdist(O, cross_point);
        if (cur < d) { d = cur; p = i; }
    }
    return p;
}

double dy[] = { -1E-3, -1E-3, -1E-3, 0, 0, 1E-3, 1E-3, 1E-3 };
double dx[] = { -1E-3, 0, 1E-3, -1E-3, 1E-3, -1E-3, 0, 1E-3 };

int main() {

    freopen("fence4.in","r",stdin);freopen("fence4.out","w",stdout);

    scanf("%d", &N);
    scanf("%lf %lf", &O.x, &O.y);
    FOR(i,0,N) scanf("%lf %lf", &P[i].x, &P[i].y);

    // Check if its simple.
    FOR(i,0,N) FOR(j,0,N) if (i != j) {
        int k = (i+1)%N, l = (j+1)%N;
        if (seg_intersect(P[i],P[k],P[j],P[l])==1) {
            printf("NOFENCE\n"); return 0;
        }
    }

    CLR(V,0);
    // Check visibility for all points.
    FOR(i,0,N) {
        FOR(k,0,8) {
            point R = P[i];
            R.x += dx[k]; R.y += dy[k];
            V[first_intersect(O,R)] = 1;
        }
        FOR(k,0,8) {
            point R = (P[i]+P[(i+1)%N])/2;
            R.x += dx[k]; R.y += dy[k];
            V[first_intersect(O,R)] = 1;
        }
    }

    int ret = 0;
    FOR(i,0,N) if (V[i]) ret++;
    printf("%d\n", ret);

    FOR(i,0,N-2) if (V[i]) {
        int j = (i+1)%N;
        printf("%d %d %d %d\n", (int)P[i].x, (int)P[i].y, (int)P[j].x, (int)P[j].y);
    }
    if (V[N-1]) printf("%d %d %d %d\n", (int)P[0].x, (int)P[0].y, (int)P[N-1].x, (int)P[N-1].y);
    if (V[N-2]) printf("%d %d %d %d\n", (int)P[N-2].x, (int)P[N-2].y, (int)P[N-1].x, (int)P[N-1].y);

    return 0;
}
