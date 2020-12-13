/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>

using namespace std;

int L, f;

const double EPS = 1E-15;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

double FT(double v) {
    double d = v*v / (2.*f);
    double S = v * 3600.;
    return S / (L + d);
}

int main() {

    while (scanf("%d%d", &L, &f)) {
        if (!(L|f)) break;
        double lo = 1E-10, hi = 1E6, flo, fhi;
        for (int it = 0; it < 100; it++) {
            if (cmp(lo,hi)==0) break;
            double lo2 = (2.*lo + hi) / 3., hi2 = (lo + 2.*hi) / 3.;
            flo = FT(lo2); fhi = FT(hi2);
            (cmp(flo,fhi) < 0 ? lo = lo2 : cmp(flo,fhi) > 0 ? hi = hi2 : (lo < hi) ? lo = lo2 : hi = hi2);  // Maximiza FT.
        }
        printf("%.8lf %.8lf\n", lo, flo);
    }

    return 0;
}
