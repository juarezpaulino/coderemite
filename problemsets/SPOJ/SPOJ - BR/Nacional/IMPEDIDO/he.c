/* He is offside */

#include <stdio.h>
#include <stdlib.h>

#define INF 0x7fffffff

int a, d;
int m, m1, m2;

int getint() {

    int ch, i;
    
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    if (ch == EOF) return (EOF);
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar())
        i = 10 * i + (ch - '0');
    ungetc(ch, stdin);
    
    return i;
}


int main() {
    
    int i;
    int x;
    
    while (1) {
        
        a = getint(); d = getint();
        if (!a && !d) break;   
        
        m = m1 = m2 = INF;
        for (i = 0; i < a; i++) {
            x = getint();
            if (x < m) m = x;
        }
        for (i = 0; i < d; i++) {
            x = getint();
            if (x < m1) { m2 = m1; m1 = x; }
            else if (x < m2) m2 = x;
        }
        
        if ((m-m2) < 0) printf("Y\n");
        else printf("N\n");
    }    
    
    return 0;
}
