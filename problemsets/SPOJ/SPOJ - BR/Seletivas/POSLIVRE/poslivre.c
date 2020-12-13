#include <stdio.h>


char tab[501][501];
int w, h, n;

int get_int() {

    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));

    if (ch == EOF) return (EOF);

    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');

    return i;
}


int main() {
    
    int i, j, k;
    int x1, x2, y1, y2, c;
    
    while (1) {
        w = get_int(); h = get_int(); n = get_int();
        if (!w && !h && !n) break;
        for (i = 1; i <= h; i++) for (j = 1; j <= w; j++) tab[i][j] = 0;
        c = 0;
        for (k = 0; k < n; k++) { 
            x1 = get_int(); y1 = get_int(); x2 = get_int(); y2 = get_int();
            if (x1>x2) x1^=x2^=x1^=x2; if (y1>y2) y1^=y2^=y1^=y2;
            for (i = y1; i <= y2; i++) for (j = x1; j <= x2; j++)
                if (!tab[i][j]) { c++; tab[i][j] = 1; }
        }
        c = w*h-c;
        if (!c) puts("There is no empty spots.");
        else if (c == 1) puts("There is one empty spot.");
        else printf("There are %d empty spots.\n", c);
    }
    
    return 0;
}
