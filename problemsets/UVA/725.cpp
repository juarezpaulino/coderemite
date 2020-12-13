/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
char sol, A[10], F[255];

void generate(int k) {
    if (k == 5) {
        int a = atoi(A), b = a * N;
        if (b > 99999) return;
        char B[10];
        sprintf(B, "%05d", b);
        for (int i = 0; i < 5; i++) F[B[i]]++;
        bool ok = 1;
        for (int i = '0'; ok && i <= '9'; i++) if (F[i] != 1) ok = 0;
        if (ok) {
            sol = 1;
            printf("%s / %s = %d\n", B, A, N);
        }
        for (int i = 0; i < 5; i++) F[B[i]]--;
        return;
    }
    for (int i = '0'; i <= '9'; i++) if (!F[i]) {
        A[k] = i; F[i]++;
        generate(k+1);
        F[i]--;
    }
}

int main() {

    bool nl = 0;
    int L = -1;
    while (1) {
        scanf("%d", &N);
        if (!N) break;
        if (nl && N != L) putchar('\n');
        sol = 0;
        generate(0);
        if (!sol) printf("There are no solutions for %d.\n", N);
        nl = 1;
        L = N;
    }

    return 0;
}
