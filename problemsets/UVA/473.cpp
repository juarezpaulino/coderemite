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

vector<vector<vector<int> > > DP;
int n, t, m;
vector<int> V;

const int INF = 1<<30;

int go(int a, int b, int c) {
    int &ret = DP[a][b][c];
    if (ret != -1) return ret;
    if (a == n) {
        if (c < m-1) return ret = -INF;
        return ret = 0;
    }
    if (c == m) return ret = 0;
    ret = -INF;
    ret = max(ret, go(a+1, b, c));
    if (b < t) ret = max(ret, go(a,t,c+1));
    if (b-V[a] >= 0) ret = max(ret, 1+go(a+1, b-V[a], c));
    return ret;
}


int main() {

    int c;
    scanf("%d", &c);
    while (c--) {
        scanf("%d %d %d", &n, &t, &m);
        V.resize(n);
        DP.resize(n+1); for (int i = 0; i <= n; i++) {
            DP[i].resize(t+1); for (int j = 0; j <= t; j++) {
                DP[i][j].resize(m+1); for (int k = 0; k <= m; k++)
                    DP[i][j][k] = -1;
            }
        }
        for (int i = 0; i < n; i++) scanf("%d%*c", &V[i]);
        int ret = go(0,t,0);
        printf("%d\n", ret);
        if (c) putchar('\n');
    }

    return 0;
}
