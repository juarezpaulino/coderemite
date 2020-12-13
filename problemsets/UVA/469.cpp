/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <sstream>

using namespace std;

int M, N;
char MAPA[101][101];
int ID[101][101];
int AREA[10101], id;

int dy[] = {-1,-1,-1,0,0,1,1,1};
int dx[] = {-1,0,1,-1,1,-1,0,1};

void go(int i, int j) {
    MAPA[i][j] = 0;
    ID[i][j] = id;
    AREA[id]++;
    for (int k = 0; k < 8; k++) {
        int y = i+dy[k], x = j+dx[k];
        if (y < 0 || y >= M || x < 0 || x >= N || MAPA[y][x]!='W') continue;
        go(y,x);
    }
}

int main() {

    int T;
    scanf("%d ", &T);
    while (T--) {
        M = 0;
        while (1) {
            gets(MAPA[M]);
            if (MAPA[M][0]!='W' && MAPA[M][0]!='L') break;
            M++;
        }
        N = strlen(MAPA[0]);
        id = 0;
        for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) if (MAPA[i][j]=='W') {
            AREA[id] = 0;
            go(i,j);
            id++;
        }
        do {
            if (MAPA[M][0]==0) break;
            istringstream is(MAPA[M]);
            int y, x;
            is >> y; is >> x;
            if (y < 1 || y > M || x < 1 || x > N || MAPA[y-1][x-1]=='L') puts("0");
            else printf("%d\n", AREA[ID[y-1][x-1]]);
            if (!gets(MAPA[M])) break;
        } while (1);
        if (T) putchar('\n');
    }

    return 0;
}
