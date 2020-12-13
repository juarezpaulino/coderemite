/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int A, B, C, D, E, F;

int main() {

    int id = 1;
    while (scanf("%d%d%d%d%d%d", &A, &B, &C, &D, &E, &F)!=EOF) {
        int s = 0, t = 0;
        if (A > 0) { s++; t += A + 1200*(D-1); }
        if (B > 0) { s++; t += B + 1200*(E-1); }
        if (C > 0) { s++; t += C + 1200*(F-1); }
        printf("team %d: %d, %d\n", id, s, t);
        ++id;
    }

    return 0;
}
