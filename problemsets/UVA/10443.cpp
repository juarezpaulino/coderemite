/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>

using namespace std;

int R, C, N;
char M[110][110], M2[110][110];
char D[256];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

int main() {

    D['R'] = 'P';
    D['P'] = 'S';
    D['S'] = 'R';
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &R, &C, &N);
        for (int i = 0; i < R; i++) scanf("%s", M[i]);
        while (N--) {
            for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) {
                int v = D[M[i][j]];
                bool ok = 0;
                for (int k = 0; !ok && k < 4; k++) {
                    int ny = i+dy[k], nx = j+dx[k];
                    if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
                    if (M[ny][nx]==v) ok = 1;
                }
                if (ok) M2[i][j] = v;
                else M2[i][j] = M[i][j];
            }
            memcpy(M, M2, sizeof(M));
        }
        for (int i = 0; i < R; i++) puts(M[i]);
        if (T) putchar('\n');
    }

    return 0;
}
