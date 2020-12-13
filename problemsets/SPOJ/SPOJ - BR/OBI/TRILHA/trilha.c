#include <stdio.h>

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');
    return i;
}


int main() {
    register int n, m, c1, c2, k, x, x1, min, tr;
    n = get_int(); min = 0x3F3F3F3F;
    for (k = 1; k <= n; k++) {
        m = get_int(); c1 = c2 = 0;
        x = get_int();
        while (--m) {
            x1 = get_int(); if (x1 > x) c1 += x1-x; else c2 += x-x1; x = x1;
        }
        if (c1 < min) { tr = k; min = c1; } if (c2 < min) { tr = k; min = c2; }
    }
    printf("%d\n", tr);
    return 0;
}

