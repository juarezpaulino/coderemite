/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long i64;

i64 G, T, A, D;

int main() {

    while (1) {
        scanf("%lld %lld %lld %lld", &G, &T, &A, &D);
        if (G == -1 && T == -1 && A == -1 && D == -1) break;
        i64 Z = 0; for (i64 T = G*A + D - 1; T; Z++, T/=2);
        if (A==1 && G==1 && D==0) Z = 0;
        i64 Y = (1LL<<Z) - G*A - D;
        i64 X = G*T*(T-1)/2 + (1LL<<Z) - 1;
        printf("%lld*%lld/%lld+%lld=%lld+%lld\n", G, A, T, D, X, Y);
    }

    return 0;
}
