/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {

    long long A, B;

    while (scanf("%lld %lld", &A, &B) != EOF) {
        printf("%lld\n", abs(B-A));
    }

    return 0;
}
