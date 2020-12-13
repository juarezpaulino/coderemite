/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

const int INF = 0x3F3F3F3F;

int C, S, E, T;
int DP[101][10001];
int adj[101][101];
set<int> L;

int go(int s, int t) {
    int &ret = DP[s][t];
    if (ret != -1) return ret;
    if (t == T) {
        if (L.count(s)) return 0;
        else return -INF;
    }
    ret = -INF;
    for (int i = 0; i < C; i++) {
        int c = go(i, t+1);
        if (c != -INF) ret = max(ret, c+adj[s][i]);
    }
    return ret;
}

int main() {

    while (scanf("%d %d %d %d", &C, &S, &E, &T)) {
        if (!(C|S|E|T)) break;
        S--;
        for (int i = 0; i < C; i++) for (int j = 0; j < C; j++) scanf("%d", &adj[i][j]);
        for (int i = 0; i < C; i++) for (int j = 0; j <= T; j++) DP[i][j] = -1;
        L.clear();
        for (int i = 0; i < E; i++) {
            int x; scanf("%d", &x); x--; L.insert(x);
        }
        int ret = go(S, 0);
        printf("%d\n", ret);
    }

    return 0;
}
