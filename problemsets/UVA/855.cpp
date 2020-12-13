/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

int M, N, K;
int X[50505], Y[50505];

int main() {

    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &M, &N, &K);
        int m = 0, n = 0;
        for (int i = 0; i < K; i++) scanf("%d %d", X+i, Y+i);
        random_shuffle(X, X+K); random_shuffle(Y, Y+K);
        nth_element(X, X+(K-1)/2, X+K); nth_element(Y, Y+(K-1)/2, Y+K);
        printf("(Street: %d, Avenue: %d)\n", X[(K-1)/2], Y[(K-1)/2]);
    }

    return 0;
}
