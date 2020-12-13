/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <sstream>

using namespace std;

int N;
int M[110][110];
int ret, ok;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

void dfs(int r, int c) {
    ret++;
    int v = M[r][c];
    M[r][c]+=N;
    for (int i = 0; i < 4; i++) {
        int y = r+dy[i];
        int x = c+dx[i];
        if (y <= 0 || y > N || x <= 0 || x > N || M[y][x] != v) continue;
        dfs(y,x);
    }
}

char S[101010];

int main() {

    while (scanf("%d ", &N) != EOF) {
        if (!N) break;
        for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) M[i][j] = 0;
        for (int i = 1; i < N; i++) {
            gets(S);
            istringstream is(S);
            int r, c;
            while (is >> r >> c) M[r][c] = i;
        }
        ok = 1;
        for (int i = 1; ok && i <= N; i++) for (int j = 1; ok && j <= N; j++) if (M[i][j] < N) {
            ret = 0;
            dfs(i,j);
            if (ret != N) ok = 0;
        }
        if (ok) puts("good");
        else puts("wrong");
    }

    return 0;
}
