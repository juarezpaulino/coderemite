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

char V[30][30];
char M[30][30];
int N;

int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void DFS(int y, int x) {
    V[y][x] = 1;
    for (int i = 0; i < 8; i++) {
        int ny = y+dy[i],
            nx = x+dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= N || V[ny][nx] || M[ny][nx]=='0') continue;
        DFS(ny,nx);
    }
}

int main() {

    int T = 1;

    while (scanf("%d", &N) != EOF) {
        memset(V, 0, sizeof(V));
        for (int i = 0; i < N; i++) scanf("%s", M[i]);
        int ret = 0;
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (!V[i][j] && M[i][j]=='1')
            DFS(i,j), ret++;
        printf("Image number %d contains %d war eagles.\n", T++, ret);
    }

    return 0;
}
