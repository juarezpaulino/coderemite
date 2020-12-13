/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

typedef map<long long, int> prime_map;

void squeeze(prime_map &M, long long &n, int p) { for (; n % p == 0; n /= p) M[p]++; }

prime_map factor(long long n) {
    prime_map M;
    if (n < 0) return (factor(-n));
    if (n < 2) return M;

    squeeze(M, n, 2); squeeze(M, n, 3);

    int maxP = min((int)sqrt(n)+2,1000000);
    for (int p = 5; n != 1 && p < maxP; p += 6) { squeeze(M, n, p); squeeze(M, n, p+2); }
    if (n > 1) M[n]++;
    return M;
}

int main() {

    long long N;
    while (scanf("%lld", &N)) {
        if (N < 0) break;
        if (N <= 2) { printf("    %4lld\n\n", N); continue; }
        prime_map M = factor(N);
        for (prime_map::iterator it = M.begin(); it != M.end(); it++) {
            long long v = it->first, k = it->second;
            for (int i = 0; i < k; i++) printf("    %lld\n", v);
        }
        putchar('\n');
    }

    return 0;
}
