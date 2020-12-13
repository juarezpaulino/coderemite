/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    long long N;
    int T; scanf("%d", &T);
    while (T-- && scanf("%llu", &N) != EOF) {
        long long lo = 0, hi = 1000000000LL, m;
        while (hi > lo+1) {
            if (hi <= lo) break;
            m = lo + (hi-lo) / 2;
            if ((m*m + m) / 2 <= N) lo = m;
            else hi = m;
        }
        printf("%lld\n", lo);
    }

    return 0;
}
