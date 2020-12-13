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

char G[] = "@IEHOVA#";
char dy[] = {-1,0,0};
char dx[] = {0,-1,1};
char C[][10] = {"forth", "left", "right"};

int main() {

    char MAPA[10][10];
    int T;
    scanf("%d", &T);
    while (T--) {
        int M, N;
        scanf("%d %d", &M, &N);
        for (int i = 0; i < M; i++) scanf("%s", MAPA[i]);
        int y = -1, x = -1;
        for (int j = 0; j < N; j++) if (MAPA[M-1][j]=='@') { y = M-1, x = j; break; }
        for (int k = 1; k < 8; k++) {
            for (int i = 0; i < 3; i++) {
                int ny = y+dy[i], nx = x+dx[i];
                if (ny < 0 || ny >= M || nx < 0 || nx >= N || MAPA[ny][nx]!=G[k]) continue;
                x = nx, y = ny;
                if (k > 1) printf(" %s", C[i]);
                else printf("%s", C[i]);
            }
        }
        putchar('\n');
    }

    return 0;
}
