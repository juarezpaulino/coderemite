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

    int T, S, D;

    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &S, &D);
        int A, B;
        if ((S+D) % 2) { puts("impossible"); continue; }
        A = (S+D)/2;
        B = S - A;
        if (A < 0 || B < 0) { puts("impossible"); continue; }
        printf("%d %d\n", A, B);
    }

    return 0;
}
