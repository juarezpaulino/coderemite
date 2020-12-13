/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

char mapa[110][110];
int M, N;
int X, Y;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };
char cr;

int dfs(int y, int x) {
    int ret = 1;
    mapa[y][x] = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y+dy[i];
        int nx = (x+dx[i]+N) % N;
        if (ny < 0 || ny >= M) continue;
        if (mapa[ny][nx]==cr) ret += dfs(ny, nx);
    }
    return ret;
}

int main() {

    while (scanf("%d %d", &M, &N) != EOF) {
        for (int i = 0; i < M; i++) scanf("%s", mapa[i]);
        scanf("%d %d", &Y, &X);
        cr = mapa[Y][X];
        dfs(Y, X);
        int ret = 0;
        for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) if (mapa[i][j]==cr)
            ret = max(ret, dfs(i,j));
        printf("%d\n", ret);
    }

    return 0;
}
