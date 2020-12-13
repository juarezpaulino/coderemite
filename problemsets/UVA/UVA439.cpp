/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int dy[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dx[] = { -1, 1, -2, 2, -2, 2, -1, 1 };

int M[8][8];

int y1, x1, y2, x2;

int BFS() {
    queue<pair<int, int> > q;
    q.push(make_pair(y1,x1));
    memset(M, -1, sizeof(M));
    M[y1][x1] = 0;
    while (!q.empty()) {
        int y = q.front().first, x = q.front().second;
        q.pop();
        if (y == y2 && x == x2) return M[y][x];
        for (int i = 0; i < 8; i++) {
            int ny = y+dy[i];
            int nx = x+dx[i];
            if (ny < 0 || nx < 0 || ny >= 8 || nx >= 8 || M[ny][nx] != -1) continue;
            M[ny][nx] = M[y][x]+1;
            q.push(make_pair(ny,nx));
        }
    }
    return -1;
}

int main() {

    char c1, c2;
    int r1, r2;
    while (scanf(" %c%d %c%d", &c1, &r1, &c2, &r2) != EOF) {
        y1 = r1-1, x1 = c1-'a',
        y2 = r2-1, x2 = c2-'a';
        int ret = BFS();
        printf("To get from %c%d to %c%d takes %d knight moves.\n", c1,r1,c2,r2,ret);
    }

    return 0;
}
