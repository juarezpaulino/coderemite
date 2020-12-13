/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int M, N;
char B[150][150];
char V[150][150];

int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void DFS(int y, int x) {
    if (y < 0 || x < 0 || y >= M || x >= N || V[y][x] || B[y][x]=='*') return;
    V[y][x] = 1;
    for (int i = 0; i < 8; i++) DFS(y+dy[i], x+dx[i]);
}

int main() {

    while (scanf("%d %d ", &M, &N)) {
        if (!(M|N)) break;
        for (int i = 0; i < M; i++) gets(B[i]);
        memset(V,0,sizeof(V));
        int ret = 0;
        for (int i = 0; i < M; i++) for (int j = 0; j < N; j++)
            if (!V[i][j] && B[i][j]=='@') {
                DFS(i,j);
                ret++;
            }
        printf("%d\n", ret);
    }

    return 0;
}
