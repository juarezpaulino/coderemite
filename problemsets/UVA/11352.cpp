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
char M[110][110];
int D[110][110];

int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int ddy[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int ddx[] = { -1, 1, -2, 2, -2, 2, -1, 1 };

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &R, &C);
        for (int i = 0; i < R; i++) scanf("%s", M[i]);
        int sy, sx;
        for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) {
            if (M[i][j]=='A') sy = i, sx = j;
            D[i][j]=-1;
        }
        queue<int> qy, qx;
        qy.push(sy); qx.push(sx);
        D[sy][sx] = 0;
        bool ok = 0;
        while (!qx.empty()) {
            int y = qy.front(), x = qx.front();
            qy.pop(); qx.pop();
            if (M[y][x]=='B') {
                ok = 1;
                printf("Minimal possible length of a trip is %d\n", D[y][x]);
                break;
            }
            for (int i = 0; i < 8; i++) {
                int ny = y+dy[i], nx = x+dx[i];
                if (ny < 0 || nx < 0 || ny >= R || nx >= C || M[ny][nx]=='Z' || D[ny][nx]!=-1) continue;
                bool ok = 1;
                for (int j = 0; M[ny][nx]!='B' && j < 8; j++) {
                    int zy = ny+ddy[j], zx = nx+ddx[j];
                    if (zy < 0 || zx < 0 || zy >= R || zx >= C) continue;
                    if (M[zy][zx]=='Z') { ok = 0; break; }
                }
                if (ok) {
                    D[ny][nx] = D[y][x]+1;
                    qy.push(ny); qx.push(nx);
                }
            }
        }
        if (!ok) puts("King Peter, you can't go now!");
    }

    return 0;
}
