/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/*
 ID: juarezp1
 PROG: fence3
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

typedef pair<point, double> circle;

template<class P> double dist(P A, P B = P()) { return sqrt((A-B)*(A-B)); }

bool in_circle(circle C, point p){
    return cmp(dist(p - C.first), C.second) <= 0;
}

point circumcenter(point p, point q, point r) {
    point a = p - r, b = q - r, c = point(a * (p + r) / 2, b * (q + r) / 2);
    return point(c % point(a.y, b.y), point(a.x, b.x) % c) / (a % b);
}

circle spanning_circle(vector<point>& T) {
    int n = SI(T);
    random_shuffle(ALL(T));
    circle C(point(), -DINF);
    FOR(i,0,n) if (!in_circle(C, T[i])) {
        C = circle(T[i], 0);
        FOR(j,0,i) if (!in_circle(C, T[j])) {
            C = circle((T[i] + T[j]) / 2, dist(T[i] - T[j]) / 2);
            FOR(k,0,j) if (!in_circle(C, T[k])) {
                point o = circumcenter(T[i], T[j], T[k]);
                C = circle(o, dist(o - T[k]));
            }
        }
    }
    return C;
}

double seg_distance(point p, point q, point r, bool isSeg) {
    point A = r - q, B = r - p, C = q - p;
    double a = A * A, b = B * B, c = C * C;
    if (isSeg) {
        if (cmp(b, a + c) >= 0) return sqrt(a);
        else if (cmp(a, b + c) >= 0) return sqrt(b);
    }
    return fabs(A % B) / sqrt(c);
}


int N;
vector<point> P;
point F[150][2];

double FUNC(point C) {
    double L = 0;
    FOR(i,0,N) L += seg_distance(F[i][0], F[i][1], C, true);
    return L;
}


int main() {

    freopen("fence3.in","r",stdin);freopen("fence3.out","w",stdout);

    scanf("%d", &N);
    P.resize(N*2);
    FOR(i,0,N) {
        int x, y;
        scanf("%d %d", &x, &y);
        F[i][0] = P[i*2] = point(x, y);
        scanf("%d %d", &x, &y);
        F[i][1] = P[i*2+1] = point(x, y);
    }

    circle C = spanning_circle(P);

    double cur = FUNC(C.first), L = cur;
    point B = C.first, A = B;
    double STEP = 1;
    while (STEP > 0.01) {
       FOR(dx,-1,2) FOR(dy,-1,2) {
            double np = FUNC(A + point(dx*STEP,dy*STEP));
            if (cmp(np,L) < 0) {
                L = np;
                B = A + point(dx*STEP,dy*STEP);
            }
        }
        if (cmp(L,cur) < 0) A = B, cur = L;
        else STEP /= 2;
    }

    printf("%.1lf %.1lf %.1lf\n", B.x, B.y, L);

    return 0;
}
