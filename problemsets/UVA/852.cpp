/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int B, W, C, b, w;
char M[10][10];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

void dfs(int y, int x) {
    M[y][x] = '#';
    C++;
    for (int i = 0; i < 4; i++) {
        int ny = y+dy[i], nx = x+dx[i];
        if (ny < 0 || nx < 0 || ny >= 9 || nx >= 9 || M[ny][nx]=='#') continue;
        if (M[ny][nx]=='X') b++;
        else if (M[ny][nx]=='O') w++;
        else if (M[ny][nx]=='.') dfs(ny,nx);
    }
}

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i < 9; i++) scanf("%s", M[i]);
        B = W = 0;
        for (int i = 0; i < 9; i++) for (int j = 0; j < 9; j++) {
            if (M[i][j]=='X') B++;
            else if (M[i][j]=='O') W++;
            else if (M[i][j]=='.') {
                C = b = w = 0;
                dfs(i,j);
                if (!w && b) B += C;
                if (w && !b) W += C;
            }
        }
        printf("Black %d White %d\n", B, W);
    }

    return 0;
}
