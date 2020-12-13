/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;


int main() {

    int T, N;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        if (N < 10) { printf("%d\n", N); continue; }
        int C[10] = {0};
        for (int c = 9; c >= 2; c--)
            while (N%c == 0) { C[c]++; N /= c; }
        if (N != 1) puts("-1");
        else {
            for (int c = 2; c < 10; c++) for (int i = 0; i < C[c]; i++) putchar(c+'0');
            putchar('\n');
        }
    }

    return 0;
}
