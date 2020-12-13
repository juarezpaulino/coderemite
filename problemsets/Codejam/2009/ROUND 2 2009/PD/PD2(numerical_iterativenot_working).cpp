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

double spanning_maximum_radius(vector<circle> &T, double x, double y) {
    double ret = -1;
    int N = SI(T);
    FOR(i,0,N) ret = max(ret, dist(T[i].first,point(x,y))+T[i].second);
    return ret;
}

circle spanning_circle(vector<circle>& T) {
    int N = SI(T);
    // First estimation.
    double sx = 0, sy = 0, t = 0, k;
    FOR(i,0,N) k = T[i].second, sx += T[i].first.x*k, sy += T[i].first.y*k, t += k;
    sx /= t; sy /= t;
    double STEP = 1;
    double best = spanning_maximum_radius(T,sx,sy);
    while (STEP > 1E-6) {
        bool found = false;
        double r;
        // Try potential directions.
        if (cmp((r = spanning_maximum_radius(T, sx+STEP, sy)), best) < 0) best = r, sx = sx+STEP, found = true;
        else if (cmp((r = spanning_maximum_radius(T, sx, sy+STEP)), best) < 0) best = r, sy = sy+STEP, found = true;
        else if (cmp((r = spanning_maximum_radius(T, sx-STEP, sy)), best) < 0) best = r, sx = sx-STEP, found = true;
        else if (cmp((r = spanning_maximum_radius(T, sx, sy-STEP)), best) < 0) best = r, sy = sy-STEP, found = true;
        // Try perpendicular line directions.
        else FOR(i,0,N) {
            double dx = T[i].first.x-sx, dy = T[i].first.y-sy, len = sqrt(dx*dx + dy*dy);
            if (cmp(len)) {
                double dx2 = dy/len, dy2 = -dx/len;
                if (cmp((r = spanning_maximum_radius(T, sx+dx2*STEP, sy+dy2*STEP)), best) < 0) {
                    best = r, sx = sx+dx2*STEP, sy = sy+dy2*STEP, found = true; break;
                }
                if (cmp((r = spanning_maximum_radius(T, sx-dx2*STEP, sy-dy2*STEP)), best) < 0) {
                    best = r, sx = sx-dx2*STEP, sy = sy-dy2*STEP, found = true; break;
                }
            }
        }
        if (!found) STEP /= 2;
    }
    return circle(point(sx,sy),best);
}


int N;
vector<circle> V;


int main() {
    
//	freopen("D.in","r",stdin);
	freopen("D-small-practice.in","r",stdin);//freopen("D-small-practice.out","w",stdout);
//	freopen("D-large-practice.in","r",stdin);freopen("D-large-practice.out","w",stdout);
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

        double m, t, dt = PI/6, ret = DINF;
        for (t = 0; t < 2*PI+EPS; t+=dt) { m = tan(t); FOR(i,0,N) {
            vector<circle> S1, S2;
            if (!cmp(t,PI/2)) FOR(j,0,N) (cmp(V[j].first.x,V[i].first.x)<=0) ? S1.PB(V[j]) : S2.PB(V[j]);
            else FOR(j,0,N) (cmp(V[j].first.y, m*(V[j].first.x-V[i].first.x)+V[i].first.y) <= 0) ? S1.PB(V[j]) : S2.PB(V[j]);
            
            double r1 = spanning_circle(S1).second, r2 = spanning_circle(S2).second;
            ret = min(ret, max(r1,r2));
        }}
        
        // Prints result.
        printf("Case #%d: %.8lf\n", tc, ret);
    }

	return 0;
}
