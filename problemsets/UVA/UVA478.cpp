/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>

using namespace std;

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


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

struct line {
    double a, b, c;
    line(double a = 0, double b = 0, double c = 0): a(a), b(b), c(c) {}
    line(point p, point q) {
        if (cmp(p.x, q.x) == 0) { a = 1; b = 0; c = -p.x; }
        else { b = 1; a = -(p.y-q.y)/(p.x-q.x); c = -(a*p.x)-(b*p.y); }
    }
    line(point p, double m) { a = -m; b = 1; c = -((a*p.x)+(b*p.y)); }
    bool operator ||(line s) const { return (cmp(a, s.a) == 0) && (cmp(b, s.b) == 0); }
    bool operator ==(line s) const { return (*this || s) && (cmp(c, s.c) == 0); }
};

typedef pair<point, double> circle;

template<class P> double dist(P A, P B = P()) { return sqrt((A-B)*(A-B)); }

inline double signed_area(point p, point q, point r) {
    return ((p - r) % (q - r)) / 2.0;
}

char T[100];
point P[30][3];
double R[30];

int main() {

    char c;
    int N = 0;
    while ((c = getchar()) != '*') {
        if (c=='r') scanf("%lf %lf %lf %lf ", &P[N][0].x, &P[N][1].y, &P[N][1].x, &P[N][0].y);
        else if (c=='c') scanf("%lf %lf %lf ", &P[N][0].x, &P[N][0].y, &R[N]);
        else scanf("%lf %lf %lf %lf %lf %lf ", &P[N][0].x, &P[N][0].y, &P[N][1].x, &P[N][1].y, &P[N][2].x, &P[N][2].y);
        T[N] = c;
        N++;
    }

    point p;
    int k = 1;
    while (scanf("%lf %lf", &p.x, &p.y)) {
        if (!cmp(p.x,9999.9) && !cmp(p.y,9999.9)) break;
        bool f = false;
        for (int i = 0; i < N; i++) {
            if ((T[i]=='r' && cmp(p.x,P[i][0].x)>0 && cmp(p.x,P[i][1].x)<0 && cmp(p.y,P[i][0].y)>0 && cmp(p.y,P[i][1].y)<0) ||
                (T[i]=='c' && cmp(dist(p,P[i][0]),R[i])<0) ||
                (T[i]=='t' && cmp(fabs(signed_area(P[i][0],P[i][1],p))+fabs(signed_area(P[i][1],P[i][2],p))+fabs(signed_area(P[i][2],P[i][0],p)),fabs(signed_area(P[i][0],P[i][1],P[i][2])))==0))
                printf("Point %d is contained in figure %d\n", k, i+1), f = true;
        }
        if (!f) printf("Point %d is not contained in any figure\n", k);
        k++;
    }

    return 0;
}
