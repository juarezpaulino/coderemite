#include <stdio.h>

int get_int() {
    int ch, i, s;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    s = (ch == '-') ? 1, ch = getchar() : 0;
    for (i = 0; ch>='0' && ch<='9'; ch = getchar()) i = 10 * i + (ch - '0');
    if (s) return -i; return i;
}


int main() {

    register int i, n, s;
    
    n = get_int();
    for (s = i = 0; i < n; i++) s += get_int();
    printf("%d\n", s);
    
    return 0;
}

