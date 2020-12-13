/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

struct node { int y, x, o; };

int N, M;
char MAPA[110][110];
int DIST[2][110][110];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int BFS(int y, int x) {
    int o;
    memset(DIST,-1,sizeof(DIST));
    DIST[0][y][x] = 1;
    queue<node> q;
    q.push((node){y,x,0});
    while (!q.empty()) {
        y = q.front().y, x = q.front().x, o = q.front().o;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k], nx = x + dx[k], no = o;;
            if (ny < 0 || ny >= M || nx < 0 || nx >= N) return DIST[o][y][x];
            if (MAPA[ny][nx]=='W' || (MAPA[ny][nx]=='D' && !o)) continue;
            if (MAPA[ny][nx]=='O') no = 1;
            if (MAPA[ny][nx]=='C') no = 0;
            if (DIST[no][ny][nx] != -1) continue;
            DIST[no][ny][nx] = DIST[o][y][x]+1;
            q.push((node){ny,nx,no});
        }
    }
    return -1;
}


int main() {

    int y = 0, x = 0;

    while (1) {
        scanf("%d %d",  &M, &N);
        if (M <= 0 && N <= 0) break;
        for (int i = 0; i < M; i++) scanf("%s", MAPA[i]);

        for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) if (MAPA[i][j]=='H') y = i, x = j;
        int ret = BFS(y, x);
        printf("%d\n", ret);
    }

    return 0;
}
