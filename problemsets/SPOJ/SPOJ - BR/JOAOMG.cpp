/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main() {

    int N;
    while (scanf("%d", &N)) {
        if (!N) break;
        if (N == 1) { puts("1: S"); continue; }
        else if (N == 10 || N == 100 || N == 1000 || N == 10000) { printf("%d: N\n", N); continue; }
        int n = N*N, t = 10;
        bool ok = 0;
        while (!ok && t < n) {
            int q = n / t, r = n % t;
            if (N == q+r) ok = 1;
            t *= 10;
        }
        printf("%d: %c\n", N, ok ? 'S' : 'N');
    }

    return 0;
}
