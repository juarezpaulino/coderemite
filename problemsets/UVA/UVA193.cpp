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

int T;
int N, M;
int adj[110][110];
char color[110];
vector<int> RET;
int ret;

void solve(int k, int c) {
    int u = -1;

    if (c+N-k <= ret) return;

    // Find a node.
    for (int i = 1; i <= N; i++) if (color[i]==-1) { u = i; break; }
    if (u == -1) {
        if (c > ret) {
            ret = c;
            RET.clear();
            for (int i = 1; i <= N; i++) if (color[i]==1) RET.push_back(i);
        }
        return;
    }

    // Color black vertex.
    vector<int> q;
    color[u] = 1;
    int t = 1;
    for (int i = 1; i <= N; i++) if (adj[u][i] && color[i]==-1) {
        color[i] = 0; t++; q.push_back(i);
    }
    solve(k+t, c+1);
    for (int i = 0; i < q.size(); i++) color[q[i]] = -1;

    // Color white vertex.
    color[u] = 0;
    solve(k+1, c);
    color[u] = -1;
}

int main() {

    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &M);
        memset(adj,0,sizeof(adj));
        for (int i = 0; i < M; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u][v] = adj[v][u] = 1;
        }
        for (int i = 1; i <= N; i++) color[i] = -1;
        ret = 0;
        solve(0, 0);
        printf("%d\n", ret);
        bool f = 0;
        for (int i = 0; i < RET.size(); i++) {
            if (f) putchar(' ');
            f = 1;
            printf("%d", RET[i]);
        }
        putchar('\n');
    }

    return 0;
}
