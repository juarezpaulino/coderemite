/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <queue>
#include <map>

using namespace std;

int N;
char M[101][101];
char c;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void dfs(int y, int x, char v) {
    M[y][x] = v;
    for (int i = 0; i < 4; i++) {
        int ny = y+dy[i], nx = x+dx[i];
        if (ny < 0 || nx < 0 || ny >= N || !M[ny][nx]) continue;
        if (M[ny][nx]==' ') dfs(ny,nx,v);
    }
}


int main() {

    while (1) {
        N = 0;
        queue<pair<int,int> > q;
        while (1) {
            if (!gets(M[N])) return 0;
            if (M[N][0]=='_') break;
            if (N == 0) for (int i = 0; M[0][i]; i++) {
                if (M[0][i]!=' ') { c = M[0][i]; break; }
            }
            for (int i = 0; M[N][i]; i++) if (M[N][i]!=' ' && M[N][i]!=c)
                q.push(make_pair(N,i));
            N++;
        }
        while (!q.empty()) {
            int y = q.front().first, x = q.front().second; q.pop();
            dfs(y, x, M[y][x]);
        }
        for (int i = 0; i <= N; i++) printf("%s\n", M[i]);
    }

    return 0;
}
