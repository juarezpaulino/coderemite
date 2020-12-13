/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int H[25][25][4][5];
int M, N;
char MAPA[30][30];
int sx,sy,tx,ty;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int id = 1;

struct node { int y, x, d, c, v; };

int main() {

    bool first = 1;
    while (scanf("%d %d ", &M, &N)) {
        if (!(M|N)) break;

        if (!first) putchar('\n');
        first = 0;

        for (int i = 0; i < M; i++) {
            gets(MAPA[i]);
            for (int j = 0; j < N; j++)
                if (MAPA[i][j]=='S') { sy = i, sx = j; }
                else if (MAPA[i][j]=='T') { ty = i, tx = j; }
        }

        queue<node> q;
        q.push((node){sy,sx,0,0,0});
        H[sy][sx][0][0] = id;

        int ret = -1;
        while (!q.empty()) {
            node u = q.front(); q.pop();
            if (u.y == ty && u.x == tx && u.c == 0) { ret = u.v; break; }
            {
                node v = (node){u.y+dy[u.d], u.x+dx[u.d], u.d, (u.c+1)%5, u.v+1};
                if (v.y >= 0 && v.x >= 0 && v.y < M && v.x < N &&
                    MAPA[v.y][v.x] != '#' &&
                    H[v.y][v.x][v.d][v.c] != id) {
                    H[v.y][v.x][v.d][v.c] = id;
                    q.push(v);
                }
            }
            {
                node v = (node){u.y, u.x, (u.d+1)%4, u.c, u.v+1};
                if (H[v.y][v.x][v.d][v.c] != id) {
                    H[v.y][v.x][v.d][v.c] = id;
                    q.push(v);
                }
            }
            {
                node v = (node){u.y, u.x, (u.d+3)%4, u.c, u.v+1};
                if (H[v.y][v.x][v.d][v.c] != id) {
                    H[v.y][v.x][v.d][v.c] = id;
                    q.push(v);
                }
            }
        }

        printf("Case #%d\n", id++);
        if (ret == -1) puts("destination not reachable");
        else printf("minimum time = %d sec\n", ret);
    }


    return 0;
}
