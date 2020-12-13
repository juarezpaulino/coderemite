/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 0x3F3F3F3F;

int DP[22][80];
int CT[1000], CA[1000], W[1000];
int C, T, A, N;


int main() {

    scanf("%d", &C);
    while (C--) {
        scanf("%d %d %d", &T, &A, &N);
        for (int i = 0; i < N; i++) scanf("%d %d %d", CT+i, CA+i, W+i);

        memset(DP,INF,sizeof(DP));
        DP[0][0] = 0;
        for (int i = 0; i < N; i++) {
            for (int j = T; j >= 0; j--)
                for (int k = A; k >= 0; k--) {
                    int t = min(j+CT[i],T), a = min(k+CA[i],A);
                    DP[t][a] = min(DP[t][a], DP[j][k]+W[i]);
                }
        }
        printf("%d\n", DP[T][A]);
    }

    return 0;
}
