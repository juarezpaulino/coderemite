/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int DP[220][22];
vector<int> V[22];
int M, C;

int go(int m, int c) {
    if (m < 0) return -1;
    if (c < 0) return 0;
    int &ret = DP[m][c];
    if (ret != -2) return ret;
    ret = -1;
    for (int j = 0; j < V[c].size(); j++) {
        int v = V[c][j],
            u = go(m-v,c-1);
        if (u != -1) ret = max(ret, u+v);
    }
    return ret;
}

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &M, &C);
        for (int i = 0; i < C; i++) {
            V[i].clear();
            int x, y;
            scanf("%d", &x);
            while (x--) {
                scanf("%d", &y);
                V[i].push_back(y);
            }
        }
        for (int i = 0; i <= M; i++) for (int j = 0; j < C; j++) DP[i][j] = -2;
        int ret = go(M, C-1);
        if (ret == -1) puts("no solution");
        else printf("%d\n", ret);
    }

    return 0;
}
