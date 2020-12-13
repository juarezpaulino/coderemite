/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>

using namespace std;

int main() {

    int T, K, N;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &K);
        if (K == 0) { printf("3\n"); goto OUT; }
        K = abs(K);
        N = (int)((-1. + sqrt(1 + 8.*K)) / 2.);
        while (N*(N+1)/2 < K) N++;
        while ((N*(N+1)/2 - K)%2 != 0) N++;
        printf("%d\n", N);
OUT:
        if (T) putchar('\n');
    }

    return 0;
}
