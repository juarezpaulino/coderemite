/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {

    int N;
    scanf("%d", &N);
    for (int t = 1; t <= N; t++) {
        char M[110][110], C[55];
        int L[110];
        int x = 0, y = 55;
        int ymax = -100, ymin = 200;
        memset(M, ' ', sizeof(M));
        scanf("%s", C);
        for (int i = 0; C[i]; i++) {
            if (C[i]=='R') ymax = max(ymax, y), ymin = min(ymin, y), L[y] = x, M[y++][x++] = '/';
            else if (C[i]=='F') M[--y][x++] = '\\', ymax = max(ymax, y), ymin = min(ymin, y), L[y] = x-1;
            else ymax = max(ymax, y), ymin = min(ymin, y), L[y] = x, M[y][x++] = '_';
        }
        printf("Case #%d:\n", t);
        int l = 0;
        for (int i = ymax; i >= ymin; i--) {
            putchar('|');
            putchar(' ');
            for (int j = 0; j <= L[i]; j++) putchar(M[i][j]);
            l = max(l, L[i]);
            putchar('\n');
        }
        putchar('+');
        for (int i = 0; i <= l+2; i++) putchar('-');
        putchar('\n');
        putchar('\n');
    }

    return 0;
}
