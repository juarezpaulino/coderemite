/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const double EPS = 1E-14;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

double x, y, c;

double F(double d) {
    return 1.-c/sqrt(x*x-d*d)-c/sqrt(y*y-d*d);
}


int main() {

    while (scanf("%lf %lf %lf", &x, &y, &c) != EOF) {
        double lo = 0, hi = min(x,y), m;
        for (int it = 0; it < 1000; it++) {
            if (cmp(hi,lo)==0) break;
            double m = (hi+lo)/2.;
            if (cmp(F(m)) > 0) lo = m; else hi = m;
        }
        printf("%.3lf\n", (hi+lo)/2.);
    }

    return 0;
}
