/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


using namespace std;

double T;
double P[8][3] = {  {-0.5,0.5,0.5},     // A
                    {0.5,0.5,0.5},      // B
                    {0.5,-0.5,0.5},     // C
                    {0.5,-0.5,-0.5},    // D
                    {-0.5,-0.5,-0.5},   // E
                    {-0.5,0.5,-0.5},    // F
                    {-0.5,-0.5,0.5},    // G
                    {0.5,0.5,-0.5} };   // H
double Q[8][3];
double A;


void rotatex(double &x, double &y, double &z) {
    double x1 = x, y1 = y, z1 = z;
    x = x1;
    y = cos(T) * y1 - sin(T) * z1;
    z = sin(T) * y1 + cos(T) * z1;
}

void rotatey(double &x, double &y, double &z) {
    double x1 = x, y1 = y, z1 = z;
    x = cos(T) * x1 + sin(T) * z1;
    y = y1;
    z = -sin(T) * x1 + cos(T) * z1;
}

void rotatez(double &x, double &y, double &z) {
    double x1 = x, y1 = y, z1 = z;
    x = cos(T) * x1 - sin(T) * y1;
    y = sin(T) * x1 + cos(T) * y1;
    z = z1;
}


double area() {
    double ret = 0.;
    for (int i = 0, j = i+1; i < 6; i++, j = (i+1)%6)
        ret += Q[i][0]*Q[j][2]-Q[i][2]*Q[j][0];
    return fabs(ret)/2.;
}

double FT(double v) {
    T = v;
    memcpy(Q,P,sizeof(P));
    for (int i = 0; i < 8; i++)
        rotatex(Q[i][0],Q[i][1],Q[i][2]);
    return fabs(A-area());
}


int main() {

    T = M_PI/4.;
    for (int i = 0; i < 8; i++) rotatey(P[i][0],P[i][1],P[i][2]);

    int TT;
    scanf("%d", &TT);
    for (int tt = 1; tt <= TT; tt++) {
        printf("Case #%d:\n", tt);

        cin >> A;

        double lo = 0., hi = M_PI/2., flo, fhi;
        for (int it = 0; it < 1000; it++) {
            if (cmp(lo,hi)==0) break;
            double lo2 = (2*lo + hi) / 3, hi2 = (lo + 2*hi) / 3;
            flo = FT(lo2); fhi = FT(hi2);
            (flo > fhi) ? lo = lo2 : hi = hi2;
        }
        FT((lo+hi)/2.);

        double x1 = (Q[0][0]+Q[2][0])/2., y1 = (Q[0][1]+Q[2][1])/2., z1 = (Q[0][2]+Q[2][2])/2.;
        double x2 = (Q[2][0]+Q[4][0])/2., y2 = (Q[2][1]+Q[4][1])/2., z2 = (Q[2][2]+Q[4][2])/2.;
        double x3 = (Q[0][0]+Q[4][0])/2., y3 = (Q[0][1]+Q[4][1])/2., z3 = (Q[0][2]+Q[4][2])/2.;

        printf("%.16f %.16f %.16f\n", x1, y1, z1);
        printf("%.16f %.16f %.16f\n", x2, y2, z2);
        printf("%.16f %.16f %.16f\n", x3, y3, z3);
    }
    return 0;
}
