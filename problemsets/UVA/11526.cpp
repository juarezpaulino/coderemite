/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>

using namespace std;


int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        long long ret = 0;
        int v = sqrt(N+1E-10);
        for (int i = 1; i <= v; i++) ret += (N/i);
        printf("%lld\n", 2*ret-v*v);
    }

    return 0;
}
