#include <stdio.h>
#include <math.h>

int x[1000], y[1000], dist[1000];

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
    int n;
    register int i, j, d, dx, dy, m, k = 1;
    while (1) {
        n = get_int(); if (!n) break;
        for (i = 0; i < n; i++) x[i] = get_int(), y[i] = get_int(), dist[i] = 0;
        for (i = 0; i < n; i++) for (j = i+1; j < n; j++) {
            dx = x[i]-x[j]; dy = y[i]-y[j]; d = dx*dx+dy*dy;
            if (d > dist[i]) dist[i] = d; if (d > dist[j]) dist[j] = d;
        }
        for (i = 0, m = 0x3F3F3F3F; i < n; i++) if (dist[i] < m) m = dist[i];
        printf("Teste %d\n%.0lf\n\n", k++, 2*sqrt(m) + 5 + 0.5);
    }
    
    return 0;
}

