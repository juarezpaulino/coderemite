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

struct node { int y, x, j, d; };

char M[1010][1010];
int vis[1010][1010], id = 1;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

int main() {

    int T;
    int R, C;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &R, &C);
        queue<node> q;
        int sy, sx;
        for (int i = 0; i < R; i++) {
            scanf("%s", M[i]);
            for (int j = 0; j < C; j++) {
                if (M[i][j]=='J') sy = i, sx = j, vis[i][j] = id;
                else if (M[i][j]=='F') q.push((node){i,j,0,0}), vis[i][j] = id;
            }
        }
        q.push((node){sy,sx,1,0});
        while (!q.empty()) {
            node u = q.front();
            int y = u.y, x = u.x, j = u.j, d = u.d;
            if (j && (u.y==0 || u.x==0 || u.y==R-1 || u.x==C-1)) {
                printf("%d\n", d+1);
                break;
            }
            q.pop();
            for (int i = 0; i < 4; i++) {
                int ny = y+dy[i], nx = x+dx[i];
                if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
                if (vis[ny][nx]==id) continue;
                if (M[ny][nx]=='#') continue;
                vis[ny][nx]=id;
                q.push((node){ny,nx,j,d+1});
            }
        }
        if (q.empty()) puts("IMPOSSIBLE");
        id++;
    }

    return 0;
}
