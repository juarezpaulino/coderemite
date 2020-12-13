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
        int A, B, C;
        scanf("%d %d %d", &A, &B, &C);
        bool ok = 0;
        for (int i = -100; !ok && i <= 100; i++) for (int j = i+1; !ok && j <= 100; j++) {
            int k = A - i - j;
            if (k < j) continue;
            int b = i*j*k;
            int c = i*i+j*j+k*k;
            if (b == B && c == C) {
                printf("%d %d %d\n", i, j, k);
                ok = 1;
            }
        }
        if (!ok) puts("No solution.");
    }

    return 0;
}
