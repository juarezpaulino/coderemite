/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

char MAPA[101][101];
char C[1010];
int T, M, N;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
char V[] = "NESW";

int main() {

    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &M, &N); getchar();
        for (int i = 0; i < M; i++) gets(MAPA[i]);
        int y, x, d = 0;
        scanf("%d %d", &y, &x);
        y--; x--;
        bool ok = 1;
        while (ok && scanf("%s", C)) {
            for (int i = 0; ok && C[i]; i++) {
                if (C[i]=='Q') ok = 0;
                else if (C[i]=='F') {
                    int ny = y + dy[d], nx = x + dx[d];
                    if (ny < 0 || nx < 0 || ny >= M || nx >= N || MAPA[ny][nx]=='*') continue;
                    y = ny; x = nx;
                }
                else if (C[i]=='R') d = (d+1)%4;
                else if (C[i]=='L') d = (d+3)%4;
            }
        }
        printf("%d %d %c\n", y+1, x+1, V[d]);
        if (T) putchar('\n');
    }

    return 0;
}
