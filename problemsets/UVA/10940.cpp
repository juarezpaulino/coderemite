/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {

    int N;
    while (1) {
        scanf("%d", &N);
        if (!N) break;
        if (__builtin_popcount(N) == 1) printf("%d\n", N);
        else {
            N <<= 1;
            int k = 0, m = N;
            while (m) { m/=2; k++; }
            N ^= 1<<(k-1);
            printf("%d\n", N);
        }
    }

    return 0;
}
