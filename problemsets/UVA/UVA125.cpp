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

int N, M;
int adj[35][35];

int main() {

    int T = 0;
    while (scanf("%d", &M) != EOF) {
        for (int i = 0; i < 35; i++) for (int j = 0; j < 35; j++) adj[i][j] = 0;
        int N = 0;
        for (int i = 0; i < M; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u][v]++;
            N = max(N, max(u,v));
        }
        for (int k = 0; k <= N; k++) for (int i = 0; i <= N; i++) for (int j = 0; j <= N; j++)
            adj[i][j] += adj[i][k] * adj[k][j];

        // Check for cycles.
        for (int k = 0; k <= N; k++) if (adj[k][k])
            for (int i = 0; i <= N; i++) for (int j = 0; j <= N; j++)
                if (adj[i][k]!=0 && adj[k][j]!=0)
                    adj[i][j] = -1;

        printf("matrix for city %d\n", T++);
        for (int i = 0; i <= N; i++) {
            printf("%d", adj[i][0]);
            for (int j = 1; j <= N; j++) printf(" %d", adj[i][j]);
            putchar('\n');
        }
    }

    return 0;
}
