/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

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

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int K;
        scanf("%d", &K);
        prime_map F = factor(K);
        set<int> U;
        int n = 1;
        printf("Case #%d: %d", t, K);
        int c = 0;
        for (prime_map::iterator it = F.begin(); c < 2 && it != F.end(); it++) {
            for (int i = 0; c < 2 && i < it->second; i++) {
                n *= it->first;
                if (!U.count(n)) printf(" = %d * %d", n, K/n), U.insert(n), U.insert(K/n), c++;
            }
        }
        putchar('\n');
    }

    return 0;
}
