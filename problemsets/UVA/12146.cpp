/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

#define max(a, b) ((a)>(b)?(a):(b))

int m,n;

int getint() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    if (ch == EOF) return (EOF);
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar()) i = 10 * i + (ch - '0');
    return i;
}

int main() {
    register int i, j, a;
    int x, y, z, x1, y1, z1;
    while (1) {
        m = getint(); n = getint();
        if (!m && !n) break;
        for (i = 0; i < m; i++) {
            z = y = getint(); if (n > 1) { a = getint(); z = max(y, a); }
            for (j = 2; j < n; j++) {
                x = y; y = z; a = getint(); z = max(x+a, y);
            }
            if (i == 0) z1 = y1 = z; else if (i == 1) z1 = max(y1, z);
            else { x1 = y1; y1 = z1; z1 = max(x1+z, y1); }
        }
        printf("%d\n", z1);
    }
    return 0;
}

