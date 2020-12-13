/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cstring>


using namespace std;

const double EPS = 1E-10;

///////////////////////////////////////////////////////////////////////////////
// Return area of a triangle known its three sides. Herons Formula.
//
inline double triarea_sides(double a, double b, double c) {
    double p = (a+b+c) / 2.;
    return sqrt(p*(p-a)*(p-b)*(p-c)) + EPS;
}


///////////////////////////////////////////////////////////////////////////////
// Return radius of circumcircle known three sides of a triangle.
//
inline double circumcircle_triangle_radius(double &a, double &b, double &c) {
    return a*b*c / sqrt((a+b+c)*(a+b-c)*(a+c-b)*(b+c-a)) + EPS;
}

///////////////////////////////////////////////////////////////////////////////
// Return radius of incircle (inscribed circle) known three sides of a
// triangle.
//
inline double triangle_incircle_radius(double &a, double &b, double &c) {
    double p = a+b+c;
    return 2*triarea_sides(a,b,c) / p + EPS;
}


int main() {

    double a, b, c;
    while (scanf("%lf %lf %lf", &a, &b, &c) != EOF) {
        double R = circumcircle_triangle_radius(a,b,c);
        double r = triangle_incircle_radius(a,b,c);
        double t = triarea_sides(a,b,c);
        double A3 = M_PI*r*r;
        double A2 = t - A3;
        double A1 = M_PI*R*R - t;
        printf("%.4lf %.4lf %.4lf\n", A1, A2, A3);
    }

    return 0;
}
