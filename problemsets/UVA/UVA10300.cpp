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

    int T, F;
    long long A, B, C;

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &F);
        long long ret = 0;
        for (int i = 0; i < F; i++) {
            scanf("%lld %lld %lld", &A, &B, &C);
            ret += A*C;
        }
        printf("%lld\n", ret);
    }

    return 0;
}
