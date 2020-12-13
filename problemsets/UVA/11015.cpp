/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <string>
#include <cstring>
#include <map>

using namespace std;

int adj[30][30];
char S[30][101];

int main() {

    int N, M, T = 1;
    while (scanf("%d %d", &N, &M)) {
        if (!N) break;
        memset(adj, 0x3F3F3F3F, sizeof(adj));
        for (int i = 0; i < N; i++) scanf("%s", S[i]), adj[i][i] = 0;
        for (int i = 0; i < M; i++) {
            int x, y, c; scanf("%d %d %d", &x, &y, &c); x--; y--;
            adj[x][y] = adj[y][x] = min(adj[x][y], c);
        }
        for (int k = 0; k < N; k++) for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
            int c = adj[i][k] + adj[k][j];
            if (c < adj[i][j]) adj[i][j] = c;
        }
        int ret = -1, RET = 0x3F3F3F3F;
        for (int p = 0; p < N; p++) {
            int P = 0;
            for (int j = 0; j < N; j++) P += adj[p][j];
            if (P < RET) RET = P, ret = p;
        }
        printf("Case #%d : %s\n", T++, S[ret]);
    }

    return 0;
}
