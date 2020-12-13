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

///////////////////////////////////////////////////////////////////////////////
// Return -1,0,1 for not intersect, equal or intersection on "i".
//
int line_intersect(point p, point q, point r, point s, point &i) {
    point a = q - p, b = s - r, c = point(p % q, r % s), d = r-p;
    if (cmp(a%b,0)==0) return cmp(d%a)==0 ? 0 : -1;
    i = point(point(a.x, b.x) % c, point(a.y, b.y) % c) / (a % b);
    return 1;
}

point A, B, C, D;

int main() {

    int N;
    scanf("%d", &N);
    printf("INTERSECTING LINES OUTPUT\n");
    while (N--) {
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y, &D.x, &D.y);
        point I;
        int ret = line_intersect(A,B,C,D,I);
        if (ret == -1) puts("NONE");
        else if (ret == 0) puts("LINE");
        else printf("POINT %.2lf %.2lf\n", I.x, I.y);
    }
    printf("END OF OUTPUT\n");

    return 0;
}
