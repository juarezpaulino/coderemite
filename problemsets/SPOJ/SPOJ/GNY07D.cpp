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
char S[1000]; int ns;
char mat[50][50];
char F[50][50];
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

int decode(char *S, int M) {
    int ret = 0;
    for (int i = 0; i < M; i++) ret = ret*2 + S[i]-'0';
    return ret;
}

int main() {

    int id = 1;
    scanf("%d", &T);
    while (T--) {

        scanf("%d%*c%d%*c", &R, &C);
        gets(S);
        int d = 0, y = 0, x = 0;
        for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) mat[i][j] = S[i*C + j];
        memset(F,0,sizeof(F));
        char D[10]; int nd = 0;
        ns = 0;
        while (!F[y][x]) {
            F[y][x] = 1;
            D[nd++] = mat[y][x];
            if (nd >= 5) {
                S[ns] = decode(D, 5) - 1 + 'A';
                if (S[ns] < 'A') S[ns] = ' ';
                ns++;
                nd = 0;
            }
            int ny = y+dy[d], nx = x+dx[d];
            if (ny >= R || nx >= C || ny < 0 || nx < 0 || F[ny][nx]) {
                d = (d+1)%4; ny = y+dy[d]; nx = x+dx[d];
            }
            y = ny; x = nx;
        }
        S[ns] = 0;
        while (S[ns]==' ' && ns>=0) ns--; S[++ns] = 0;


        printf("%d", id);
        printf(" %s\n", S);
        id++;
    }

    return 0;
}
