/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

char px[10][10], py[10][10], p[10][10];
char vis[10][10];
int X[6], Y[6];
int sx, sy, tx, ty;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };
char dir[] = "NWSE";

int main() {

    while (scanf("%d %d", &sx, &sy)!=EOF && (sx|sy)) {
        scanf("%d %d", &tx, &ty);
        for (int i = 0; i < 6; i++) scanf("%d %d", X+i, Y+i);
        memset(vis,0,sizeof(vis));
        queue<int> qx, qy;
        qx.push(sx); qy.push(sy);
        vis[sy][sx] = 1;
        while (!qx.empty()) {
            int x = qx.front(), y = qy.front();
            qx.pop(); qy.pop();
            if (x == tx && y == ty) break;
            for (int i = 0; i < 4; i++) {
                int nx = x+dx[i], ny = y+dy[i];
                if (nx < 1 || ny < 1 || nx > 6 || ny > 6) continue;
                if (vis[ny][nx]) continue;
                bool ok = 1;
                for (int j = 0; j < 6; j+=2) {
                    if (X[j]==X[j+1]) {
                        if (dy[i] != 0) continue;
                        int miny = min(Y[j], Y[j+1]);
                        int maxy = max(Y[j], Y[j+1]);
                        int minx = min(x,nx);
                        if (miny+1 <= y && y <= maxy && minx==X[j]) ok = 0;
                    }
                    else {
                        if (dx[i] != 0) continue;
                        int minx = min(X[j], X[j+1]);
                        int maxx = max(X[j], X[j+1]);
                        int miny = min(y,ny);
                        if (minx+1 <= x && x <= maxx && miny==Y[j]) ok = 0;
                    }
                }
                if (ok) {
                    qx.push(nx); qy.push(ny);
                    px[ny][nx]=x; py[ny][nx]=y; p[ny][nx] = dir[i];
                    vis[ny][nx] = 1;
                }
            }
        }
        string ret = "";
        int y = ty, x = tx;
        while (y!=sy || x!=sx) {
            ret += p[y][x];
            int ny = py[y][x], nx = px[y][x];
            y = ny; x = nx;
        }
        reverse(ret.begin(), ret.end());
        printf("%s\n", ret.c_str());
    }

    return 0;
}
