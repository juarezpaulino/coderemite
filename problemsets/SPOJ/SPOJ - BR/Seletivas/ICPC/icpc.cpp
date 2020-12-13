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
#include <vector>


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
const double EPS = 1e-17;

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


typedef pair<point, double> circle;

double dist(point p) { return hypot(p.x, p.y); }

////////////////////////////////////////////////////////////////////////////////
// Verifica se o ponto P está no círculo C.
//
bool in_circle(circle C, point p){
    return cmp(dist(p - C.first), C.second) <= 0;
}

////////////////////////////////////////////////////////////////////////////////
// Centro do circulo que escreve um triangulo.
//
point circumcenter(point p, point q, point r) {
    point a = p - r, b = q - r, c = point(a * (p + r) / 2., b * (q + r) / 2.);
    return point(c % point(a.y, b.y), point(a.x, b.x) % c) / (a % b);
}

////////////////////////////////////////////////////////////////////////////////
// Encontra o menor círculo que contém todos os pontos dados.
//
circle spanning_circle(vector<point>& T) {
    int n = T.size();
    random_shuffle(all(T));
    circle C(point(), -INFINITY);
    for (int i = 0; i < n; i++) if (!in_circle(C, T[i])) {
        C = circle(T[i], 0.);
        for (int j = 0; j < i; j++) if (!in_circle(C, T[j])) {
            C = circle((T[i] + T[j]) / 2., dist(T[i] - T[j]) / 2.);
            for (int k = 0; k < j; k++) if (!in_circle(C, T[k])) {
                point o = circumcenter(T[i], T[j], T[k]);
                C = circle(o, dist(o - T[k]));
            }
        }
    }
    return C;
}


int main() {
    
    int n, k = 1;
    vector<point> T;
    double x, y;
    
    while (scanf("%d", &n)) {
        if (!n) break;   
        
        T.resize(n);
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &x, &y);
            T[i] = point(x, y);
        }
        
        circle c = spanning_circle(T);
        
        printf("Instancia %d\n", k++);
        printf("%.2lf %.2lf %.2lf\n\n", c.first.x, c.first.y, c.second);
    }
    
    return 0;
}
