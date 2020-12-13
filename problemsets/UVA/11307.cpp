/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

int N, R;
vector<int> adj[10101];
int DP[10101][10];
char I[10101];

int go(int u, int x) {
    int &ret = DP[u][x];
    if (ret != -1) return ret;
    if (adj[u].size() == 0) return ret = x;
    ret = x;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = 1<<30;
        for (int j = 1; j < 7; j++) if (x != j)
            v = min(v, go(adj[u][i], j));
        ret += v;
    }
    return ret;
}

int main() {

    char S[1010101];
    while (scanf("%d ", &N)) {
        if (!N) break;
        for (int i = 0; i <= N; i++) adj[i].clear(), I[i] = 0;
        for (int i = 0; i <= N; i++) for (int j = 0; j < 7; j++) DP[i][j] = -1;
        for (int i = 0; i < N; i++) {
            gets(S);
            istringstream is(S);
            int u, v;
            char c;
            is >> u >> c;
            while (is >> v) adj[u].push_back(v), I[v] = 1;
        }
        for (int i = 0; i < N; i++) if (I[i]==0) { R = i; break; }
        int ret = 1<<30;
        for (int j = 1; j < 7; j++) ret = min(ret, go(R,j));
        printf("%d\n", ret);
    }

    return 0;
}
