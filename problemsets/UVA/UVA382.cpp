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

    int N;

    printf("PERFECTION OUTPUT\n");

    while (scanf("%d", &N)) {
        if (N==0) break;
        int d = 1;
        int p = 0;
        while (2 * d <= N) {
            if (N%d==0) p += d;
            d++;
        }
        if (p == N) printf("%5d  PERFECT\n", N);
        else if (p < N) printf("%5d  DEFICIENT\n", N);
        else printf("%5d  ABUNDANT\n", N);
    }

    printf("END OF OUTPUT\n");

    return 0;
}
