/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int mapa[1010][1010];


int main() {

    int N, M;
    while (scanf("%d %d", &N, &M) != EOF) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                scanf("%d", &mapa[i][j]);
        int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1};
        int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1};
        bool ok = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) {
                bool c = 1;
                for (int k = 0; k < 8; k++) {
                    int u = i+dy[k], v = j+dx[k];
                    if (u >= 0 && u < N && v >= 0 && v < M && mapa[i][j] <= mapa[u][v]) {
                        c = 0;
                        break;
                    }
                }
                if (c) printf("%d %d\n", i+1, j+1), ok = 1;
            }
        if (!ok) puts("-1");
        putchar('\n');
    }

    return 0;
}
