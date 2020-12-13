/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int DP[10101];
int V[110];

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        int M, N;
        scanf("%d %d", &M, &N);
        for (int i = 0; i < N; i++) scanf("%d", V+i);
        for (int i = 0; i <= 10000; i++) DP[i] = 1<<30;
        DP[0] = 0;
        for (int i = 0; i < N; i++)
            for (int j = 10000; j >= 0; j--)
                if (DP[j] != 1<<30 && j+V[i] <= 10000 && DP[j+V[i]] > DP[j]+1)
                    DP[j+V[i]] = DP[j]+1;
        for (int i = M; i <= 10000; i++)
            if (DP[i] != 1<<30) {
                printf("%d %d\n", i, DP[i]);
                break;
            }
    }

    return 0;
}
