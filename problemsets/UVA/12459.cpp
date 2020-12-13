/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    long long fib[81];
    fib[0] = 1; fib[1] = 1;
    for (int i = 2; i <= 80; i++) fib[i] = fib[i-1]+fib[i-2];
    int N;
    while (scanf("%d", &N) && N) {
        printf("%lld\n", fib[N]);
    }

    return 0;
}
