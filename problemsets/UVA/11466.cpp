/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

long long l;
int c;

void squeeze(long long &n, int p) { if (n%p == 0) l = p, c++; for (; n % p == 0; n /= p); }

long long factor(long long n) {
    if (n < 0) return (factor(-n));

    squeeze(n, 2); squeeze(n, 3);

    int maxP = (int)sqrt(n)+2;
    for (int p = 5; n != 1 && p < maxP; p += 6) { squeeze(n, p); squeeze(n, p+2); }
    if (n > 1) {
        c++;
        return n;
    }
    return l;
}


int main() {

    long long N;
    while (scanf("%lld", &N) && N) {
        l = -1; c = 0;
        long long ret = factor(N);
        if (c >= 2 && ret != N) printf("%lld\n", ret);
        else puts("-1");
    }

    return 0;
}
