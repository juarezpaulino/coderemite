/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>

using namespace std;

const double EPS = 1E-10;

double A, B, C;

bool median_triarea(double A, double B, double C, double &ret) {
    double p = (A+B+C)/2.;
    ret = p*(p-A)*(p-B)*(p-C);
    if (ret < EPS) return false;
    ret = 4./3. * sqrt(ret);
    return true;
}

int main() {

    while (scanf("%lf %lf %lf", &A, &B, &C) != EOF) {
        double ret;
        if (!median_triarea(A, B, C, ret)) printf("-1.000\n");
        else printf("%.3lf\n", ret);
    }

    return 0;
}
