/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <string>

using namespace std;

map<string, int> os;
int VX[1010], X[1010], n;
int VY[1010], Y[1010], m;
int c[1010][1010], b[1010][1010];


void LCS() {
    int i, j, x, y;
    for (i = 1; i <= m; i++) c[i][0] = b[i][0] = 0;
    for (j = 0; j <= n; j++) c[0][j] = b[0][j] = 0;
    for (i = 1; i <= m; i++) for (j = 1; j <= n; j++) {
        (c[i-1][j] > c[i][j-1]) ? (c[i][j] = c[i-1][j], b[i][j] = b[i-1][j]) :
        (c[i][j-1] > c[i-1][j]) ? (c[i][j] = c[i][j-1], b[i][j] = b[i][j-1]) :
        (b[i-1][j] > b[i][j-1]) ? (c[i][j] = c[i-1][j], b[i][j] = b[i-1][j]) :
                                  (c[i][j] = c[i][j-1], b[i][j] = b[i][j-1]);
        if (X[i]==Y[j]) {
            x = c[i-1][j-1]+VX[i]+VY[j]; y = b[i-1][j-1]+1;
            if (x > c[i][j] || (x==c[i][j] && y<b[i][j])) c[i][j] = x, b[i][j] = y;
        }

    }
}


int main() {

    int t, i, v, k = 0;
    char str[50];

    for (scanf("%d", &t); t--; ) {
        os.clear(); k = 0;
        /* Leitura da entrada. */
        scanf("%d", &m);
        for (i = 1; i <= m; i++) {
            scanf("%*s %s %d", str, &v); VX[i] = v;
            X[i] = (os.count(str)) ? os[str] : (os[str] = k++);
        }
        scanf("%d", &n);
        for (i = 1; i <= n; i++) {
            scanf("%*s %s %d", str, &v); VY[i] = v;
            Y[i] = (os.count(str)) ? os[str] : (os[str] = k++);
        }
        LCS();
        printf("%d %d\n", c[m][n], b[m][n]);
    }

    return 0;
}
