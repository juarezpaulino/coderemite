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

    long long M;
    while (scanf("%lld", &M) != EOF) {
        long long n = (-1. + sqrt(1. + 8.*M)) / 2. + 1. - 1E-8;
        long long d = (n*n + n) / 2 - M + 1;
        printf("%lld/%lld\n", d, n-d+1);
    }

    return 0;
}
