/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>

using namespace std;

int M[100][100];
int V[100][100];
int R, C;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int DFS(int y, int x) {
    if (V[y][x]) return V[y][x];
    int ret = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y+dy[i], nx = x+dx[i];
        if (ny < 0 || nx < 0 || ny >= R || nx >= C || M[ny][nx] >= M[y][x]) continue;
        ret = max(ret, DFS(ny, nx));
    }
    return V[y][x] = ret+1;
}

int main() {

    char S[110];
    int T;
    scanf("%d", &T);
    while (T--) {
        int ret = 0;
        scanf("%s %d %d", S, &R, &C);
        for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) scanf("%d", &M[i][j]), V[i][j] = 0;
        for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) if (!V[i][j])
            ret = max(ret, DFS(i,j));
        printf("%s: %d\n", S, ret);
    }

    return 0;
}
