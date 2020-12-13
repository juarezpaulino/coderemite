/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

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

typedef vector<point> poly;

inline int ccw(point p, point q, point r) {
    return cmp((p - r) % (q - r));
}

inline double angle(point p, point q, point r) {
    point u = p - q, v = r - q; return atan2(u % v, u * v);
}

/*******************************************************************************
 * Decide se q está sobre o segmento fechado pr. Dep: ccw.
 */
bool between(point p, point q, point r) {
    return ccw(p, q, r)==0 && cmp((p - q)*(r - q)) <= 0;
}

int in_poly(point p, poly& T) {
    double a = 0; int N = T.size();
    for (int i = 0; i < N; i++) {
        if (between(T[i], p, T[(i+1) % N])) return -1;
        a += angle(T[i], p, T[(i+1) % N]);
    }
    return cmp(a) != 0;
}

int main() {

    int N;
    while (scanf("%d", &N) != EOF) {
        if (!N) break;
        poly P(N);
        for (int i = 0; i < N; i++) scanf("%lf %lf", &P[i].x, &P[i].y);
        point p;
        scanf("%lf %lf", &p.x, &p.y);
        if (in_poly(p, P)) puts("T");
        else puts("F");
    }

    return 0;
}
