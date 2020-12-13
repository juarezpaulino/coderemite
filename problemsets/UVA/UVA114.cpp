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
#include <numeric>

using namespace std;

int M, N, W;
int p, C[2510], V[2510];
int MAPA[55][55];

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

int main() {

    scanf("%d %d %d %d", &M, &N, &W, &p);
    for (int i = 1; i <= p; i++) {
        int x, y;
        scanf("%d %d %d %d", &x, &y, V+i, C+i);
        MAPA[y][x] = i;
    }
    int y, x, d, t;
    int ret = 0;
    while (scanf("%d %d %d %d", &x, &y, &d, &t) != EOF) {
        int tot = 0;
        while (t > 0) {
            int ny = y + dy[d];
            int nx = x + dx[d];
            t--;
            if (t==0) break;
            // Hit a wall.
            if (ny <= 1 || nx <= 1 || ny >= M || nx >= N) {
                t -= W;
                d = (d+3)%4;
                continue;
            }
            // Hit a bumper.
            if (MAPA[ny][nx]!=0) {
                tot += V[MAPA[ny][nx]];
                t -= C[MAPA[ny][nx]];
                d = (d+3)%4;
                continue;
            }
            // Just go on.
            y = ny; x = nx;
        }
        printf("%d\n", tot);
        ret += tot;
    }
    printf("%d\n", ret);

    return 0;
}
