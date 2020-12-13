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

struct node { int y, x, d; };

int vis[2020][2020], target[2020][2020], id = 1;
int miny, minx, maxy, maxx;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

int main() {

    int P1, P2;
    while (scanf("%d", &P1) && P1) {
        queue<node> q;
        miny = minx = 1<<30;
        maxy = maxx = -1;
        for (int i = 0; i < P1; i++) {
            int y, x;
            scanf("%d %d", &y, &x);
            miny = min(miny, max(0,y-1));
            minx = min(minx, max(0,x-1));
            maxy = max(maxy, min(2000,y+1));
            maxx = max(maxx, min(2000,x+1));
            q.push((node){y,x,0});
            vis[y][x] = id;
        }
        scanf("%d", &P2);
        for (int i = 0; i < P2; i++) {
            int y, x;
            scanf("%d %d", &y, &x);
            miny = min(miny, max(0,y-1));
            minx = min(minx, max(0,x-1));
            maxy = max(maxy, min(2000,y+1));
            maxx = max(maxx, min(2000,x+1));
            target[y][x] = id;
        }
        while (!q.empty()) {
            node u = q.front(); q.pop();
            int y = u.y, x = u.x, d = u.d;
            if (target[y][x]==id) { printf("%d\n", d); break; }
            for (int i = 0; i < 4; i++) {
                int ny = y+dy[i], nx = x+dx[i];
                if (ny < miny || nx < minx || ny > maxy || nx > maxx) continue;
                if (vis[ny][nx]==id) continue;
                vis[ny][nx]=id;
                q.push((node){ny,nx,d+1});
            }
        }
        id++;
    }

    return 0;
}
