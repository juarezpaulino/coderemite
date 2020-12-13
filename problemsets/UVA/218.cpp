/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// Estruturas
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

typedef vector<point> poly;

template<class P> double dist(P A, P B = P()) { return sqrt((A-B)*(A-B)); }

inline int ccw(point p, point q, point r) {
    return cmp((p - r) % (q - r));
}

bool radial_lt(point p, point q) {
    point P = p - point::pivot, Q = q - point::pivot; double R = P % Q;
    return (cmp(R)) ? R > 0 : cmp(P * P, Q * Q) < 0;
}

poly convex_hull(vector<point>& T) {
    int i, j = 0, k, n = T.size(); poly U(n);
    point::pivot = *min_element(T.begin(), T.end());
    sort(T.begin(), T.end(), radial_lt);
    for (k = n-2; k >= 0 && ccw(T[0], T[n-1], T[k]) == 0; k--);
    reverse((k+1) + T.begin(), T.end());
    for (int i = 0; i < n; i++) {
    // troque o >= por > para manter pontos colineares
        while (j > 1 && ccw(U[j-1], U[j-2], T[i]) >= 0) j--;
        U[j++] = T[i];
    }
    U.erase(j + U.begin(), U.end());
    return U;
}


int main() {

    vector<point> P;

    int t = 1;
    int N;
    while (scanf("%d", &N)) {
        if (!N) break;
        double x, y;
        P.clear();
        for (int i = 0; i < N; i++) {
            scanf("%lf %lf", &x, &y);
            P.push_back(point(x,y));
        }
        poly T = convex_hull(P);
        if (t != 1) putchar('\n');
        printf("Region #%d:\n", t++);
        printf("(%.1lf,%.1lf)", T[0].x, T[0].y);
        int M = T.size();
        double ret = 0.;
        for (int i = M-1; i >= 0; i--) {
            ret += dist(T[i],T[(i+1)%M]);
            printf("-(%.1lf,%.1lf)", T[i].x, T[i].y);
        }
        printf("\nPerimeter length = %.2lf\n", ret);
    }


    return 0;
}
