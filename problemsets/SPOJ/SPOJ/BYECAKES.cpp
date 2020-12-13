/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;


int main() {

    int A1, B1, C1, D1;
    int A2, B2, C2, D2;

    while (1) {
        scanf("%d %d %d %d", &A1, &B1, &C1, &D1);
        scanf("%d %d %d %d", &A2, &B2, &C2, &D2);
        if (A1 == -1 && D2 == -1) break;

        int N = A1, M = A2;
        if (N * B2 < M * B1) N = B1, M = B2;
        if (N * C2 < M * C1) N = C1, M = C2;
        if (N * D2 < M * D1) N = D1, M = D2;

        N = (N + M - 1) / M;
        printf("%d %d %d %d\n", N*A2-A1, N*B2-B1, N*C2-C1, N*D2-D1);
    }

    return 0;
}
