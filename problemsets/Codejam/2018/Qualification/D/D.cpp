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

double X, Y, Z;

void rotatex(double &x, double &y, double &z) {
    double x1 = x, y1 = y, z1 = z;
    x = x1;
    y = cos(X) * y1 - sin(X) * z1;
    z = sin(X) * y1 + cos(X) * z1;
}

void rotatey(double &x, double &y, double &z) {
    double x1 = x, y1 = y, z1 = z;
    x = cos(Y) * x1 + sin(Y) * z1;
    y = y1;
    z = -sin(Y) * x1 + cos(Y) * z1;
}

void rotatez(double &x, double &y, double &z) {
    double x1 = x, y1 = y, z1 = z;
    x = cos(Z) * x1 - sin(Z) * y1;
    y = sin(Z) * x1 + cos(Z) * y1;
    z = z1;
}


int main() {

    int TT;
    scanf("%d", &TT);
    for (int tt = 1; tt <= TT; tt++) {
        printf("Case #%d:\n", tt);

        double A;
        cin >> A;

        double t = 0., B, v;
        while (t < M_PI) {
            B = (A-cos(t))/sin(t), v = B*B-1;
            //printf("%.2f %.2f %.5f\n", t*180./M_PI, B, v);
            double f = asin(v)/2.;
            if (cmp(v, 1.) <= 0 && cmp(v, 0.) > 0) {
                X = sin(t)*cos(f);
                Y = sin(t)*sin(f);
                Z = cos(t);
                //printf("%f %f %f %f %f\n", X*180./M_PI, Y*180./M_PI, Z*180./M_PI, X+Y+Z, X*X+Y*Y+Z*Z);
                double x1 = 0.5, y1 = 0, z1 = 0;
                double x2 = 0., y2 = 0.5, z2 = 0;
                double x3 = 0., y3 = 0, z3 = 0.5;
                rotatex(x1,y1,z1), rotatey(x1,y1,z1), rotatez(x1,y1,z1);
                rotatex(x2,y2,z2), rotatey(x2,y2,z2), rotatez(x2,y2,z2);
                rotatex(x3,y3,z3), rotatey(x3,y3,z3), rotatez(x3,y3,z3);
                cout << setprecision(16) << fixed << x1 << " " << y1 << " " << z1 << endl;
                cout << setprecision(16) << fixed << x2 << " " << y2 << " " << z2 << endl;
                cout << setprecision(16) << fixed << x3 << " " << y3 << " " << z3 << endl;
                break;
            }
            t += 0.000872665;
        }
    }
    return 0;
}
