/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int M;
double X1[10], Y1[10], X2[10], Y2[10];
double x, y;

inline int cmp(double A, double B = 0., double d = 1E-10) {
    return (A < B+d) ? (B < A+d) ? 0 : -1 : 1;
}

int main() {

    M = 0;
    char c;
    while ((c = getchar()) != '*') {
        scanf("%lf %lf %lf %lf ", X1+M, Y1+M, X2+M, Y2+M);
        M++;
    }
    int k = 1;
    while (scanf("%lf %lf ", &x, &y)) {
        if (!cmp(x,9999.9) && !cmp(y,9999.9)) break;
        bool ok = false;
        for (int i = 0; i < M; i++) {
            if (cmp(x,X1[i])>0 && cmp(y,Y2[i])>0 && cmp(x,X2[i])<0 && cmp(y,Y1[i])<0) {
                printf("Point %d is contained in figure %d\n", k, i+1);
                ok = true;
            }
        }
        if (!ok) printf("Point %d is not contained in any figure\n", k);
        k++;
    }

    return 0;
}
