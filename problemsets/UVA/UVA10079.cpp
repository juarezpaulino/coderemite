/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {

    int N;

    while (scanf("%d", &N)) {
        if (N < 0) break;
        long long ret = 1 + ((long long)N * (N+1)) / 2;
        printf("%lld\n", ret);
    }

    return 0;
}
