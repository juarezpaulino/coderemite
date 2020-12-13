/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int W, H;
char MAPA[101][101];
int ret;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void dfs2(int y, int x) {
    MAPA[y][x] = '*';
    for (int i = 0; i < 4; i++) {
        int ny = y+dy[i], nx = x+dx[i];
        if (ny < 0 || nx < 0 || ny >= H || nx >= W || MAPA[ny][nx]!='X') continue;
        dfs2(ny,nx);
    }
}

void dfs(int y, int x) {
    if (MAPA[y][x]=='X') { ret++; dfs2(y,x); }
    MAPA[y][x] = '.';
    for (int i = 0; i < 4; i++) {
        int ny = y+dy[i], nx = x+dx[i];
        if (ny < 0 || nx < 0 || ny >= H || nx >= W || MAPA[ny][nx]=='.') continue;
        dfs(ny,nx);
    }
}

int main() {

    int T = 1;
    while (scanf("%d %d", &W, &H)) {
        if (!(W|H)) break;
        for (int i = 0; i < H; i++) scanf("%s", MAPA[i]);
        vector<int> RET;
        for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) if (MAPA[i][j]!='.') {
            ret = 0; dfs(i,j); RET.push_back(ret);
        }
        sort(RET.begin(), RET.end());
        printf("Throw %d\n", T++);
        printf("%d", RET[0]);
        for (int i = 1; i < RET.size(); i++) printf(" %d", RET[i]);
        putchar('\n');
        putchar('\n');
    }

    return 0;
}
