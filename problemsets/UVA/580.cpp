/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {

    long long E[65];
    E[0] = 1; E[1] = 2; E[2] = 4; E[3] = 7;
    for (int i = 4; i < 63; i++) E[i] = 2*E[i-1] - E[i-4];
    int N;
    while (scanf("%d", &N)) {
        if (!N) break;
        if (N <= 2) puts("0");
        else printf("%lld\n", (1LL<<N) - E[N]);
    }

    return 0;
}
