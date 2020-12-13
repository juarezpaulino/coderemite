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

int T, N;
char M[110][110];
int d;

int dy[] = { 1, 0 };
int dx[] = { 0, 1 };

void DFS(int y, int x, int d) {
    M[y][x] = '@';
    int ny = y+dy[0], nx = x+dx[0];
    if (d <= 0 && ny >= 0 && nx >= 0 && ny < N && nx < N && M[ny][nx]!='.'){
        DFS(ny,nx,0);
        return;
    }
    ny = y+dy[1], nx = x+dx[1];
    if ((d == 1 || d == -1) && ny >= 0 && nx >= 0 && ny < N && nx < N && M[ny][nx]!='.'){
        DFS(ny,nx,1);
        return;
    }
}

int main() {

    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d ", &N);
        int ret = 0;
        for (int i = 0; i < N; i++) gets(M[i]);
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (M[i][j]=='x') {
            DFS(i,j,-1);
            ret++;
        }
        printf("Case %d: %d\n", t, ret);
    }

    return 0;
}
