/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int N, hi = 0, lo = 0;
        int A, B;
        scanf("%d %d", &N, &A);
        for (int i = 1; i < N; i++) {
            scanf("%d", &B);
            if (B > A) hi++;
            else if (B < A) lo++;
            A = B;
        }
        printf("Case %d: %d %d\n", t, hi, lo);
    }

    return 0;
}
