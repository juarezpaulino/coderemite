/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

typedef long long i64;

int T;
i64 N;

int main() {

    scanf("%d", &T);
    while (T--) {
        scanf("%lld", &N);
        printf("%lld\n", N*(N+2)*(2*N+1)/8);
    }

    return 0;
}
