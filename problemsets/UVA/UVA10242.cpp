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

int cmp(double x, double y = 0., double tol = EPS) {
    return (x < y+tol) ? (y < x+tol) ? 0 : -1 : 1;
}

double X[4], Y[4];

int main() {

    while (scanf("%lf %lf %lf %lf %lf %lf %lf %lf", X, Y, X+1, Y+1, X+2, Y+2, X+3, Y+3) != EOF) {
        if (cmp(X[0],X[2])==0 && cmp(Y[0],Y[2])==0) {
            X[4] = X[1] + X[3] - X[0];
            Y[4] = Y[1] + Y[3] - Y[0];
        }
        else if (cmp(X[0],X[3])==0 && cmp(Y[0],Y[3])==0) {
            X[4] = X[1] + X[2] - X[0];
            Y[4] = Y[1] + Y[2] - Y[0];
        }
        else if (cmp(X[1],X[2])==0 && cmp(Y[1],Y[2])==0) {
            X[4] = X[0] + X[3] - X[1];
            Y[4] = Y[0] + Y[3] - Y[1];
        }
        else {
            X[4] = X[0] + X[2] - X[1];
            Y[4] = Y[0] + Y[2] - Y[1];
        }
        printf("%.3lf %.3lf\n", X[4], Y[4]);
    }

    return 0;
}
