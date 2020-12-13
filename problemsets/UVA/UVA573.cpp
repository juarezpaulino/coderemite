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

int h, u, d, f;
double H, U, D, F;

int main() {

    while (scanf("%d %d %d %d", &h, &u, &d, &f)) {
        if (!h) break;
        H = h; U = u; D = d; F = f/100. * U;
        double p = 0.;
        int k = 1;
        while (1) {
            p = p + U;
            if (p > H+1E-10) break;
            U -= F;
            if (U <= 0.) U = 0;
            p -= D;
            if (p < -1E-10) break;
            k++;
        }
        if (p <= 1E-10) printf("failure on day %d\n", k);
        else printf("success on day %d\n", k);
    }

    return 0;
}
