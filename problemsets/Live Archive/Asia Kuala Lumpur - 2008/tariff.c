#include <stdio.h>
#include <stdlib.h>

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');
    return i;
}


int main() {

    int t, n, x, s1, s2, c, i;

    t = get_int();    
    for (c = 1; c <= t; c++) {
        n = get_int(); printf("Case %d: ", c);
        s1 = s2 = 0;
        for (i = 0; i < n; i++) {
            x = get_int(); s1 += ((x/30)+1)*10; s2 += ((x/60)+1)*15;
        }
        if (s1 < s2) printf("Mile %d\n", s1);
        else if (s2 < s1) printf("Juice %d\n", s2);
        else printf("Mile Juice %d\n", s1);
    }
    return 0;
}
