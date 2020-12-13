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


template<class P> double dist(P A, P B = P()) { return sqrt((A-B)*(A-B)); }

point circumcenter(point p, point q, point r) {
    point a = p - r, b = q - r, c = point(a * (p + r) / 2, b * (q + r) / 2);
    return point(c % point(a.y, b.y), point(a.x, b.x) % c) / (a % b);
}


point p1, p2, p3;
point pc;
double r;

int main() {

    while (scanf("%lf %lf %lf %lf %lf %lf", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y) != EOF) {
        point pc = circumcenter(p1, p2, p3);
        r = dist(pc, p1);
        double c = -2*pc.x,
               d = -2*pc.y,
               e = pc.x*pc.x + pc.y*pc.y - r*r;

        if (pc.x < 0 && pc.y < 0) printf("(x + %.3lf)^2 + (y + %.3lf)^2 = %.3lf^2\n", fabs(pc.x), fabs(pc.y), r);
        if (pc.x < 0 && pc.y > 0) printf("(x + %.3lf)^2 + (y - %.3lf)^2 = %.3lf^2\n", fabs(pc.x), fabs(pc.y), r);
        if (pc.x > 0 && pc.y < 0) printf("(x - %.3lf)^2 + (y + %.3lf)^2 = %.3lf^2\n", fabs(pc.x), fabs(pc.y), r);
        if (pc.x > 0 && pc.y > 0) printf("(x - %.3lf)^2 + (y - %.3lf)^2 = %.3lf^2\n", fabs(pc.x), fabs(pc.y), r);

        if (c < 0 && d < 0 && e < 0) printf("x^2 + y^2 - %.3lfx - %.3lfy - %.3lf = 0\n", fabs(c), fabs(d), fabs(e));
        if (c < 0 && d < 0 && e > 0) printf("x^2 + y^2 - %.3lfx - %.3lfy + %.3lf = 0\n", fabs(c), fabs(d), fabs(e));
        if (c < 0 && d > 0 && e < 0) printf("x^2 + y^2 - %.3lfx + %.3lfy - %.3lf = 0\n", fabs(c), fabs(d), fabs(e));
        if (c < 0 && d > 0 && e > 0) printf("x^2 + y^2 - %.3lfx + %.3lfy + %.3lf = 0\n", fabs(c), fabs(d), fabs(e));
        if (c > 0 && d < 0 && e < 0) printf("x^2 + y^2 + %.3lfx - %.3lfy - %.3lf = 0\n", fabs(c), fabs(d), fabs(e));
        if (c > 0 && d < 0 && e > 0) printf("x^2 + y^2 + %.3lfx - %.3lfy + %.3lf = 0\n", fabs(c), fabs(d), fabs(e));
        if (c > 0 && d > 0 && e < 0) printf("x^2 + y^2 + %.3lfx + %.3lfy - %.3lf = 0\n", fabs(c), fabs(d), fabs(e));
        if (c > 0 && d > 0 && e > 0) printf("x^2 + y^2 + %.3lfx + %.3lfy + %.3lf = 0\n", fabs(c), fabs(d), fabs(e));

        putchar('\n');
    }

    return 0;
}
