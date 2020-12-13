#include <stdio.h>

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar()) i = 10 * i + (ch - '0');
    return i;
}

int main() {
    int t, n, r;
    int x, y, dx, dy;
    int mapa[60][60];
    int i;

    t = get_int();
    while (t--) {
        n = get_int(); r = get_int();
        for (i = 0; i < r; i++) x = get_int(), y = get_int(), mapa[y][x] = t+1;
        x = get_int(), y = get_int();
        for (dx = x ? x <= n ? 0 : -1 : 1, dy = y ? y <= n ? 0 : -1 : 1;
             (x+=dx) && (y+=dy) && x<=n && y<=n;
             dy = mapa[y][x]==t+1 ? -(dy^=dx^=dy^=dx) : dy);
        printf("%d %d\n", x, y);
    }
    return 0;
}
