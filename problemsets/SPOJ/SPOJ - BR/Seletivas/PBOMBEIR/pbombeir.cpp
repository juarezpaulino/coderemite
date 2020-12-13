/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <inttypes.h>
#include <ctype.h>
#include <algorithm>
#include <utility>
#include <iostream>


using namespace std;

#define TRACE(x...)
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x" = " << x << "\n")
#define _inline(f...) f() __attribute__((always_inline)); f
#define _foreach(it, b, e) for (typeof(b) it = (b); it != (e); it++)
#define foreach(x...) _foreach(x)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

const int INF = 0x3F3F3F3F;
const int NULO = -1;
const double EPS = 1e-13;

_inline(int cmp)(double x, double y = 0, double tol = EPS) {
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

_inline(int ccw)(point p, point q, point r) {
    return cmp((p - r) % (q - r));
}

point circumcenter(point p, point q, point r) {
    point a = p - r, b = q - r, c = point(a * (p + r) / 2, b * (q + r) / 2);
    return point(c % point(a.y, b.y), point(a.x, b.x) % c) / (a % b);
}


int main() {
 
    int n; double a, b, c, d, e, f;
    point p, q, r, z;
    
    scanf("%d", &n);
    while (n--) {
        scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &d, &e, &f);
        p = point(a, b); q = point(c, d); r = point(e, f);
        if (p==q || p==r || q==r) { 
            puts("There is an infinity of possible locations."); continue; 
        }
        if (!ccw(p, q, r)) {
            puts("There is no possible location."); continue;
        }
        z = circumcenter(p, q, r);
        printf("The equidistant location is (%.7lf, %.7lf).\n", z.x, z.y);
    }
    return 0;
}
