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

////////////////////////////////////////////////////////////////////////////////
// Geometria ///////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#include <vector>

struct point {
    double x, y, z;
    point(double x = 0, double y = 0, double z = 0): x(x), y(y), z(z) {}
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

////////////////////////////////////////////////////////////////////////////////
// Comparação radial.
//
bool radial_lt(point p, point q) {
    point P = p - point::pivot, Q = q - point::pivot;
    double R = P % Q;
    if (cmp(R)) return R > 0;
    return cmp(P * P, Q * Q) < 0;
}

////////////////////////////////////////////////////////////////////////////////
// Retorna <0, 0, >0 para cw, colinear, ccw
//
_inline(int ccw)(point p, point q, point r) {
    return cmp((p - r) % (q - r));
}

bool ord(point p, point q) {
    int dx = cmp(p.x, q.x), dy = cmp(p.y, q.y);
    if (dx < 0) return true; else if (dx > 0) return false;
    else if (dy < 0) return true; else return false;
}


int main() {

    int n, x, y, z;
    double m;
    int i, c = 1;
    vector<point> T, S;
    
    point::pivot = point(0,0,INF);
    
    while (scanf("%d", &n)) {
        if (!n) break; T.resize(n);
        for (i = 0; i < n; i++) { 
            scanf("%d %d %d", &x, &y, &z); T[i] = point(x,y,z);
        }
        sort(all(T), radial_lt);
        S.clear(); m = T[0].z;
        for (i = 0; i < n-1; i++)
            if (!ccw(point::pivot, T[i], T[i+1])) {
                if (cmp(T[i+1].z, m) <= 0) S.push_back(T[i+1]);
                else m = T[i+1].z;
            }
            else m = T[i+1].z;
        printf("Data set %d:\n", c++);
        if (!S.size()) { puts("All the lights are visible."); continue; }
        sort(all(S), ord);
        puts("Some lights are not visible:");
        for (i = 0; i < S.size()-1; i++)
            printf("x = %.0lf, y = %.0lf;\n", S[i].x, S[i].y);
        printf("x = %.0lf, y = %.0lf.\n", S[i].x, S[i].y);
    }
    
    return 0;
}
