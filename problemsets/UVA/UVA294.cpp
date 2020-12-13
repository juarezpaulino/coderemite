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
#include <sstream>
#include <algorithm>

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

    int N, L, U;
    scanf("%d", &N);
    while (N--) {
        scanf("%d %d", &L, &U);
        int P = -1, D = 0;
        for (int i = L; i <= U; i++) {
            prime_map M = factor(i);
            int d = 1;
            for (prime_map::iterator it = M.begin(); it != M.end(); it++) d *= it->second+1;
            if (d > D) P = i, D = d;
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n", L, U, P, D);
    }

    return 0;
}
