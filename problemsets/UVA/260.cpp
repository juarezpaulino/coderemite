/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <algorithm>

using namespace std;

int N;
char M[202][202];
char W;

int dy[] = {-1,-1,0,0,1,1};
int dx[] = {-1,0,-1,1,0,1};

void dfs(int r, int c, char v) {
    char u = M[r][c];
    M[r][c] = 0;
    if (v=='W' && c==N-1) { W = v; return; }
    if (v=='B' && r==N-1) { W = v; return; }
    for (int i = 0; i < 6; i++) {
        int y = r + dy[i];
        int x = c + dx[i];
        if (y < 0 || y >= N || x < 0 || x >= N) continue;
        if (M[y][x]==u) dfs(y,x,v);
    }
}

int main() {

    int id = 1;
    while (1) {
        scanf("%d ", &N);
        if (!N) break;
        for (int i = 0; i < N; i++) gets(M[i]);
        for (int i = 0; i < N; i++) if (M[i][0]=='w') dfs(i,0,'W');
        for (int j = 0; j < N; j++) if (M[0][j]=='b') dfs(0,j,'B');
        printf("%d %c\n", id++, W);
    }

    return 0;
}
