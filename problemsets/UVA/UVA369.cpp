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

int ncc(int n, int k) {
    int num[k], den[k];
    for (int i = 0; i < k; i++) num[i] = n - i, den[i] = i + 1;
    for (int i = 0; i < k; i++) for (int j = 0; j < k; j++) {
        int mdc = __gcd(den[i], num[j]);
        num[j] /= mdc; den[i] /= mdc;
    }
    int ret = 1;
    for (int i = 0; i < k; i++) ret = ret*num[i];
    return ret;
}

int main() {

    int N, K;
    while (scanf("%d %d", &N, &K)) {
        if (!(N|K)) break;
        printf("%d things taken %d at a time is %d exactly.\n", N, K, ncc(N,K));
    }

    return 0;
}
