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

template<class P> double dist(P A, P B = P()) { return sqrt((A-B)*(A-B)); }

struct Point3D {
    double x, y, z;
    Point3D(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
    Point3D normal() { double l = dist(*this); return (!cmp(l)) ? *this : Point3D(x/l, y/l, z/l); }
    Point3D operator+(Point3D q) { return Point3D(x+q.x, y+q.y, z+q.z); }
    Point3D operator-(Point3D q) { return Point3D(x-q.x, y-q.y, z-q.z); }
    Point3D operator*(double t) { return Point3D(x*t, y*t, z*t); }
    Point3D operator/(double t) { return Point3D(x/t, y/t, z/t); }
    double operator*(Point3D q) { return x*q.x + y*q.y + z*q.z; }
    Point3D cross(Point3D q) { return Point3D(y*q.z-z*q.y, z*q.x-x*q.z, x*q.y-y*q.x); }
    double operator%(Point3D q) {
        double l1 = dist(*this), l2 = dist(q), l3 = this->normal()*q.normal();
        l3 = sqrt(fabs(1.-l3*l3));
        return l1*l2*l3;
    }
    int cmp(Point3D q) const {
        int t;
        if (t = ::cmp(x, q.x)) return t;
        if (t = ::cmp(y, q.y)) return t;
        return ::cmp(z, q.z);
    }
    bool operator ==(Point3D q) const { return cmp(q) == 0; }
    bool operator !=(Point3D q) const { return cmp(q) != 0; }
    bool operator < (Point3D q) const { return cmp(q) < 0; }
    friend ostream& operator <<(ostream& o, Point3D p) {
        return o << "(" << p.x << ", " << p.y << ", " << p.z << ")";
    }
};

struct Line3D {
    Point3D P, V;
    // Use v = true if P2 is the velocity vector.
    Line3D(Point3D P1, Point3D P2, bool v = false) : P(P1) { v ? V=P2 : V=P2-P1; }
    Point3D operator[](double t) { return Point3D(P+V*t); }
    double closest_time(Point3D Q) {
        if (V==Point3D()) return 0.;
        Point3D P2 = (*this)[1.];
        return -((P-Q)*(P2-P))/((P2-P)*(P2-P));
    }
    Point3D closest_point(Point3D Q) { return (*this)[closest_time(Q)]; }
    double closest_dist(Point3D Q) {
        if (V==Point3D()) return dist(P,Q);
        return dist(Q,(*this)[closest_time(Q)]);
    }
};

Point3D PAV, VAV;
int N;



int main() {
    
//	freopen("B.in","r",stdin);
	freopen("B-small-practice.in","r",stdin);freopen("B-small-practice.out","w",stdout);
//	freopen("B-large-practice.in","r",stdin);freopen("B-large-practice.out","w",stdout);
//	freopen("B-small-attempt0.in","r",stdin);freopen("B-small-attempt0.out","w",stdout);
//	freopen("B-small-attempt1.in","r",stdin);freopen("B-small-attempt1.out","w",stdout);
//	freopen("B-small-attempt2.in","r",stdin);freopen("B-small-attempt2.out","w",stdout);
//	freopen("B-large.in","r",stdin);freopen("B-large.ans","w",stdout);
    
    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        // Read input.
        PAV = VAV = Point3D();
        scanf("%d", &N);
        FOR(i,0,N) {
            int X, Y, Z;
            scanf("%d%d%d", &X, &Y, &Z); PAV.x += X; PAV.y += Y; PAV.z += Z;
            scanf("%d%d%d", &X, &Y, &Z); VAV.x += X; VAV.y += Y; VAV.z += Z;
        }
        PAV.x /= N; PAV.y /= N; PAV.z /= N;
        VAV.x /= N; VAV.y /= N; VAV.z /= N;
                
        // Compute minimal distance between origin and line 3D.
        Line3D L(PAV, VAV, true);
        double t = L.closest_time(Point3D());
        double d = (cmp(t) < 0) ? (t = 0, dist(PAV)) : L.closest_dist(Point3D());
        
        // Prints result.
        printf("Case #%d: %.8lf %.8lf\n", tc, d, t);
    }

	return 0;
}
