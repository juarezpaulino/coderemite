/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

const double EPS = 1E-8;

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

typedef pair<point, double> circle;

template<class P> double dist(P A, P B = P()) { return sqrt((A-B)*(A-B)); }

vector<point> intersect_circle_circle(circle &c1, circle &c2) {
    vector<point> ret;
    point m1 = c1.first, m2 = c2.first;
    double r1 = c1.second, r2 = c2.second;
    double dx = m2.x - m1.x, dy = m2.y - m1.y;
    double d = sqrt(dx*dx + dy*dy);
    double rsum = r1 + r2, rdiff = fabs(r1 - r2);
    if (d > rsum || d < rdiff || (d < EPS && rdiff < EPS)) return ret;
    double x = (d*d + r1*r1 - r2*r2) / (2*d);
    if (cmp(d,rsum) <= 0 || cmp(d,rdiff) <= 0) {
        ret.push_back(point(m1.x + (x*dx)/d, m1.y + (x*dy)/d));
    } else {
        double y = sqrt(fabs(r1*r1 - x*x));
        ret.push_back(point(m1.x + (x*dx - y*dy) / d, m1.y + (x*dy + y*dx) / d));
        ret.push_back(point(m1.x + (x*dx + y*dy) / d, m1.y + (x*dy - y*dx) / d));
    }
    return ret;
}

bool in_circle(circle C, point p){
    return cmp(dist(p - C.first), C.second) <= 0;
}


double t1, t2;
point c, h, s;

bool check(double m) {
    double  r[] = { t2 + dist(c,h) - m,
                    t1 + dist(c,s) - m,
                    m };
    for (int i = 0; i < 3; i++)
        if (r[i] < -EPS)
            return false;
    printf("%.2lf\n", m);
    circle  C[3] = {    circle(h, r[0]),
                        circle(s, r[1]),
                        circle(c, r[2]) };
    for (int i = 0; i < 3; i++)
        if (in_circle(C[(i+1)%3], C[i].first) && in_circle(C[(i+2)%3], C[i].first))
            return true;
    int o[3] = {0, 1, 2};
    do {
        vector<point> I = intersect_circle_circle(C[o[0]],C[o[1]]);
        for (vector<point>::iterator it = I.begin(); it != I.end(); it++) {
            if (in_circle(C[o[2]], *it))
                return true;
        }
    } while (next_permutation(o, o+3));
    return false;
}


int main() {

    double a = 2.;
    scanf("%lf %lf", &t1, &t2);
    scanf("%lf %lf %lf %lf %lf %lf", &c.x, &c.y, &h.x, &h.y, &s.x, &s.y);

    if (cmp(dist(c,s) + dist(s, h), t2 + dist(c,h)) <= 0) {
        printf("%.8lf", min(t1 + dist(c,s) + dist(s, h), t2 + dist(c,h)));
        return 0;
    }

    double lo = 0., hi = 1E3+10.;
    for (int it = 0; it < 100; it++) {
        if (cmp(hi,lo)==0) break;
        double m = (hi+lo)/2.;
        if (check(m)) lo = m; else hi = m;
    }
    printf("%.8lf\n", lo);

    return 0;
}
