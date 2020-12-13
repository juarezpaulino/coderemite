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

char MAPA[100][100];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int M;

void DFS(int y, int x) {
    MAPA[y][x] = '#';
    for (int i = 0; i < 4; i++) {
        int ny = y+dy[i], nx = x+dx[i];
        if (MAPA[ny][nx]!=' ' && MAPA[ny][nx]!='*' && MAPA[ny][nx]!='_') continue;
        DFS(ny,nx);
    }
}

int main() {

    int T;
    scanf("%d ", &T);
    while (T--) {
        int y, x;
        M = 0;
        while (gets(MAPA[M])) {
            bool out = true;
            for (int i = 0; MAPA[M][i]; i++) {
                if (MAPA[M][i]!='_') { out = false; }
                if (MAPA[M][i]=='*') y = M, x = i;
            }
            M++;
            if (out) break;
        }
        DFS(y,x);
        for (int i = 0; i < M; i++) puts(MAPA[i]);
    }

    return 0;
}
