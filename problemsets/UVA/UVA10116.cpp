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

int M, N, C;
char MAPA[15][15];
int D[15][15];

int main() {

    while (scanf("%d %d %d", &M, &N, &C)) {
        if (!(M|N|C)) break;
        for (int i = 0; i < M; i++) scanf("%s", MAPA[i]);
        for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) D[i][j] = -1;
        int y = 0, x = C-1;
        int ret = 0;
        C = -1;
        while (1) {
            D[y][x] = ++ret;
            int ny = MAPA[y][x]=='N' ? y-1 : MAPA[y][x]=='S' ? y+1 : y;
            int nx = MAPA[y][x]=='W' ? x-1 : MAPA[y][x]=='E' ? x+1 : x;
            if (ny < 0 || nx < 0 || ny >= M || nx >= N) break;
            if (D[ny][nx] != -1) { C = ret-D[ny][nx]+1; ret = D[ny][nx]-1; break; }
            y = ny; x = nx;
        }
        if (C == -1) printf("%d step(s) to exit\n", ret);
        else printf("%d step(s) before a loop of %d step(s)\n", ret, C);
    }

    return 0;
}
