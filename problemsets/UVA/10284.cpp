/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;


int main() {

    char S[80];
    while (gets(S)) {
        char MAPA[30][30] = {0};
        char vis[30][30] = {0};
        int r = 10, c = 10;
        for (int i = 0; S[i]; i++) {
            if (S[i]=='/') { r++; c = 10; continue; }
            if (S[i] >= '0' && S[i] <= '9') c += S[i]-'0';
            else MAPA[r][c++] = S[i];
        }
        for (int r = 10; r < 18; r++) for (int c = 10; c < 18; c++) if (MAPA[r][c] != 0) {
            vis[r][c] |= 1;
            if (MAPA[r][c]=='p' || MAPA[r][c]=='P') {
                int d = MAPA[r][c]=='p'?1:-1;
                vis[r+d][c-1] = vis[r+d][c+1] |= 2;
            }
            if (MAPA[r][c]=='r' || MAPA[r][c]=='R' || MAPA[r][c]=='q' || MAPA[r][c]=='Q') {
                for (int j = 1; j <= 8; j++) if (!MAPA[r][c-j]) vis[r][c-j] |= 2; else break;
                for (int j = 1; j <= 8; j++) if (!MAPA[r][c+j]) vis[r][c+j] |= 2; else break;
                for (int j = 1; j <= 8; j++) if (!MAPA[r+j][c]) vis[r+j][c] |= 2; else break;
                for (int j = 1; j <= 8; j++) if (!MAPA[r-j][c]) vis[r-j][c] |= 2; else break;
            }
            if (MAPA[r][c]=='n' || MAPA[r][c]=='N')
                vis[r+2][c+1] |=
                vis[r+2][c-1] |=
                vis[r+1][c+2] |=
                vis[r+1][c-2] |=
                vis[r-2][c+1] |=
                vis[r-2][c-1] |=
                vis[r-1][c+2] |=
                vis[r-1][c-2] |= 2;
            if (MAPA[r][c]=='b' || MAPA[r][c]=='B'|| MAPA[r][c]=='q' || MAPA[r][c]=='Q') {
                for (int d = 1; d <= 8; d++) if (!MAPA[r+d][c+d]) vis[r+d][c+d] |= 2; else break;
                for (int d = 1; d <= 8; d++) if (!MAPA[r+d][c-d]) vis[r+d][c-d] |= 2; else break;
                for (int d = 1; d <= 8; d++) if (!MAPA[r-d][c+d]) vis[r-d][c+d] |= 2; else break;
                for (int d = 1; d <= 8; d++) if (!MAPA[r-d][c-d]) vis[r-d][c-d] |= 2; else break;
            }
            if (MAPA[r][c]=='K' || MAPA[r][c]=='k') {
                for (int i = -1; i <= 1; i++) for (int j = -1; j <= 1; j++) vis[r+i][c+j] |= 2;
            }
        }
        int ret = 0;
        for (int i = 10; i < 18; i++) for (int j = 10; j < 18; j++) if (vis[i][j]==0) ret++;
        printf("%d\n", ret);
    }

    return 0;
}
