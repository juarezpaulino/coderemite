/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long i64;

int main() {

    i64 V;
    while (1) {
        scanf("%lld", &V);
        if (V == -1) break;
        if (V == 0) { puts("N"); break; }
        i64 D = 9 + 12 * (V-1);
        if ((fabs((i64)sqrt(D)*(i64)sqrt(D)-D) < 1E-8) && ((i64)(3 + sqrt(D) + 1E-8) % 6 == 0))
            puts("Y");
        else puts("N");
    }

    return 0;
}
