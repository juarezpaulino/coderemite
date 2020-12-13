#include <stdio.h>

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');
    return i;
}


int main() {
    
    register int i, f = 1;
    int n;
    
    n = get_int();
    for (i = 2; i <= n; i++) f*=i;
    printf("%d\n", f);
    
    return 0;
}
    

