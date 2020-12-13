/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>


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
        if (int t = ::cmp(y, q.y)) return t;
        return ::cmp(x, q.x);
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
    return (cmp(R)) ? R > 0 : cmp(P * P, Q * Q) < 0;
}

poly convex_hull(vector<point>& T) {
    int j = 0, k, n = T.size(); poly U(n);
    point::pivot = *min_element(T.begin(), T.end());
    sort(T.begin(), T.end(), radial_lt);
    for (k = n-2; k >= 0 && ccw(T[0], T[n-1], T[k]) == 0; k--);
    reverse((k+1) + T.begin(), T.end());
    for (int i = 0; i < n; i++) {
        while (j > 1 && ccw(U[j-1], U[j-2], T[i]) >= 0) j--;
        U[j++] = T[i];
    }
    U.erase(j + U.begin(), U.end());
    return U;
}


int main() {

    int T, N;
    scanf("%d", &T);
    printf("%d\n", T);
    while (T--) {
        scanf("%d", &N);
        vector<point> P(N);
        for (int i = 0; i < N; i++) scanf("%lf %lf", &P[i].x, &P[i].y);
        poly C = convex_hull(P);
        N = C.size();
        printf("%d\n", N+1);
        for (int i = 0; i < N; i++) printf("%.0lf %.0lf\n", C[i].x, C[i].y);
        printf("%.0lf %.0lf\n", C[0].x, C[0].y);

        if (T) printf("-1\n");
        scanf("%d", &N);
    }

    return 0;
}
