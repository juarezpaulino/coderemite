/* P-Network */

#include <stdio.h>

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
    
    int n;
    int i, j;
    int x;
    int s;
    char t[21];
    char index[21];
    char valid[21];

    
    while (1) {
        
        if ((n = getint()) == 0) break;
        
        for (i = 1; i <= n; i++) t[i] = 0;
        
        for (i = 1; i <= n; i++) {
            x = getint();
            if (t[x] > 0) break;
            t[x] = i;
            valid[i] = 1;
        }
        newl();
        if (i <= n) { printf("No solution\n"); continue; }

        s = 0;
        for (i = n; i > 0; i--) {
            for (j = 1, x = 0; j <= t[i]; j++) if (valid[j]) x++;
            valid[t[i]] = 0;
            index[n-i] = x;
            s += x;
        }
        
        x = (((1+n)*n)/2)-s;
        printf("%d", x);
        for (i = 0, x = n; i < n; i++, x--)
            for (j = index[i]; j < x; j++)
                printf(" %d", j);
        putchar('\n');
    }
    
    return 0;
}
