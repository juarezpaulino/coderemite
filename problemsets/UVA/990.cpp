/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int T, W, N;
int DP[1010][35];
vector<int> dp[1010][35];
int D[35], G[35];

int go(int t, int k) {
    int &ret = DP[t][k];
    if (ret != -1) return ret;
    if (k == N) return ret = 0;
    vector<int> &p = dp[t][k];

    ret = go(t, k+1); p = dp[t][k+1];
    if (3*W*D[k] <= t) {
        int v = G[k]+go(t-3*W*D[k],k+1);
        if (v > ret) {
            ret = v;
            p = dp[t-3*W*D[k]][k+1];
            p.push_back(k);
        }
    }

    return ret;
}


int main() {

    bool f = 1;
    while (scanf("%d %d", &T, &W) != EOF) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) scanf("%d %d", D+i, G+i);
        for (int i = 0; i <= T; i++) for (int j = 0; j <= N; j++) DP[i][j] = -1, dp[i][j].clear();
        int ret = go(T,0);
        vector<int> p = dp[T][0];
        reverse(p.begin(), p.end());

        if (!f) putchar('\n');
        f = 0;
        printf("%d\n%d\n", ret, p.size());
        for (int i = 0; i < p.size(); i++)
            printf("%d %d\n", D[p[i]], G[p[i]]);
    }

    return 0;
}
