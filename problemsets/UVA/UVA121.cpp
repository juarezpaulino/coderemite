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

double A, B;

const double EPS = 1E-10;

inline int cmp(double A, double B = 0, double tol = EPS) {
    return (A < B+tol) ? (B < A+tol) ? 0 : -1 : 1;
}

int skew(double A, double B) {
    if (cmp(B,1) < 0) return 0;
    int ret = 0;
    int h = (B-1) / sqrt(.75) + 1 + EPS;
    ret += h/2 * (int)(A-.5);
    ret += (h+1)/2 * (int)A;
    return ret;
}

int main() {

    string pat;
    int ret;
    while (scanf("%lf %lf", &A, &B) != EOF) {
        pat = "grid"; ret = (int)A * (int)B;
        int tot;
        if ((tot = skew(A,B)) > ret) ret = tot, pat = "skew";
        if ((tot = skew(B,A)) > ret) ret = tot, pat = "skew";
        printf("%d %s\n", ret, pat.c_str());
    }

    return 0;
}
