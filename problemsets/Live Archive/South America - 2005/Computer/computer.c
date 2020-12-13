/* Computer DJ */

#include <stdio.h>

char music[27][102];
int sum[50];

void newl() {
    
    char ch;
    
    while ((getchar() != '\n') && (ch != EOF));    
}

int getint() {

    int ch, i, sign = 1;
    while (((ch = getchar()) == ' ') || (ch == '\n'));

    if (ch == EOF) return (EOF);

    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');

    ungetc(ch, stdin);

    return i;
}

int main() {

    int n, q, k;
    int i, j;
    int l, c, d, pos;
    
    while (1) {
        n = getint();
        q = getint();    
        newl();
        
        if ((!n) && (!q)) break;
        
        for (i = 0; i < n; i++) scanf("%s%*c", music[i]);
        
        if (n == 1) {
            for (i = 0; i < q; i++) {
                k = getint();
                puts(music[0]);
            }
            putchar('\n');
            continue;
        }
        
        sum[0] = 0;
        j = n;
        for (i = 0; sum[i] <= 100000000; i++) {
            sum[i+1] = sum[i] + (i+1)*j;
            j = j*n;
        }
        l = i;
        
        for (i = 0; i < q; i++) {
            k = getint();
            for (j = 1; (j < l) && (sum[j] < k); j++);
            c = j;
            d = k-1-sum[c-1];
            pos = c - (d%c);
            k = d/c;
            for (j = 1; j < pos; j++) k = k / n;
            puts(music[k%n]);
        }
        putchar('\n');
    }
    
    return 0;
}
