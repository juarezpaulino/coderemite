/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

const double EPS = 1E-10;

int main() {

    int N;
    double A, R, r, A1, A2;

    int id = 1;
    while (scanf("%d %lf", &N, &A) != EOF) {
        if (N < 3) break;
        R = sqrt(2.*A / (N * sin(2.*M_PI/N)) );
        r = sqrt(A / (N * tan(M_PI / N)) );
        A1 = M_PI*R*R - A;
        A2 = A - M_PI*r*r;
        printf("Case %d: %.5lf %.5lf\n", id++, A1+EPS, A2+EPS);
    }

    return 0;
}
