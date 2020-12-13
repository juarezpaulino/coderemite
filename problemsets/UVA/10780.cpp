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

int N, M;

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

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d %d", &M, &N);
        prime_map mapa = factor(M);
        int ret = 0;
        for (auto p : mapa) {
            int v = 0;
            for (int i = 2; i <= N; i++) {
                for (int j = i; j % p.first == 0; j /= p.first)
                    v++;
            }
            v /= p.second;
            if (ret == 0 || ret > v) ret = v;
        }
        printf("Case %d:\n", t);
        if (ret > 0) printf("%d\n", ret);
        else puts("Impossible to divide");
    }

    return 0;
}
