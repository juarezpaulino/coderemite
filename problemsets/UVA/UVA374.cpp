/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>

using namespace std;

long long B, P, M;

long long FEXP(long long A, int P) {
    if (P == 0) return 1LL;
    long long ret = FEXP(A, P/2);
    ret = (ret*ret) % M;
    if (P%2==1) ret = (ret*A) % M;
    return ret;
}

int main() {

    while (scanf("%lld %lld %lld", &B, &P, &M) != EOF) {
        B %= M;
        B = FEXP(B, P);
        printf("%lld\n", B);
    }

    return 0;
}
