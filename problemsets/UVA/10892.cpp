/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template <class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

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

    int N;
    while (scanf("%d", &N) && N) {
        prime_map M = factor(N);
        int ret = 1;
        for (auto m : M) ret *= 2*m.second+1;
        ret = (ret+1)/2;
        printf("%d %d\n", N, ret);
    }

    return 0;
}
