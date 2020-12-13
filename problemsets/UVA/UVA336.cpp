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

const int INF = 0x3F3F3F3F;

int N, M;
map<int, int> V;
int adj[30][30];

int main() {

    int T = 1;
    while (scanf("%d", &M)) {
        if (!M) break;

        for (int i = 0; i < 30; i++) for (int j = 0; j < 30; j++) adj[i][j] = (i==j) ? 0 : INF;
        N = 0; V.clear();

        for (int i = 0; i < M; i++) {
            int x, y, u, v;
            scanf("%d %d", &x, &y);
            if (!V.count(x)) u = V[x] = N++;
            else u = V[x];
            if (!V.count(y)) v = V[y] = N++;
            else v = V[y];
            if (u != v) adj[u][v] = adj[v][u] = 1;
        }

        // Floyd.
        for (int k = 0; k < N; k++) for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
            int d = adj[i][k] + adj[k][j];
            if (d < adj[i][j]) adj[i][j] = d;
        }

        int x, d;
        while (scanf("%d %d", &x, &d)) {
            if (!(x|d)) break;
            int u = V[x];
            int ret = 0;
            for (int i = 0; i < N; i++) if (adj[u][i] > d) ret++;
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", T++, ret, x, d);
        }
    }

    return 0;
}
