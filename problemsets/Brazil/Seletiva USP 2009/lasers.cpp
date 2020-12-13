/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/* Seletiva USP 2009 - Problema H - lasers.cpp 
 *
 * Tecnica: Geometria / Reta 3D / Envoltoria convexa / Area de poligono
 *
 * Entrada: Ponto de disparo e pontos a serem atingidos no espaco 3D.
 * Saida: Area da envoltoria convexa gerada pelo prolongamento a terra (z = 0)
 * do ponto de disparo pelos pontos a serem atingidos.
 *
 * Tecnica: A reta formada pela prolongacao do ponto de disparo com os pontos-
 * alvo eh formada pela equacao parametrica do vetor direcao formado na variavel
 * tempo t. Isto e, tome p1(x1, y1, z1) e p2(x2, y2, z2) dois pontos do espaco
 * 3D, o vetor direcao e formado por v = (x2-x1, y2-y1, z2-z1). Logo, temos
 *
 * x = x1 + vx*t / y = y1 + vy*t / z = z1 + vz*t
 *
 * Supondo o prolongamento ate a terra (z = 0), derivamos os pontos (x,y) quando
 * z = 0 por:
 * A = z1 / (z1-z2);
 * x(z=0) = x1 + A(x2-x1)
 * y(z=0) = y1 + A(y2-y1)
 *
 * Em seguida, resta aplicar a envoltoria convexa sobre os pontos obtidos e
 * calcular a area do poligono convexo.
 *
 */ 

#include <stdio.h>
#include <vector>
#include <algorithm>

#define _inline(f...) f() __attribute__((always_inline)); f
#define _foreach(it, b, e) for (typeof(b) it = (b); it != (e); it++)
#define foreach(x...) _foreach(x)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

using namespace std;

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
    static point pivot;
};
point point::pivot;

typedef vector<point> polygon;

/*******************************************************************************
 * Retorna <0, 0, >0 para cw, colinear, ccw
 */
int ccw(point p, point q, point r) {
    return cmp((p - r) % (q - r));
}

/*******************************************************************************
 * Comparação radial.
 */
bool radial_lt(point p, point q) {
    point P = p - point::pivot, Q = q - point::pivot;
    double R = P % Q;
    if (cmp(R)) return R > 0;
    return cmp(P * P, Q * Q) < 0;
}

/*******************************************************************************
 * Determina o fecho convexo de um conjunto de pontos no plano.
 * Destrói a lista de pontos T.
 * Dep: ccw, radial_lt.
 */
polygon convex_hull(vector<point>& T) {
    int j = 0, k, n = T.size(); polygon U(n);
    point::pivot = *min_element(all(T));
    sort(all(T), radial_lt);
    for (k = n-2; k >= 0 && ccw(T[0], T[n-1], T[k]) == 0; k--);
    reverse((k+1) + all(T));    
    for (int i = 0; i < n; i++) {
        while (j > 1 && ccw(U[j-1], U[j-2], T[i]) >= 0) j--;
        U[j++] = T[i];
    }
    U.erase(j + all(U));
    return U;
}

/*******************************************************************************
 * Calcula a área orientada em ccw do polígono T.
 */
double poly_area(polygon& T) {
    double s = 0; int n = T.size();
    for (int i = 0; i < n; i++) s += T[i] % T[(i+1) % n];
    return s / 2;
}

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return i;
}

int n;
double x1, y1, z1;

int main() {
    
    int i;
    double x2, y2, z2, A;
    vector<point> p;
    polygon poly;
    for ( ; n = get_int(), n; ) {
        x1 = get_int(), y1 = get_int(), z1 = get_int();
        p.resize(n);
        for (i = 0; i < n; i++) {
            x2 = get_int(), y2 = get_int(), z2 = get_int();
            A = z1/(z1-z2); p[i] = point(x1+A*(x2-x1), y1+A*(y2-y1));
        }
        poly = convex_hull(p);
        printf("%.2lf\n", poly_area(poly));
    }
    
    return 0;
}
