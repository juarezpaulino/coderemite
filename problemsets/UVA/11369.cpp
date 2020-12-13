/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>
#include <functional>
#include <algorithm>

using namespace std;

int main() {

    int DP[20202], P[20202];
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        memset(DP, 0, sizeof(DP));
        int N;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) scanf("%d", P+i);
        sort(P, P+N, greater<int>());
        DP[2] = P[2];
        for (int i = 3; i < N; i++) DP[i] = max(DP[i-1], DP[i-3] + P[i]);
        printf("%d\n", DP[N-1]);
    }

    return 0;
}
