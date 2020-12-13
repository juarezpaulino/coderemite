/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>

#define _FORIT(it, b, e) for (__typeof(b) it = (b); it != (e); it++)
#define FORIT(x...) _FORIT(x)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

int T, A, B;

template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

typedef map<int, int> prime_map;

void squeeze(prime_map &M, int &n, int p) { for (; n % p == 0; n /= p) M[p]++; }

prime_map factor(int n) {
    prime_map M;
    if (n < 0) return (factor(-n));
    if (n < 2) return M;

    squeeze(M, n, 2); squeeze(M, n, 3);

    int maxP = (int)sqrt(n)+2;
    for (int p = 5; p < maxP; p += 6) { squeeze(M, n, p); squeeze(M, n, p+2); }
    if (n > 1) M[n]++;
    return M;
}

int main() {

    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &A, &B);
        prime_map M = factor(gcd(A,B));
        int ret = 1;
        FORIT(it,ALL(M)) {
            ret *= it->second+1;
        }
        printf("%d\n", ret);
    }

    return 0;
}
