/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

const double EPS = 1E-10;

int count_digit(int a, int base) {
    if (!a) return 1;
    double sum = 0.;
    for (int i = 2; i <= a; i++) sum += log10(i);
    return floor(sum / log10(base) + EPS)+1;
}

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


int zero(int n, int factor) {
    int total = 0, deno = factor;
    if (n == factor) return 1;
    while (deno <= n) { total += n/deno; deno *= factor; }
    return total;
}

int count_zero(int n, int base) {
    prime_map M = factor(base);
    int ret = -1;
    for (prime_map::iterator it = M.begin(); it != M.end(); it++) {
        int v = zero(n,it->first); v /= it->second;
        if (ret == -1 || ret > v) ret = v;
    }
    return ret == -1 ? 0 : ret;
}

int main() {

    int N, B;
    while (scanf("%d %d", &N, &B) != EOF) {
        printf("%d %d\n", count_zero(N,B), count_digit(N,B));
    }

    return 0;
}
