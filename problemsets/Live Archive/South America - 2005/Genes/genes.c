/* Genes */

#include <stdio.h>

int revi[1000], revj[1000];

int get_int() {

    int ch, i, sign = 1;
    while (((ch = getchar()) == ' ') || (ch == '\n'));

    if (ch == EOF) return (EOF);

    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');

    return i;
}

int main() {

    int n, r, q;
    int i, j;
    int x;
    int c;
    
    c = 1;
    while ((n = get_int()) != EOF) {
        
        if (n == 0) break;
        
        r = get_int();
        for (i = 0; i < r; i++) { revi[i] = get_int(); revj[i] = get_int(); }
        q = get_int();
        printf("Genome %d\n", c);
        for (i = 0; i < q; i++) {
            x = get_int();
            for (j = 0; j < r; j++)
                if ((revi[j] <= x) && (x <= revj[j]))
                    x = revi[j]+(revj[j]-x);
            printf("%d\n", x);
        }
        c++;
    }
    return 0;
}
