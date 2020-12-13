/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>

using namespace std;

int A, B, C;

int main() {

    while (1) {
        scanf("%d %d %d", &A, &B, &C);
        if (!A && !B && !C) break;
        if (A + C == B + B) printf("AP %d\n", C + (C-B));
        else printf("GP %d\n", C * (C/B));
    }

    return 0;
}
