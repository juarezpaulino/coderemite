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

using namespace std;

int DP[35];
int N, G;
int P[1000], W[1000];

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        memset(DP, 0, sizeof(DP));
        scanf("%d", &N);
        for (int i = 0; i < N; i++) scanf("%d %d", P+i, W+i);
        int d;
        for (int k = 0; k < N; k++) for (int i = 30; i >= 0; i--)
            if (W[k] <= i && DP[i] < (d = DP[i-W[k]] + P[k]))
                DP[i] = d;
        scanf("%d", &G);
        int ret = 0;
        for (int i = 0; i < G; i++) scanf("%d", &d), ret += DP[d];
        printf("%d\n", ret);
    }

    return 0;
}
