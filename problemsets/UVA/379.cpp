/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>

int UX[40], UY[40];
int V[10][10];

int dy[] = { 1, 0, 0, -1 };
int dx[] = { 0, 1, -1, 0 };

int main() {

    memset(UX, 0, sizeof(UX));
    memset(UY, 0, sizeof(UY));
    memset(V, 0, sizeof(V));

    int K = 1;
    for (int i = 0; i < 2; i++) for (int j = 2; j < 5; j++) UY[K] = i, UX[K] = j, V[i][j] = K++;
    for (int i = 2; i < 5; i++) for (int j = 0; j < 7; j++) UY[K] = i, UX[K] = j, V[i][j] = K++;
    for (int i = 5; i < 7; i++) for (int j = 2; j < 5; j++) UY[K] = i, UX[K] = j, V[i][j] = K++;

    printf("HI Q OUTPUT\n");
    int T;
    scanf("%d", &T);
    while (T--) {
        char MAPA[10][10] = { 0 };

        int x;
        while (scanf("%d", &x) != EOF) {
            if (!x) break;
            MAPA[UY[x]][UX[x]] = 1;
        }
        bool ok = 1;
        while (ok) {
            ok = 0;
            for (int k = 33; k >= 1 && !ok; k--) {
                int i = UY[k], j = UX[k];
                if (MAPA[i][j]) continue;
                for (int d = 0; d < 4; d++) {
                    int my = i+dy[d], mx = j+dx[d];
                    int ny = my+dy[d], nx = mx+dx[d];
                    if (my < 0 || mx < 0 || ny < 0 || nx < 0) continue;
                    if (!V[ny][nx]) continue;
                    if (!MAPA[my][mx] || !MAPA[ny][nx]) continue;
                    MAPA[my][mx] = MAPA[ny][nx] = 0;
                    MAPA[i][j] = 1;
                    ok = 1;
                    break;
                }
            }
        }
        int ret = 0;
        for (int k = 1; k < 34; k++) {
            int i = UY[k], j = UX[k];
            if (MAPA[i][j]) ret += k;
        }
        printf("%d\n", ret);
    }
    printf("END OF OUTPUT\n");

    return 0;
}
