/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

typedef unsigned long long u64;

u64 DP[1010101];

int main() {

    DP[3] = 0;
    u64 acc = 0;
    for (int i = 4; i <= 1000000; i++) {
        int d = (i-2) / 2;
        acc += d;
        DP[i] = DP[i-1]+acc;
    }

    int K;
    while (scanf("%d", &K)) {
        if (K < 3) break;
        printf("%llu\n", DP[K]);
    }

    return 0;
}
