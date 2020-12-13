/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {

    char MAPA[15][15], P[15][15];
    int T, N;
    scanf("%d ", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) scanf("%s", MAPA[i]);
        for (int i = 0; i < N; i++) scanf("%s", P[i]);
        bool ok = 1;
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
            if (P[i][j]=='.' && MAPA[i][j]=='.') continue;
            else if (P[i][j]=='.' && MAPA[i][j]=='*') continue;
            else if (P[i][j]=='x' && MAPA[i][j]=='*') ok = 0;
            else {
                int c = 0;
                for (int k = 0; k < 8; k++) {
                    int ny = i+dy[k], nx = j+dx[k];
                    if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                    if (MAPA[ny][nx]=='*') c++;
                }
                P[i][j] = '0'+c;
            }
        }
        if (!ok) for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (MAPA[i][j]=='*') P[i][j] = '*';
        for (int i = 0; i < N; i++) puts(P[i]);
        if (T) putchar('\n');
    }

    return 0;
}
