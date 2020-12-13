/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>
#include <queue>
#include <cstring>
#include <map>

using namespace std;

typedef pair<int,int> PII;

int m, S;
int M[2][50];
int C[303][303];
int ret;

const int INF = 0x3F3F3F3F;

void bfs() {
    int S2 = S*S;
    for (int i = 0; i <= S; i++) for (int j = 0; j <= S; j++) C[i][j] = INF;
    C[0][0] = 0;
    queue<PII> q;
    q.push(PII(0,0));
    while (!q.empty()) {
        PII u = q.front(); q.pop();
        int u1 = u.first, u2 = u.second;
        for (int i = 0; i < m; i++) {
            int x = u1 + M[0][i], y = u2 + M[1][i];
            int v = x*x + y*y;
            if (v <= S2 && C[u1+M[0][i]][u2+M[1][i]] >= INF) {
                if (v == S2) ret = min(ret, C[u1][u2]+1);
                C[u1+M[0][i]][u2+M[1][i]] = C[u1][u2]+1;
                q.push(PII(u1+M[0][i],u2+M[1][i]));
            }
        }
    }
}

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &m, &S);
        for (int i = 0; i < m; i++) scanf("%d %d", &M[0][i], &M[1][i]);
        ret = INF; bfs();
        if (ret == INF) puts("not possible");
        else printf("%d\n", ret);
    }

    return 0;
}
