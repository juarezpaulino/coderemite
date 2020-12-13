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

const double EPS = 1E-10;

inline int cmp(double A, double B = 0., double tol = 1E-10) {
    return (A < B+tol) ? (B < A + tol) ? 0 : -1 : 1;
}

inline double dist(double x1, double y1, double x2, double y2) {
    double dx = x1-x2;
    double dy = y1-y2;
    return sqrt(dx*dx+dy*dy);
}

char C[100];
double X1[100], Y1[100], X2[100], Y2[100];
double CX[100], CY[100], R[100];

int main() {

    int N = 0;
    double x, y;
    while ((C[N] = getchar()) != '*') {
        if (C[N] == 'r') scanf("%lf %lf %lf %lf ", X1+N, Y2+N, X2+N, Y1+N);
        else scanf("%lf %lf %lf ", CX+N, CY+N, R+N);
        N++;
    }
    int k = 1;
    while (1) {
        scanf("%lf %lf", &x, &y);
        bool f = false;
        if (!cmp(x,9999.9) && !cmp(y,9999.9)) break;
        for (int i = 0; i < N; i++) {
            if (C[i]=='r' && cmp(x,X1[i])>0 && cmp(x,X2[i])<0 && cmp(y,Y1[i])>0 && cmp(y,Y2[i])<0)
                printf("Point %d is contained in figure %d\n", k, i+1), f = true;
            else if (C[i]=='c' && cmp(dist(x, y, CX[i], CY[i]), R[i]) < 0)
                printf("Point %d is contained in figure %d\n", k, i+1), f = true;
        }
        if (!f) printf("Point %d is not contained in any figure\n", k);
        k++;
    }

    return 0;
}
