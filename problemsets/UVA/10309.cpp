/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char M[20][20], U[20][20];

int dy[] = { 0, -1, 0, 1, 0 };
int dx[] = { 0, 0, -1, 0, 1 };

inline void sw(int i, int j) {
    for (int k = 0; k < 5; k++)
        M[i+dy[k]][j+dx[k]] = 1-M[i+dy[k]][j+dx[k]];
}

int main() {

    char S[1010];
    while (gets(S)) {
        if (!strcmp(S, "end")) break;
        for (int i = 0; i < 10; i++) {
            scanf(" %s ", M[i]);
            for (int j = 0; j < 10; j++) U[i][j] = (M[i][j]=='O') ? 1 : 0;
        }
        int ret = 101;
        for (int v = 0; v < 1<<10; v++) {
            memcpy(M, U, sizeof(M));
            int u = 0;
            for (int i = 0; i < 10; i++) if (v&(1<<i)) {
                u++; sw(0,i);
            }
            for (int i = 1; i < 10; i++) for (int j = 0; j < 10; j++) if (M[i-1][j]) {
                u++; sw(i,j);
            }
            bool ok = 1;
            for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) if (M[i][j]) ok = 0;
            if (ok) ret = min(ret, u);
        }
        if (ret > 100) printf("%s -1\n", S);
        else printf("%s %d\n", S, ret);
    }

    return 0;
}
