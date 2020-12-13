/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int F[31], G[31];

int main() {

    F[0] = G[1] = 1;
    F[1] = G[0] = 0;
    for (int i = 2; i <= 30; i++) {
        F[i] = F[i-2] + 2*G[i-1];
        G[i] = F[i-1] + G[i-2];
    }
    while (1) {
        scanf("%d", &N);
        if (N == -1) break;
        printf("%d\n", F[N]);
    }

    return 0;
}
