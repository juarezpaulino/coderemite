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

inline double angle(point p, point q, point r) {
    point u = p - q, v = r - q; return atan2(u % v, u * v);
}

typedef pair<point, double> circle;


////////////////////////////////////////////////////////////////////////////////
// Encontra os pontos secantes a dois círculos C1 e C2.
////////////////////////////////////////////////////////////////////////////////
/*vector<point> intersect_circle_circle(circle &c1, circle &c2) {
    vector<point> ret;
    point m1 = c1.first, m2 = c2.first;
    double r1 = c1.second, r2 = c2.second;
    double dx = m2.x - m1.x, dy = m2.y - m1.y;
    double d = sqrt(dx*dx + dy*dy);
    double rsum = r1 + r2, rdiff = fabs(r1 - r2);
    if (d > rsum || d < rdiff || (d < EPS && rdiff < EPS)) return ret;
    double x = (d*d + r1*r1 - r2*r2) / (2*d);
    if (cmp(d,rsum) <= 0 || cmp(d,rdiff) <= 0) {
        ret.push_back(point(m1.x + (x*dx)/d, m1.y + (x*dy)/d));
    } else {
        double y = sqrt(fabs(r1*r1 - x*x));
        ret.push_back(point(m1.x + (x*dx - y*dy) / d, m1.y + (x*dy + y*dx) / d));
        ret.push_back(point(m1.x + (x*dx + y*dy) / d, m1.y + (x*dy - y*dx) / d));
    }
    return ret;
}*/

vector<point> intersect_circle_circle(const circle &A,const circle &B)
{
    vector<point> RET;
	double X1=A.FI.x,Y1=A.FI.y,X2=B.FI.x,Y2=B.FI.y;
	double R1=A.SE,R2=B.SE;
	double dst=dist(A.FI,B.FI);
	if (dst>R1+R2+EPS || dst<fabs(R1-R2)-EPS) return RET;
	double a=X1-X2;
	double b=Y1-Y2;
	double c=-(a*(X1+X2)+b*(Y1+Y2)-SQR(R1)+SQR(R2))/2.0;
	double CX=X1,CY=Y1;
	double x1,y1,x2,y2;
	if (fabs(a)>fabs(b))
	{
		double A=SQR(a)+SQR(b);
		double B=2.0*b*(c+a*CX)-2.0*SQR(a)*CY;
		double C=SQR(c+a*CX)+SQR(a)*(SQR(CY)-SQR(R1));
		double delta=SQR(B)-4*A*C;
		if (delta<-EPS) return RET;
		if (delta<0) delta=0;
		delta=sqrt(delta);
		y1=(-B+delta)/(2*A);x1=(-c-b*y1)/a;
		y2=(-B-delta)/(2*A);x2=(-c-b*y2)/a;
		RET.PB(point(x1,y1));
		RET.PB(point(x2,y2));
	}
	else
	{
		swap(a,b);swap(CX,CY);
		double A=SQR(a)+SQR(b);
		double B=2.0*b*(c+a*CX)-2.0*SQR(a)*CY;
		double C=SQR(c+a*CX)+SQR(a)*(SQR(CY)-SQR(R1));
		double delta=SQR(B)-4*A*C;
		if (delta<-EPS) return RET;
		if (delta<0) delta=0;
		delta=sqrt(delta);
		y1=(-B+delta)/(2*A);x1=(-c-b*y1)/a;
		y2=(-B-delta)/(2*A);x2=(-c-b*y2)/a;
		swap(x1,y1);swap(x2,y2);
		swap(a,b);swap(CX,CY);
		RET.PB(point(x1,y1));
		RET.PB(point(x2,y2));
	}
	return RET;
}


bool in_circle(circle C, circle c) {
    return cmp(dist(C.first, c.first)+c.second, C.second) <= 0;
}

inline double circle_segment(double rad, double th) {
    return rad*rad*(th - sin(th))/2;
}


const int MAXP = 5000;
const int MAXQ = 1000;

int N, M;
point P[MAXP], Q[MAXQ];
double A[MAXQ];
circle C[MAXP];



int main() {

	freopen("D.in","r",stdin);
//  freopen("D-small-practice.in","r",stdin);freopen("D-small-practice.out","w",stdout);
//	freopen("D-large-practice.in","r",stdin);freopen("D-large-practice.out","w",stdout);
//	freopen("D-small-attempt0.in","r",stdin);freopen("D-small-attempt0.out","w",stdout);
//	freopen("D-small-attempt1.in","r",stdin);freopen("D-small-attempt1.out","w",stdout);
//	freopen("D-small-attempt2.in","r",stdin);freopen("D-small-attempt2.out","w",stdout);
//	freopen("D-large.in","r",stdin);freopen("D-large.ans","w",stdout);

    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        // Read input.
        scanf("%d %d", &N, &M);
        FOR(i,0,N) {
            int x, y; scanf("%d%d", &x, &y);
            P[i] = point(x,y);
        }
        FOR(i,0,M) {
            int x, y; scanf("%d%d", &x, &y);
            Q[i] = point(x,y);
        }

        FOR(k,0,M) A[k] = 0;
        FOR(k,0,M) {
            FOR(i,0,N) C[i] = circle(P[i], dist(P[i],Q[k]));
            FOR(i,0,N) FOR(j,i+1,N) {
                if (in_circle(C[i], C[j])) {
                    A[k] += PI*C[i].SE*C[i].SE;
                    continue;
                }
                if (in_circle(C[j], C[i])) {
                    A[k] += PI*C[j].SE*C[j].SE;
                    continue;
                }

                vector<point> SEC = intersect_circle_circle(C[i], C[j]);

                if (SEC[0]==SEC[1]) continue;

                A[k] += circle_segment(C[i].SE, fabs(angle(SEC[0], C[i].FI, SEC[1])));
                printf("%.6lf\n", fabs(angle(SEC[0], C[i].FI, SEC[1])));
                A[k] += circle_segment(C[j].SE, fabs(angle(SEC[0], C[j].FI, SEC[1])));
                printf("%.6lf\n",fabs(angle(SEC[0], C[j].FI, SEC[1])));
            }
        }

        // Prints result.
        printf("Case #%d:", tc);
        FOR(i,0,M) printf(" %.8lf", A[i]);
        putchar('\n');
    }

	return 0;
}
