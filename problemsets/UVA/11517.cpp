/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int D[20202][110];
int V[110];

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        int M, N;
        scanf("%d %d", &M, &N);
        int maxi = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d", V+i);
            maxi = max(maxi, V[i]);
        }
        for (int i = 0; i <= M+maxi; i++)
            for (int j = 0; j <= N; j++)
                D[i][j] = -1;

        D[0][0] = 0;
        queue<int> q1, q2;
        q1.push(0);
        q2.push(0);
        int ret = 1<<30, c = 1<<30;
        while (!q1.empty()) {
            int u = q1.front(); q1.pop();
            int k = q2.front(); q2.pop();
            if (u >= M) {
                if (ret > u || (ret == u && D[u][k] < c)) {
                    ret = u; c = D[u][k];
                }
                continue;
            }
            for (int i = k; i < N; i++) {
                int v = u + V[i];
                if (D[v][i+1] == -1) {
                    D[v][i+1] = D[u][k]+1;
                    q1.push(v);
                    q2.push(i+1);
                }
            }
        }
        printf("%d %d\n", ret, c);
    }

    return 0;
}
