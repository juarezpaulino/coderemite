/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    long long N;
    scanf("%lld", &N);
    int k = 2;
    while (k * (long long) k <= N) {
        if (N % k == 0) { puts("S"); return 0; }
        k++;
    }
    puts("N");

    return 0;
}
