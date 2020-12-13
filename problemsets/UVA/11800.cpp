/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <sstream>

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

template<class P> double dist(P A, P B = P()) { return sqrt((A-B)*(A-B)); }

inline double angle(point p, point q, point r) {
    point u = p - q, v = r - q; return atan2(u % v, u * v);
}

bool radial_lt(point p, point q) {
    point P = p - point::pivot, Q = q - point::pivot; double R = P % Q;
    return (cmp(R)) ? R > 0 : cmp(P * P, Q * Q) < 0;
}


point P[5];
double a[4];
double d[4];

int main() {

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        for (int i = 0; i < 4; i++) scanf("%lf %lf", &P[i].x, &P[i].y);
        point::pivot = P[0];
        for (int i = 1; i < 4; i++) if (P[i] < point::pivot) { point::pivot = P[i]; swap(P[i],P[0]); }
        sort(P+1, P+4, radial_lt);
        for (int j = 0; j < 4; j++) {
            int i = (j+3)%4, k = (j+1)%4;
            d[j] = dist(P[j],P[k]);
            a[j] = fabs(angle(P[i], P[j], P[k]));
        }
        bool prl1 = !cmp((P[0]-P[1])%(P[2]-P[3]));
        bool prl2 = !cmp((P[1]-P[2])%(P[3]-P[0]));
        bool sqr = !cmp(d[0],d[1]) && !cmp(d[1],d[2]) && !cmp(d[2],d[3]) && !cmp(a[0],M_PI/2.) && !cmp(a[1],M_PI/2.) && !cmp(a[2],M_PI/2.) && !cmp(a[3],M_PI/2.);
        bool rct = !cmp(d[0],d[2]) && !cmp(d[1],d[3]) && !cmp(a[0],M_PI/2.) && !cmp(a[1],M_PI/2.) && !cmp(a[2],M_PI/2.) && !cmp(a[3],M_PI/2.);
        bool rho = !cmp(d[0],d[1]) && !cmp(d[1],d[2]) && !cmp(d[2],d[3]) && cmp(a[0],M_PI/2.) && cmp(a[1],M_PI/2.) && cmp(a[2],M_PI/2.) && cmp(a[3],M_PI/2.) && !cmp(a[0],a[2]) && !cmp(a[1],a[3]);
        bool plg = !cmp(d[0],d[2]) && !cmp(d[1],d[3]) && cmp(a[0],M_PI/2.) && cmp(a[1],M_PI/2.) && cmp(a[2],M_PI/2.) && cmp(a[3],M_PI/2.) && !cmp(a[0],a[2]) && !cmp(a[1],a[3]);
        bool tpz = (prl1 && !prl2) || (prl2 && !prl1);

        printf("Case %d: ", t);
        if(sqr) puts("Square");
        else if(rct) puts("Rectangle");
        else if(rho) puts("Rhombus");
        else if(plg) puts("Parallelogram");
        else if(tpz) puts("Trapezium");
        else puts("Ordinary Quadrilateral");    }

    return 0;
}
