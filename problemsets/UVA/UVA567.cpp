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

int adj[21][21];

int main() {

    int T = 1;

    while (1) {
        for (int i = 1; i <= 20; i++) for (int j = 1; j <= 20; j++) adj[i][j] = (i==j) ? 0 : INF;
        for (int i = 1; i < 20; i++) {
            int M;
            if (scanf("%d", &M) == EOF) return 0;
            while (M--) {
                int x;
                scanf("%d", &x);
                if (i != x) adj[i][x] = adj[x][i] = 1;
            }
        }
        for (int k = 1; k <= 20; k++) for (int i = 1; i <= 20; i++) for (int j = 1; j <= 20; j++) {
            int d = adj[i][k] + adj[k][j];
            if (d < adj[i][j]) adj[i][j] = d;
        }
        printf("Test Set #%d\n", T++);
        int N;
        scanf("%d", &N);
        while (N--) {
            int u, v;
            scanf("%d %d", &u, &v);
            printf("%2d to %2d: %d\n", u, v, adj[u][v]);
        }
        putchar('\n');
    }

    return 0;
}
