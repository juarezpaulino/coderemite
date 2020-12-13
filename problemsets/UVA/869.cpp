/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

char G1[110][110], G2[110][110];

int main() {

    int T;
    int N, M;
    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i < 26; i++) for (int j = i; j < 26; j++) G1[i][j] = G2[j][i] = (i==j) ? 1 : 0;
        scanf("%d", &N);
        while (N--) {
            int u, v;
            char c1, c2;
            scanf(" %c %c ", &c1, &c2);
            u = c1-'A';
            v = c2-'A';
            G1[u][v] = 1;

        }
        scanf("%d", &M);
        while (M--) {
            int u, v;
            char c1, c2;
            scanf(" %c %c ", &c1, &c2);
            u = c1-'A';
            v = c2-'A';
            G2[u][v] = 1;

        }
        for (int k = 0; k < 26; k++) for (int i = 0; i < 26; i++) for (int j = 0; j < 26; j++) {
            G1[i][j] |= G1[i][k]&G1[k][j];
            G2[i][j] |= G2[i][k]&G2[k][j];
        }
        bool ok = 1;
        for (int i = 0; i < 26; i++) for (int j = 0; j < 26; j++)
            if (G1[i][j]!=G2[i][j]) { ok = 0; break; }
        if (ok) puts("YES");
        else puts("NO");
        if (T) putchar('\n');
    }

    return 0;
}
