/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <queue>
#include <map>

using namespace std;

typedef pair<int,int> PII;

const int INF = 0x3F3F3F3F;

int N, M;
int dist[1010], marc[1010], pai[1010];
int D[1010][1010];
int X[1010], Y[1010];

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) scanf("%d%d", X+i, Y+i), dist[i] = INF, marc[i] = 0, pai[i] = -1;
        for (int i = 1; i <= N; i++) for (int j = i; j <= N; j++) {
            int dx = X[i]-X[j], dy = Y[i]-Y[j];
            D[i][j] = D[j][i] = dx*dx+dy*dy;
        }
        scanf("%d", &M);
        while (M--) {
            int u, v;
            scanf("%d %d", &u, &v);
            D[u][v] = D[v][u] = 0;
        }
        bool ok = 0;
        priority_queue<PII> q;
        q.push(PII(dist[1] = 0,1));
        while (!q.empty()) {
            int u = q.top().second; q.pop();
            if (marc[u]) continue;
            marc[u] = 1;
            if (dist[u] != 0) printf("%d %d\n", pai[u], u), ok = 1;
            for (int i = 1; i <= N; i++) if (!marc[i])
                if (D[u][i] < dist[i]) {
                    pai[i] = u;
                    q.push(PII(-(dist[i] = D[u][i]), i));
                }
        }
        if (!ok) puts("No new highways need");
        if (T) putchar('\n');
    }

    return 0;
}
