/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <numeric>

using namespace std;

typedef map<int, int> prime_map;

void squeeze(prime_map &M, long long &n, int p) { for (; n % p == 0; n /= p) M[p]++; }

prime_map factor(long long n) {
    prime_map M;
    if (n < 0) return (factor(-n));
    if (n < 2) return M;

    squeeze(M, n, 2); squeeze(M, n, 3);

    int maxP = (int)sqrt(n)+2;
    for (int p = 5; p < maxP; p += 6) { squeeze(M, n, p); squeeze(M, n, p+2); }
    if (n > 1) M[n]++;
    return M;
}


long long N;

int main() {

    while (scanf("%lld", &N)) {
        if (!N) break;
        prime_map M = factor(N);
        int ret = 0;
        for (prime_map::iterator it = M.begin(); it != M.end(); it++)
            ret = __gcd(ret,it->second);
        while (N < 0 && ret%2==0) ret/=2;
        printf("%d\n", ret);
    }

    return 0;
}
