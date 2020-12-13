/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    if (ch == '-') return (EOF);
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');
    return i;
}



int main() {

    int n, k = 1, m;
    while ((n = get_int()) != EOF) {
        if (!n) printf("Teste %d\n4\n\n", k++);
        else { m = (2<<(n-1))>>1; printf("Teste %d\n%d\n\n", k++, ((m*(1+m))<<2)|1); }
    }
    
    return 0;
}

