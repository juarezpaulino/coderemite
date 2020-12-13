/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    int T, N, A, D;

    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &N, &A, &D);
        int K = ((2*A + (N-1)*D) * N) / 2;
        printf("%d\n", K);
    }

    return 0;
}
