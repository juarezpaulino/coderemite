#include <stdio.h>
#include <stdlib.h>

int get_int() {
    int ch, i, s;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    s = (ch == '-') ? 1, ch = getchar() : 0;
    for (i = 0; ch>='0' && ch<='9'; ch = getchar()) i = 10 * i + (ch - '0');
    if (s) return -i; return i;
}

int p[10000];

int cmp(int *a, int *b) { return *b-*a; }


int main() {

    register int i, n, m;
    int cmp();
    
    n = get_int(); m = get_int();
    for (i = 0; i < n; i++) p[i] = get_int();
    qsort(p, n, sizeof(int), cmp);
    for (i = 0; i < m; i++) printf("%d\n", p[i]);
    
    return 0;
}

