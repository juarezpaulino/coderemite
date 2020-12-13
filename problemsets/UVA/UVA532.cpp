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

int L, R, C;
char MAPA[50][50][50];

int dy[] = { -1, 0, 1, 0, 0, 0 };
int dx[] = { 0, 1, 0, -1, 0, 0 };
int dz[] = { 0, 0, 0, 0, -1, 1 };

int sx, sy, sz;
int tx, ty, tz;

struct Node { int z, y, x, d; };

int main() {

    while (scanf("%d %d %d", &L, &R, &C)) {
        if (!(L|R|C)) break;
        for (int k = 0; k < L; k++) for (int i = 0; i < R; i++) scanf("%s", MAPA[k][i]);
        for (int k = 0; k < L; k++) for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) {
            if (MAPA[k][i][j]=='S') sz = k, sy = i, sx = j;
            if (MAPA[k][i][j]=='E') tz = k, ty = i, tx = j;
        }
        queue<Node> q;
        q.push((Node){sz, sy, sx, 0});
        MAPA[sz][sy][sx] = '#';
        int z, y, x, d;
        while (!q.empty()) {
            z = q.front().z, y = q.front().y, x = q.front().x, d = q.front().d;
            q.pop();
            if (z==tz && y==ty && x==tx) break;
            for (int i = 0; i < 6; i++) {
                int nz = z+dz[i], ny = y+dy[i], nx = x+dx[i];
                if (nz >= 0 && nz < L && ny >= 0 && ny < R && nx >= 0 && nx < C && MAPA[nz][ny][nx]!='#')
                    MAPA[nz][ny][nx] = '#',
                    q.push((Node){nz,ny,nx,d+1});
            }
        }
        if (z==tz && y==ty && x==tx) printf("Escaped in %d minute(s).\n", d);
        else puts("Trapped!");
    }

    return 0;
}
