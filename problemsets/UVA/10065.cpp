/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>


using namespace std;


const double EPS = 1E-14;


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

////////////////////////////////////////////////////////////////////////////////

template<class P> double dist(P A, P B = P()) { return sqrt((A-B)*(A-B)); }
template<class P> double sqrdist(P A, P B = P()) { return (A-B)*(A-B); }
template<class P> double arg(P p) { return atan2(p.y, p.x); }


/*******************************************************************************
 * Retorna <0, 0, >0 para cw, colinear, ccw
 */
inline int ccw(point p, point q, point r) {
    return cmp((p - r) % (q - r));
}

/*******************************************************************************
 * Comparação radial.
 */
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

/*******************************************************************************
 * poly_area: Calcula a area de um poligono T dado pelos seus pontos. Dep: point, poly. O(n)
 */
double poly_area(poly& T) {
    double d = 0.; int j, n = T.size();
    for (int i = 0; i < n; i++) j = (i+1)%n, d+=T[i]%T[j];
    return fabs(d/2.);
}


int main() {

    int N, x, y, T = 1;
    while (scanf("%d", &N)) {
        if (!N) break;
        poly P(N);
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &x, &y);
            P[i].x = x; P[i].y = y;
        }
        double a1 = poly_area(P);
        poly C = convex_hull(P);
        double a2 = poly_area(C);
        printf("Tile #%d\nWasted Space = %.2lf %%\n\n", T++, 100. - a1 * 100. / a2);
    }

    return 0;
}
