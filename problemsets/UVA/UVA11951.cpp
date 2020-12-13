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
#include <numeric>

using namespace std;

int T, N, M, K;
int P[100][100];

int main() {

    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {

        scanf("%d %d %d", &M, &N, &K);
        for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) scanf("%d", &P[i][j]);

        int A = 0, ret = 0;

        for (int k = 0; k < M; k++) {
            int DP[100] = {0};
            for (int i = k; i < M; i++) {
                for (int j = 0; j < N; j++) DP[j] += P[i][j];
                int s = 0, l = 0;
                for (int j = 0; j < N; j++) {
                    s += DP[j];
                    while (s > K) s -= DP[l++];
                    int a = (i-k+1) * (j-l+1);
                    if (a > A || (a == A && s < ret)) A = a, ret = s;
                }
            }
        }

        printf("Case #%d: %d %d\n", t, A, ret);
    }

    return 0;
}
