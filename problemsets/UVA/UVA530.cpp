/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

long long ncc(long long n, long long k) {
    long long num[k], den[k];
    for (int i = 0; i < k; i++) num[i] = n - i, den[i] = i + 1;
    for (int i = 0; i < k; i++) for (int j = 0; j < k; j++) {
        long long mdc = __gcd(den[i], num[j]);
        num[j] /= mdc; den[i] /= mdc;
    }
    long long ret = 1;
    for (int i = 0; i < k; i++) ret = ret*num[i];
    return ret;
}

int main() {

    long long N, K;
    while (scanf("%lld %lld", &N, &K)) {
        if (!(N|K)) break;
        if (K == 0) { printf("1\n"); continue; }
        if (N-K < K) K = N-K;
        long long ret = ncc(N,K);
        printf("%lld\n", ret);
    }

    return 0;
}
