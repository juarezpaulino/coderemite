/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

int n;
int dm[2][13] = { {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
                  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };

int get_int() {
    int ch, i, s;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    if (ch == EOF) return (EOF);
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');
    return i;
}

int main() {

    int d, m, y, c, b;
    int d1, m1, y1, c1;
    register int i;
    int nc, nd;

    while (1) {
        n = get_int();
        if (!n) break;
        d1 = get_int(); m1 = get_int(); y1 = get_int(); c1 = get_int();
        for (i = 1, nc = nd = 0; i < n; i++) {
            d = get_int(); m = get_int(); y = get_int(); c = get_int();
            if ((y == y1) || (y1+1==y && m1==12&&m==1)) {
                b = 0;
                if (m1==2 && m==3)
                    b = ((!(y1%4) && (y1%100)) || !(y1%400));
                if (((m1+1==m || (m1==12&&m==1)) && d1==dm[b][m1] && d==1) ||
                    (m1==m && d1+1==d)) {
                    nc += (c-c1); nd++;
                }
            }
            d1 = d; m1 = m; y1 = y; c1 = c;
        }
        printf("%d %d\n", nd, nc);
    }

    return 0;
}
