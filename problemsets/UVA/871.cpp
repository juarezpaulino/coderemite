/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int M, N;
int T, ret, v;
char A[30][30];

int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1};
int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1};

void dfs(int y, int x) {
    v++;
    A[y][x] = '0';
    for (int i = 0; i < 8; i++) {
        int ny = y+dy[i],
            nx = x+dx[i];
        if (ny < 0 || nx < 0 || ny >= M || nx >= N || A[ny][nx]!='1') continue;
        dfs(ny,nx);
    }
}


int main() {

    scanf("%d ", &T);
    while (T--) {
        M = 0;
        while (gets(A[M])) {
            if (*A[M]==0) break;
            M++;
        }
        N = strlen(A[0]);
        int ret = 0;
        for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) {
            v = 0;
            if (A[i][j]=='1') dfs(i,j);
            ret = max(ret, v);
        }
        printf("%d\n", ret);
        if (T) putchar('\n');
    }

    return 0;
}
