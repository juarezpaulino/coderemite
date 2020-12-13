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
#include <numeric>

using namespace std;

double N;

int main() {

    while (scanf("%lf", &N)) {
        if (N < 1E-10) break;
        int a = pow(N, 1/3.)+1E-8;
        double M = a + (N-a*a*a)/3./a/a;
        printf("%.4lf\n", M);
    }

    return 0;
}
