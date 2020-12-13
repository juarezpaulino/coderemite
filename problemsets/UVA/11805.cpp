/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

    int T, N, K, P;

    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        scanf("%d %d %d", &N, &K, &P);
        printf("Case %d: %d\n", i, ((K+P-1)%N)+1);
    }

    return 0;
}
