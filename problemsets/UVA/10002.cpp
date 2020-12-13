/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const double EPS = 1E-14;

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

typedef vector<point> poly;

inline int ccw(point p, point q, point r) {
    return cmp((p - r) % (q - r));
}

bool radial_lt(point p, point q) {
    point P = p - point::pivot, Q = q - point::pivot; double R = P % Q;
    return (cmp(R)) ? R > 0 : cmp(P * P, Q * Q) > 0;
}

double poly_area(poly& T) {
    double d = 0.; int j, n = T.size();
    for (int i = 0; i < n; i++) j = (i+1)%n, d+=T[i]%T[j];
    return d/2.;
}

void center_mass(poly &T, double &cx, double &cy) {
    double a = poly_area(T), d;
    int j, n = T.size();
    cx = cy = 0;
    for (int i = 0; i < n; i++)
        j = (i+1)%n, d = T[i]%T[j],
        cx += (T[i].x+T[j].x)*d,
        cy += (T[i].y+T[j].y)*d;
    cx/=(6.*a), cy/=(6.*a);
}


int main() {

    int N;
    while (scanf("%d", &N)) {
        if (N < 3) break;
        poly P(N);
        double minx = 0, miny = 0;
        for (int i = 0; i < N; i++) {
            scanf("%lf %lf", &P[i].x, &P[i].y);
            minx = min(minx, P[i].x);
            miny = min(miny, P[i].y);
        }
        point::pivot = *min_element(P.begin(), P.end());
        sort(P.begin(), P.end(), radial_lt);
        double cx, cy;
        center_mass(P, cx, cy);
        printf("%.3lf %.3lf\n", cx+EPS, cy+EPS);
    }

    return 0;
}
