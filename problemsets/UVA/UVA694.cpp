/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>

using namespace std;

long long A, B;

int main() {

    int T = 1;
    while (scanf("%lld %lld", &A, &B)) {
        if (A < 0 && B < 0) break;
        int ret = 1;
        int L = A;
        while (A != 1) {
            if (A % 2 == 0) A /= 2;
            else A = 3*A + 1;
            if (A > B) break;
            ret++;
        }
        printf("Case %d: A = %d, limit = %lld, number of terms = %d\n", T++, L, B, ret);
    }

    return 0;
}
