#include <stdio.h>
#include <stdlib.h>

int get_int() {
    int ch, i, s;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    s = (ch == '-') ? 1, ch = getchar() : 0; 
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');
    if (s) return -i;
    return i;
}

int cmp(int *a, int *b) { return (*a-*b); }


int main() {

    int x[1000], y[1000];
    register int i, s, k = 1;
    int cmp();
    
    while (1) {
        s = get_int(); if (!s) break;
        for (i = 0; i < s; i++) x[i] = get_int(), y[i] = get_int();
        qsort(x, s, sizeof(int), cmp); qsort(y, s, sizeof(int), cmp);
        printf("Teste %d\n%d %d\n\n", k++, x[s>>1], y[s>>1]);
    }
    
    return 0;
}

