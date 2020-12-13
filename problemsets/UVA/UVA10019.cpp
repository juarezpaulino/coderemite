/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main() {

    int N, M;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &M);
        int b1 = 0, b2 = 0, X;
        // Compute b1
        b1 = __builtin_popcount(M);
        // Compute b2
        X = M;
        while (X) {
            int Y = X%10;
            b2 += __builtin_popcount(Y);
            X/=10;
        }
        printf("%d %d\n", b1, b2);
    }

    return 0;
}
