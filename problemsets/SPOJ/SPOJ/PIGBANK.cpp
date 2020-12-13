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

int DP[10010];
int C[600], W[600];

int main() {

    int T, E, F, N, B;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &E, &F);
        B = F-E;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) scanf("%d %d", C+i, W+i);

        memset(DP,INF,sizeof(DP));

        DP[0] = 0;
        for (int b = 1; b <= B; b++)
            for (int i = 0; i < N; i++) if (b-W[i] >= 0)
                if (DP[b-W[i]]!=INF)
                    DP[b] = min(DP[b], DP[b-W[i]]+C[i]);

        if (DP[B] != INF) printf("The minimum amount of money in the piggy-bank is %d.\n", DP[B]);
        else printf("This is impossible.\n");
    }

    return 0;
}
