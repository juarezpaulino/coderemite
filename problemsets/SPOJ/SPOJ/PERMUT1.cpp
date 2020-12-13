/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int D, N, K;
int VAL[12][100];

void PRE() {
    VAL[1][0] = 1;
    for (int n = 1; n < 12; n++) {
        for (int i = 0; VAL[n][i]; i++) {
            for (int j = i; j <= i+n; j++) VAL[n+1][j] += VAL[n][i];
        }
    }
}

int main() {

    PRE();
    scanf("%d", &D);
    while (D--) {
        scanf("%d %d", &N, &K);

        printf("%d\n", VAL[N][K]);
    }

    return 0;
}
