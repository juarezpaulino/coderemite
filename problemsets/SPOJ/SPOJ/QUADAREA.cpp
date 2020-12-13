/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int T;
double A, B, C, D;

double max_quad_area(double A, double B, double C, double D) {
    double s = (A+B+C+D)/2;
    double ret = sqrt((s-A)*(s-B)*(s-C)*(s-D));
    return ret;
}

int main() {

    scanf("%d", &T);
    while (T--) {
        scanf("%lf %lf %lf %lf", &A, &B, &C, &D);
        double s = (A+B+C+D)/2;
        double ret = sqrt((s-A)*(s-B)*(s-C)*(s-D));
        printf("%.2lf\n", ret);
    }

    return 0;
}
