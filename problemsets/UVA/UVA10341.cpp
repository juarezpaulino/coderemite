/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>

using namespace std;

const double EPS = 1E-14;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int p, q, r, s, t, u;

double F(double m) {
    return p/exp(m) + q*sin(m) + r*cos(m) + s*tan(m) + t*m*m + u;
}

int main() {

    while (scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF) {
        double lo = 0, hi = 1, m;
        bool noSolution = 0;
        for (int it = 0; it < 100 && !noSolution; it++) {
            m = (lo + hi) / 2;
            double flo = F(lo), fhi = F(hi), fm = F(m);
            if (cmp(fm)==0) break;
            if ((cmp(flo) <= 0 && cmp(fm) > 0) || (cmp(flo) >= 0 && cmp(fm) < 0)) hi = m;
            else if ((cmp(fhi) <= 0 && cmp(fm) > 0) || (cmp(fhi) >= 0 && cmp(fm) < 0)) lo = m;
            else noSolution = 1;
        }
        if (noSolution) puts("No solution");
        else printf("%.4lf\n", m);
    }

    return 0;
}
