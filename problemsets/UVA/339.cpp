/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

int S[101][101];
int M, N;

void go(int y, int x) {
    int c = S[y][x];
    S[y][x] = -1;
    for (int i = 0; i < 4; i++) {
        int ny = y+dy[i];
        int nx = x+dx[i];
        if (ny < 0 || nx < 0 || ny >= M || nx >= N || S[ny][nx] != c) continue;
        go(ny,nx);
    }
}

void fall() {
    for (int j = 0; j < N; j++) {
        int c = 0;
        for (int i = 0; i < M; i++) {
            if (S[i][j]==-1) c++;
            else S[i-c][j] = S[i][j];
        }
        for (int i = M-c; i < M; i++) S[i][j] = -1;
    }
    int rem = 0;
    for (int i = 0; i < M; i++) {
        bool ok = 1;
        for (int j = 0; j < N; j++) if (S[i][j]!=-1) ok = 0;
        if (ok) rem++;
        else break;
    }
}

void contract() {
    int rem = 0;
    for (int j = 0; j < N; j++) {
        bool ok = 1;
        for (int i = 0; i < M; i++) {
            if (S[i][j]!=-1) ok = 0;
            S[i][j-rem] = S[i][j];
        }
        if (ok) rem++;
    }
    N-=rem;
}


int main() {

    int T = 1;
    while (scanf("%d %d", &M, &N) != EOF) {
        if (!M || !N) break;
        for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) scanf("%d", &S[i][j]);
        int a, b;
        bool won = 0;
        while (scanf("%d %d", &a, &b) != EOF) {
            if (!a || !b) break;
            if (a < 1 || a > M || b < 1 || b > N || won) continue;
            a--; b--;
            if (S[a][b]==-1) continue;
            int ok = 0;
            for (int i = 0; !ok && i < 4; i++) {
                int ny = a+dy[i];
                int nx = b+dx[i];
                if (ny < 0 || nx < 0 || ny >= M || nx >= N || S[ny][nx] != S[a][b]) continue;
                ok++;
            }
            if (ok) {
                go(a,b);
                fall();
                contract();
            }
            if (!N) won = 1;
        }
        if (T > 1) putchar('\n');
        printf("Grid %d.\n", T);
        if (won) { puts("    Game Won"); }
        else for (int i = M-1; i >= 0; i--) {
            printf("   ");
            for (int j = 0; j < N; j++) {
                if (S[i][j] == -1) printf("  ");
                else printf(" %d", S[i][j]);
            }
            putchar('\n');
        }
        T++;
    }

    return 0;
}
