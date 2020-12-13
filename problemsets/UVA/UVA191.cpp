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


bool seg_intersect(point p, point q, point r, point s) {
    point A = q - p, B = s - r, C = r - p, D = s - q;
    int a = cmp(A % C) + 2 * cmp(A % D);
    int b = cmp(B % C) + 2 * cmp(B % D);
    if (a == 3 || a == -3 || b == 3 || b == -3) return false;
    if (a || b || p == r || p == s || q == r || q == s) return true;
    int t = (p < r) + (p < s) + (q < r) + (q < s);
    return t != 0 && t != 4;
}

point S, T, P1, P2;

int main() {

    int N;
    scanf("%d", &N);
    while (N--) {
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &S.x, &S.y, &T.x, &T.y, &P1.x, &P2.y, &P2.x, &P1.y);
        if (P1.x > P2.x) swap(P1.x, P2.x);
        if (P1.y > P2.y) swap(P1.y, P2.y);
        if (seg_intersect(S, T, P1, point(P2.x, P1.y)) ||
            seg_intersect(S, T, P1, point(P1.x, P2.y)) ||
            seg_intersect(S, T, P2, point(P2.x, P1.y)) ||
            seg_intersect(S, T, P2, point(P1.x, P2.y)) ||
            (cmp(P1.x, S.x)<=0 && cmp(S.x, P2.x)<=0 && cmp(P1.y, S.y)<=0 && cmp(S.y, P2.y)<=0))
            puts("T");
        else puts("F");
    }

    return 0;
}
