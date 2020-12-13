/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;

char vis[40][100];
char A[40][100];
int M, N;
int sy, sx;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

void dfs(int y, int x) {
    vis[y][x] = 1;
    bool ok = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y+dy[i], nx = x+dx[i];
        if (ny < 0 || nx < 0 || ny >= M || nx > N || vis[ny][nx]) continue;
        if (A[ny][nx]!=' ' && A[ny][nx]!='#' && A[ny][nx]!='_' && A[ny][nx]!='*') ok = 1;
        if (A[ny][nx]==' ') dfs(ny,nx);
    }
    if (ok) A[y][x] = '#';
}


int main() {

    char S[1010]; gets(S);
    int T = atoi(S);
    while (T--) {
        M = N = 0;
        memset(A, 0, sizeof(A));
        memset(vis, 0, sizeof(vis));
        while (gets(A[M])) {
            bool ok = 0;
            int i;
            for (i = 0; A[M][i]; i++) {
                if (A[M][i] != '_') ok = 1;
                if (A[M][i] == '*') sy = M, sx = i;
            }
            N = max(N,i);
            if (i && !ok) break;
            M++;
        }
        for (int i = 0; i < M; i++)
            for (int j = 0; j <= N; j++)
                if (!A[i][j]) A[i][j] = ' ';
        A[sy][sx] = ' ';
        dfs(sy,sx);
        for (int i = 0; i < M; i++) {
            for (int j = N; j >= 0; j--) {
                if (A[i][j]==' ') A[i][j] = 0;
                else break;
            }
        }
        for (int i = 0; i <= M; i++) puts(A[i]);
    }

    return 0;
}
