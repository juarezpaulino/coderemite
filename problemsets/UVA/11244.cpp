/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {

    int R, C;
    char MAPA[101][101];
    while (scanf("%d %d", &R, &C)) {
        if (!(R|C)) break;
        for (int i = 0; i < R; i++) scanf("%s", MAPA[i]);
        int ret = 0;
        int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) if (MAPA[i][j]=='*') {
            bool ok = 1;
            for (int k = 0; ok && k < 8; k++) {
                int ny = i+dy[k], nx = j+dx[k];
                if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
                if (MAPA[ny][nx]=='*') ok = 0;
            }
            if (ok) ret++;
        }
        printf("%d\n", ret);
    }

    return 0;
}
