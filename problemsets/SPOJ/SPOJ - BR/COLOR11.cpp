/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int N, M, X, Y, K, ret;
char MAPA[300][300];

int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(int x, int y) {
    MAPA[x][y] = 1;
    ret++;
    for (int i = 0; i < 8; i++) {
        int ny = y+dy[i];
        int nx = x+dx[i];
        if (nx < 0 || ny < 0 || nx >= N || ny >= M || MAPA[nx][ny]) continue;
        dfs(nx, ny);
    }
}

int main() {

    scanf("%d %d %d %d %d", &N, &M, &X, &Y, &K);
    for (int i = 0; i < K; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        MAPA[x-1][y-1] = 2;
    }
    dfs(X-1, Y-1);
    printf("%d\n", ret);

    return 0;
}
