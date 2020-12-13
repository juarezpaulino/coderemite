/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

double P, I;
int C;

int main() {

    int id = 1;
    while (1) {
        scanf("%lf %lf %d", &P, &I, &C);
        if (!cmp(P) && !cmp(I) && !C) break;
        double M = P;
        for (int i = 0; i < C; i++) {
            int UP = (int)(M*(1+I/C/100) + EPS);
            int DOWN = (int)(M*(1+I/C/100)*100 + EPS) % 100;
            M = UP + DOWN / 100.;
        }
        printf("Case %d. $%.2lf at %.2lf%% APR compounded %d times yields $%.2lf\n", id, P, I, C, M);
        id++;
    }

    return 0;
}
