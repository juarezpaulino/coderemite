/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int R, C;
int D[330][330][3];
char M[330][330];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &R, &C);
        for (int i = 0; i < R; i++) scanf("%s", M[i]);
        int sy, sx;
        for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) {
            if (M[i][j]=='S') sy = i, sx = j;
            for (int k = 0; k < 3; k++) D[i][j][k] = -1;
        }
        bool ok = 0;
        queue<int> qx, qy, qm;
        qx.push(sx); qy.push(sy); qm.push(2);
        D[sy][sx][2] = 0;
        while (!qx.empty()) {
            int x = qx.front(), y = qy.front(), m = qm.front();
            qx.pop(); qy.pop(); qm.pop();
            if (M[y][x]=='E') {
                ok = 1;
                printf("%d\n", D[y][x][m]);
                break;
            }
            for (int i = 0; i < 4; i++) {
                int mm = (m+1)%3, ny = y, nx = x;
                bool ok = 1;
                for (int j = 0; j <= mm; j++) {
                    ny = ny+dy[i], nx = nx+dx[i];
                    if (ny < 0 || nx < 0 || ny >= R || nx >= C || M[ny][nx]=='#') { ok = 0; break; }
                }
                if (!ok) continue;
                if (D[ny][nx][mm]==-1) {
                    qx.push(nx); qy.push(ny); qm.push(mm);
                    D[ny][nx][mm] = D[y][x][m]+1;
                }
            }
        }
        if (!ok) puts("NO");
    }

    return 0;
}
