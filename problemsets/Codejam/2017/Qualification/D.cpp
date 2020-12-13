/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;


int N, M;
char A[110][110];
char B[110][110];
char crow[220];
char diag[660];
int y;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main() {

    int TT;
    scanf("%d", &TT);
    for (int tt = 1; tt <= TT; tt++) {
        printf("Case #%d: ", tt);

        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
        memset(crow, 0, sizeof(crow));
        memset(diag, 0, sizeof(diag));
        cin >> N >> M;
        y = 0;
        for (int i = 0; i < M; i++) {
            char v;
            int r, c;
            cin >> v >> r >> c;
            A[r][c] = B[r][c] = v;
            y += (v=='o')?2:1;
            if (v=='o' || v=='x') crow[r] = crow[N+c] = 1;
            if (v=='o' || v=='+') diag[r+c] = diag[4*N+r-c] = 1;
        }
        for (int i = 1; i <= N; i++) if (!crow[i])
            for (int j = 1; j <= N; j++) if (!crow[N+j]) {
                if (B[i][j]=='+') B[i][j] = 'o';
                else if (!B[i][j]) B[i][j] = 'x';
                crow[i] = crow[N+j] = 1, y++;
                break;
            }
        bool ok = 1;
        while (ok) {
            ok = 0;
            int m =
            for (int k = 2; k <= 2*N; k++) if (diag[4*N+k]) {

            }
        }
        int py = 1, px = 1;
        for (int d = 0; d < 4; d++) {
            for (int k = 0; k < N; k++) {
                if (!diag[py+px] && !diag[4*N+py-px]) {
                    if (B[py][px]=='x') B[py][px] = 'o';
                    if (!B[py][px]) B[py][px] = '+';
                    diag[py+px] = diag[4*N+py-px] = 1, y++;
                }
                if (k < N-1) py+=dy[d], px+=dx[d];
            }
        }
        //for (int i = 1; i <= N; i++, putchar('\n')) for (int j = 1; j <= N; j++) printf("%c", !A[i][j]?'-':A[i][j]);
        //for (int i = 1; i <= N; i++, putchar('\n')) for (int j = 1; j <= N; j++) printf("%c", !B[i][j]?'-':B[i][j]);

        vector<tuple<char, int, int> > ret;
        for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) if (A[i][j] != B[i][j])
            ret.push_back(make_tuple(B[i][j],i,j));
        printf("%d %d\n", y, ret.size());
        for (auto it: ret)
            printf("%c %d %d\n", get<0>(it), get<1>(it), get<2>(it));
    }
    return 0;
}
