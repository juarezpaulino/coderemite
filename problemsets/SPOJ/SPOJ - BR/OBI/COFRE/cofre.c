#include <stdio.h>

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');
    return i;
}


int main() {

    register int n, x, y, s, i, k = 1;

    while (1) {
        n = get_int(); if (!n) break;
        printf("Teste %d\n", k++);
        for (i = s = 0; i < n; i++) { 
            x = get_int(); y = get_int(); s += x-y; printf("%d\n", s);
        }
        putchar('\n');
    }
    
    return 0;
}

