/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <map>
#include <cmath>

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

    int id = 1;
    long long N;
    while (scanf("%lld", &N) != EOF) {
        if (!N) break;
        printf("Case %d: ", id++);
        if (N == 1) { printf("2\n"); continue; }
        prime_map P = factor(N);
        long long ret = (P.size() == 1) ? 1 : 0;
        for (prime_map::iterator it = P.begin(); it != P.end(); it++) {
            long long s = 1;
            for (int i = 0; i < it->second; i++) s *= it->first;
            ret += s;
        }
        printf("%lld\n", ret);
    }

    return 0;
}
