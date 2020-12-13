/* Grandpa is Famous */

#include <stdio.h>

int p[10001];
int n, m;

int get_int() {

    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));

    if (ch == EOF) return (EOF);

    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');

    return i;
}


int main() {
    
    int i;
    int x;
    int fir, sec;
    
    while (1) {
        
        n = get_int(); m = get_int();
        if ((!n) && (!m)) break;
        
        for (i = 1; i <= 10000; i++) p[i] = 0;
        
        for (i = 0; i < n*m; i++) {
            x = get_int();
            p[x]++;
        }
        
        fir = sec = -1;
        for (i = 1; i <= 10000; i++)
            if (p[i] > fir) {
                if (fir > sec) sec = fir;
                fir = p[i];
            }
            else if (sec < p[i]) sec = p[i];
        
        for (i = 1; i <= 10000; i++)
            if (p[i] == sec)
                printf("%d ", i);
        putchar('\n');
    }

    return 0;
}
