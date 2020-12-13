/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int DP[101][101];

int main() {

    int N, K;
    while (1) {
        scanf("%d", &N);
        if (!N) break;
        for (int i = 0; i < N; i++) scanf("%d", &DP[i][0]);
        scanf("%d", &K);
        for (int j = 1; j < N; j++) for (int i = 0; i < N-j; i++) DP[i][j] = DP[i+1][j-1] - DP[i][j-1];
        int V[101];
        for (int j = 0; j < N; j++) V[j] = DP[N-j-1][j];
        for (int i = 0; i < K; i++) for (int j = N-2; j >= 0; j--) V[j] = V[j+1] + V[j];
        printf("Term %d of the sequence is %d\n", N+K, V[0]);
    }

    return 0;
}
