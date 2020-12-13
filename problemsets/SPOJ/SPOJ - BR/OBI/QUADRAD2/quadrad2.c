#include <stdio.h>

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n') || (ch == '-'));
    for (i = 0; ch>='0' && ch<='9'; ch = getchar()) i = 10 * i + (ch - '0');
    return i;
}


int main() {

    register int n;
    
    n = get_int(); printf("%d\n", n*n);
    
    return 0;
}

