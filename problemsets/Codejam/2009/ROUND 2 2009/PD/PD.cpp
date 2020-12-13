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
 * Primos
 * Médios: 5011 8837 8839 8849 8861 8863 8867 8887 8893 8923 8929 8933
 *         8941 8951 8963 8969 8971 8999 9001 9007 9011 9013 9029
 *         9041 9043 9049 9059 9067 9091 9103 9109 9127 9133 9137
 * Grandes: 80963,127597,263911,263927,413683,567899,713681
 *          37625701, 236422117, 9589487273, 9589487329, 694622169483311
 *
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

inline int ccw(point p, point q, point r) {
    return cmp((p - r) % (q - r));
}


bool in_circle(circle C, circle P) {
    return cmp(dist(C.first, P.first)+P.second, C.second) <= 0;
}

void farthest_circle_points(circle &A, circle &B, point &a, point &b) {
    double theta = atan2(B.first.y - A.first.y, B.first.x - A.first.x);
    a = point(A.first.x - cos(theta)*A.second, A.first.y - sin(theta)*A.second);
    b = point(B.first.x + cos(theta)*B.second, B.first.y + sin(theta)*B.second);
}

circle circumcenter(circle &C1, circle &C2) {
    point a, b;
    farthest_circle_points(C1, C2, a, b);
    double r = dist(a,b)/2;
    if (cmp(r,C1.second) < 0) return C1;
    if (cmp(r,C2.second) < 0) return C2;
    return circle((a+b)/2, r);
}

////////////////////////////////////////////////////////////////////////////////
// Appolonius: Find all possible circles that intersect three given circles on
// boundary.
// - Change +- sign for each r1, r2, r3 parameters to get a different solution.
////////////////////////////////////////////////////////////////////////////////
circle appolonius(circle &C1, circle &C2, circle &C3) {
    // Solve appolonius equations.
    double x1 = C1.first.x, y1 = C1.first.y, r1 = C1.second;
    double x2 = C2.first.x, y2 = C2.first.y, r2 = C2.second;
    double x3 = C3.first.x, y3 = C3.first.y, r3 = C3.second;
    double a = 2*(x1-x2), b = 2*(y1-y2), c = 2*(-r1+r2);// c = 2*("+-r1""+-r2")
    double d = (x1*x1 + y1*y1 - r1*r1) - (x2*x2 + y2*y2 - r2*r2);
    double e = 2*(x1-x3), f = 2*(y1-y3), g = 2*(-r1+r3);// g = 2*("+-r1""+-r3")
    double h = (x1*x1 + y1*y1 - r1*r1) - (x3*x3 + y3*y3 - r3*r3);
    double K1 = (f*d - b*h) / (a*f - b*e), K2 = (b*g - f*c) / (a*f - b*e);
    double K3 = (a*h - e*d) / (a*f - b*e), K4 = (e*c - a*g) / (a*f - b*e);
    double A = K2*K2 + K4*K4 - 1;   // A = K2*K2 + K4*K4 "+-1"
    double B = 2*(K1*K2 - x1*K2 + K3*K4 - y1*K4 + r1);
    // B = 2*(K1*K2 - x1*K2 + K3*K4 - y1*K4 "+-r1")
    double C = K1*K1 - 2*x1*K1 + x1*x1 + K3*K3 - 2*y1*K3 + y1*y1 - r1*r1;
    // C = K1*K1 - 2*x1*K1 + x1*x1 + K3*K3 - 2*y1*K3 + y1*y1 "+-r1*r1"
    double R = (-B - sqrt(B*B - 4*A*C)) / (2*A);
    double X = K1 + K2*R, Y = K3 + K4*R;
    return circle(point(X,Y), R);
}

circle circumcenter(circle &C1, circle &C2, circle &C3) {
    double d1 = dist(C1.first,C2.first), d2 = dist(C2.first,C3.first),
           d3 = dist(C1.first,C3.first);
    if (ccw(C1.first,C2.first,C3.first) == 0) {
        if (cmp(d1+d2,d3)==0) return circumcenter(C1,C3);
        if (cmp(d1+d3,d2)==0) return circumcenter(C2,C3);
        return circumcenter(C1,C2);
    }
    if (in_circle(C2, C1) || in_circle(C3, C1)) return circumcenter(C2, C3);
    if (in_circle(C1, C2) || in_circle(C3, C2)) return circumcenter(C1, C3);
    if (in_circle(C1, C3) || in_circle(C2, C3)) return circumcenter(C1, C2);
    return appolonius(C1, C2, C3);
}

////////////////////////////////////////////////////////////////////////////////
// Spanning circle for a set of circles.
// - Call: spanning_circle(I (full), B (empty), N, 0);
// - Expected runtime: O(N)
////////////////////////////////////////////////////////////////////////////////
circle spanning_circle(vector<circle> &I, vector<circle> &B, int i, int b) {
    if (i == 0) {
        if (b == 0) return circle(point(), 0);
        if (b == 1) return B[0];
        if (b == 2) return circumcenter(B[0], B[1]);
    }
    if (b >= 3) return circumcenter(B[0], B[1], B[2]);
    circle C = spanning_circle(I, B, i-1, b);
    if (!in_circle(C, I[i-1])) {
        B[b] = I[i-1]; C = spanning_circle(I, B, i-1, b+1);
    }
    return C;
}

int N;
vector<circle> V;


int main() {
    
//	freopen("D.in","r",stdin);
//	freopen("D-small-practice.in","r",stdin);freopen("D-small-practice.out","w",stdout);
	freopen("D-large-practice.in","r",stdin);freopen("D-large-practice.out","w",stdout);
//	freopen("D-small-attempt0.in","r",stdin);freopen("D-small-attempt0.out","w",stdout);
//	freopen("D-small-attempt1.in","r",stdin);freopen("D-small-attempt1.out","w",stdout);
//	freopen("D-small-attempt2.in","r",stdin);freopen("D-small-attempt2.out","w",stdout);
//	freopen("D-large.in","r",stdin);freopen("D-large.ans","w",stdout);

    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        // Read input.
        scanf("%d", &N); V.resize(N);
        FOR(i,0,N) scanf("%lf%lf%lf", &V[i].first.x, &V[i].first.y, &V[i].second);
        random_shuffle(ALL(V));

        double m, t, dt = PI/4, ret = DINF;
        for (t = 0; t < PI+EPS; t+=dt) { m = tan(t); FOR(i,0,N) {
            vector<circle> S1, S2, B1, B2;
            FOR(j,0,N)
                cmp(V[j].first.y, m*(V[j].first.x-V[i].first.x)+V[i].first.y) <= 0
                ? S1.PB(V[j]) : S2.PB(V[j]);

            B1.resize(N); B2.resize(N);
            double r1 = spanning_circle(S1, B1, SI(S1), 0).second;
            double r2 = spanning_circle(S2, B2, SI(S2), 0).second;
            ret = min(ret, max(r1,r2));
        }}
        
        // Prints result.
        printf("Case #%d: %.10lf\n", tc, ret);
    }

	return 0;
}
