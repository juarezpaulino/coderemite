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

int C, S, Q;
int adj[200][200];

const int INF = 0x3F3F3F3F;

int main() {

    int T = 1;
    while (scanf("%d %d %d", &C, &S, &Q)) {
        if (!(C|S|Q)) break;
        for (int i = 1; i <= C; i++) for (int j = 1; j <= C; j++) adj[i][j] = (i==j) ? 0 : INF;
        for (int i = 0; i < S; i++) {
            int u, v, c;
            scanf("%d %d %d", &u, &v, &c);
            if (adj[u][v] > c) adj[u][v] = adj[v][u] = c;
        }
        for (int k = 1; k <= C; k++) for (int i = 1; i <= C; i++) for (int j = 1; j <= C; j++) {
            int d = max(adj[i][k], adj[k][j]);
            if (d < adj[i][j]) adj[i][j] = d;
        }
        if (T > 1) putchar('\n');
        printf("Case #%d\n", T++);
        for (int i = 0; i < Q; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            if (adj[u][v]>=INF) puts("no path");
            else printf("%d\n", adj[u][v]);
        }
    }

    return 0;
}
