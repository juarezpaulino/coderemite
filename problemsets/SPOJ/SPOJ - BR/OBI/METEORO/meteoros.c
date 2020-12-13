#include <stdio.h>

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');
    return i;
}


int main() {

    int x1, y1, x2, y2;
    int n, x, y;
    register int i, s, k = 1;
    
    while (1) {
        x1 = get_int(); y1 = get_int(); x2 = get_int(); y2 = get_int();
        if (!x1 && !x2 && !y1 && !y2) break;
        n = get_int();
        for (i = s = 0; i < n; i++) {
            x = get_int(); y = get_int();
            if (x >= x1 && x <= x2 && y >= y2 && y <= y1) s++;
        }
        printf("Teste %d\n%d\n\n", k++, s);
    }
    
    return 0;
}

