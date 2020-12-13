/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

const double EPS = 1E-9;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
#define SQR(x) ((x)*(x))

double V, H;

double FT(double t) {
    double delta = SQR(V)*SQR(sin(t)) + 19.6*H;
    double x = V*cos(t) * (V*sin(t) + sqrt(delta)) / 9.8;
    return x;
}

int main() {

    while (1) {
        scanf("%lf %lf", &V, &H);
        if (V == -1 && H == -1) break;

        double lo = 0, hi = M_PI/2, flo, fhi;
        for (int it = 0; it < 1000; it++) {
            if (cmp(lo,hi)==0) break;
            double lo2 = (2*lo + hi) / 3, hi2 = (lo + 2*hi) / 3;
            flo = FT(lo2); fhi = FT(hi2);
            //(flo > fhi) ? lo = lo2 : hi = hi2;  // Minimiza FT.
            (flo < fhi) ? lo = lo2 : hi = hi2;  // Maximiza FT.
        }

        printf("%.6lf\n", flo);
    }

    return 0;
}
