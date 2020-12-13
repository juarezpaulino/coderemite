/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>

using namespace std;

char S[1010];
char mapa[33][33];

int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int main() {

    int T, Y;
    scanf("%d ", &T);
    while (T--) {
        puts("********************");
        gets(S);
        int cur = 0;
        char mapa[2][25][25];
        for (int k = 0; k < 2; k++) for (int i = 0; i < 25; i++) for (int j = 0; j < 25; j++) mapa[k][i][j] = ' ';
        sscanf(S, "%d", &Y);
        while (gets(S)) {
            if (!*S) break;
            int y, x;
            sscanf(S, "%d %d", &y, &x);
            mapa[cur][y][x] = 'O';
        }
        while (Y--) {
            int nxt = 1-cur;
            for (int i = 1; i <= 20; i++, putchar('\n'))
                for (int j = 1; j <= 20; j++)
                    putchar(mapa[cur][i][j]);
            if (Y) for (int i = 1; i <= 20; i++) for (int j = 1; j <= 20; j++) {
                int viz = 0;
                for (int k = 0; k < 8; k++) {
                    int ny = i+dy[k], nx = j+dx[k];
                    if (mapa[cur][ny][nx]=='O') viz++;
                }
                mapa[nxt][i][j] = mapa[cur][i][j];
                if (mapa[cur][i][j]=='O') {
                    if (viz<2||viz>3) mapa[nxt][i][j] = ' ';
                }
                else if (viz==3) mapa[nxt][i][j] = 'O';
            }
            cur = nxt;
            puts("********************");
        }
        if (T) putchar('\n');
    }

    return 0;
}
