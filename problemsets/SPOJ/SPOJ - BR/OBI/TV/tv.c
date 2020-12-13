#include <stdio.h>


int get_int() {
    int ch, i, s;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    s = (ch == '-') ? 1, ch = getchar() : 0;
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');
    if (s) return -i;
    return i;
}


int main() {
    short tv[1000][1000];
    register int i, j, k = 1, m, n, x, y, dx, dy, s, t;
    while (1) {
        m = get_int(); n = get_int(); if (!m && !n) break;
        for (i = 0; i < m; i++) for (j = 0; j < n; j++) tv[i][j] = get_int();
        dx = dy = 0;
        while (1) {
            x = get_int(); y = get_int(); if (!x && !y) break; dx += x; dy -= y;
        }
        printf("Teste %d\n", k++);
        for (i=0; i<m; i++) { for (j=0; j<n; j++) {
	       if (j != 0) putchar(' ');
	       s = (m + (i-dy)%m) % m; t = (n + (j-dx)%n) % n;
	       printf("%d", tv[s][t]);
        } putchar('\n'); }
        putchar('\n');
    }

    return 0;
}

