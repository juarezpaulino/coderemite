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

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


int main() {

    int a, b, v, A, T;
    while (scanf("%d %d %d %d %d", &a, &b, &v, &A, &T) && (a|b|v|A|T)) {
        double D = v * (double) T;
        double X = D * cos(M_PI*A / 180.);
        double Y = D * sin(M_PI*A / 180.);
        int retH = X / a / 2. + .5 + 1E-10;
        int retV = Y / b / 2. + .5 + 1E-10;
        printf("%d %d\n", retH, retV);
    }

    return 0;
}
