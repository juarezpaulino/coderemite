/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int T, R, C;
char S[1000];
char mat[50][50];
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

string binary(int v, int M) {
    string ret;
    // while (v) { ret+='0'+(v%2); v/=2; }
    for (int i = 0; i < M; i++) { ret+='0'+(v%2); v/=2; }
    reverse(ret.begin(), ret.end()); return ret;
}

int main() {

    int id = 1;
    scanf("%d", &T);
    while (T--) {

        scanf("%d%*c%d%*c", &R, &C);
        gets(S);
        int d = 0, y = 0, x = 0;
        memset(mat,0,sizeof(mat));
        for (int i = 0; S[i]; i++) {
            int k = (S[i]==' ') ? 0 : S[i]-'A'+1;
            string F = binary(k, 5);
            for (int j = 0; j < 5; j++) {
                mat[y][x] = F[j];
                int ny = y+dy[d], nx = x+dx[d];
                if (ny >= R || nx >= C || ny < 0 || nx < 0 || mat[ny][nx]) {
                    d = (d+1)%4; ny = y+dy[d]; nx = x+dx[d];
                }
                y = ny; x = nx;
            }
        }
        for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) if (!mat[i][j]) mat[i][j] = '0';

        printf("%d ", id);
        for (int i = 0; i < R; i++) printf("%s", mat[i]);
        putchar('\n');
        id++;
    }

    return 0;
}
