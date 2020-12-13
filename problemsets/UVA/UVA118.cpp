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

char MAPA[100][100];

int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };
char dir[] = "NESW";

int main() {

    int y, x, d;
    char S[150], c;
    scanf("%d %d", &N, &M);
    N++; M++;
    while (scanf("%d %d %c ", &x, &y, &c) != EOF) {
        d = (c=='N') ? 0 : (c=='E') ? 1 : (c=='S') ? 2 : 3;
        gets(S);
        int i;
        for (i = 0; S[i]; i++) {
            if (S[i]=='R') d = (d+1)%4;
            else if (S[i]=='L') d = (d+3)%4;
            else {
                int ny = y+dy[d];
                int nx = x+dx[d];
                if (ny < 0 || nx < 0 || ny >= M || nx >= N) {
                    if (MAPA[y][x]) continue;
                    printf("%d %d %c LOST\n", x, y, dir[d]);
                    MAPA[y][x] = 1;
                    break;
                }
                y = ny; x = nx;
            }
        }
        if (!S[i]) printf("%d %d %c\n", x, y, dir[d]);
    }

    return 0;
}
