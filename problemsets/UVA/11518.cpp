/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>

using namespace std;

char marc[10101];
vector<int> adj[10101];
int N, M, L;
int ret;

void dfs(int u) {
    marc[u] = 1;
    ret++;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (!marc[v]) dfs(v);
    }
}


int main() {

    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &N, &M, &L);
        for (int i = 0; i < N; i++) adj[i].clear(), marc[i] = 0;
        for (int i = 0; i < M; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            adj[x-1].push_back(y-1);
        }
        ret = 0;
        for (int i = 0; i < L; i++) {
            int x; scanf("%d", &x);
            if (!marc[x-1]) dfs(x-1);
        }
        printf("%d\n", ret);
    }


    return 0;
}
