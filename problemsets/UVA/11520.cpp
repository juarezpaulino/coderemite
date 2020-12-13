/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>


using namespace std;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1};

int main() {

    int T;
    char M[20][20];
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        printf("Case %d:\n", t);
        int N;
        scanf("%d ", &N);
        for (int i = 0; i < N; i++) scanf("%s", M[i]);
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
            if (M[i][j]=='.') for (char c = 'A'; c <= 'Z'; c++) {
                bool ok = 1;
                for (int k = 0; k < 4; k++) {
                    int ny = i+dy[k], nx = j+dx[k];
                    if (ny >= 0 && nx >= 0 && ny < N && nx < N) {
                        if (M[ny][nx]==c) { ok = 0; break; }
                    }
                }
                if (ok) { M[i][j] = c; break; }
            }
        }
        for (int i = 0; i < N; i++) puts(M[i]);
    }
    return 0;
}
