/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        double d, v, u;
        scanf("%lf %lf %lf", &d, &v, &u);
        if (v+1E-7 > u || v < 1E-7) printf("Case %d: can't determine\n", t);
        else printf("Case %d: %.3lf\n", t, d/sqrt(u*u - v*v) - d/u);
    }

    return 0;
}
