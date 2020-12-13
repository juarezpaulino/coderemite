/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

struct node {
    int u, h, d, t;
    bool operator<(const node &B) const {
        if (t != B.t) return t > B.t;
        return u < B.u;
    }
};

char M[1010];
int D[1010][24][17];
char marc[1010][24][17];

int main() {

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%s", M);
        int N = strlen(M);
        for (int i = 0; i < N; i++) for (int j = 0; j < 24; j++) for (int k = 0; k < 17; k++)
            D[i][j][k] = 1<<30, marc[i][j][k] = 0;
        printf("Case #%d: ", t);
        queue<node> q;
        q.push((node){0,0,0,D[0][0][0]=0});
        marc[0][0][0] = 1;
        int ret = -1;
        while (!q.empty()) {
            int u = q.front().u, h = q.front().h, d = q.front().d, t = q.front().t;
            q.pop();
            if (u == N-1) { ret = t; break; }
//            if (marc[u][h][d]) continue;
//            marc[u][h][d] = 1;
            int h1 = (h+1)%24, h2 = (h+8)%24;
//            if (M[u]=='*' && h1 < 1 || h1 > 11) continue;
            if (d+1 < 17 && (M[u+1]!='*' || (1 <= h1 && h1 <= 11))) {
                if (!marc[u+1][h1][d+1]) {
//                if (D[u+1][h1][d+1] > D[u][h][d]+1) {
                    q.push((node){u+1,h1,d+1,D[u+1][h1][d+1]=D[u][h][d]+1});
                    marc[u+1][h1][d+1] = 1;
                }
            }
            if (M[u]!='*' || (1 <= h2 && h2 <= 11)) {
                if (!marc[u][h2][0]) {
//                if (D[u][h2][0] > D[u][h][d]+8) {
                    q.push((node){u,h2,0,D[u][h2][0]=D[u][h][d]+8});
                    marc[u][h2][0] = 1;
                }
            }
        }
        if (ret == -1) puts("-1");
        else printf("%d\n", ret);
    }

    return 0;
}
