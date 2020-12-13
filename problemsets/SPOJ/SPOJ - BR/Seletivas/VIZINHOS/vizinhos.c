#include <stdio.h>


int main() {
 
    int n, p, m, i, k;
    int x, lug[1000];
    char str[10000], c;
    
    scanf("%d ", &n);
    while (n--) {
        scanf("%d ", &p); m = 0x3F3F3F3F;
        for (k = 0; k < p; k++) {
            gets(str); lug[k] = 0;
            for (i = 0; str[i]; i++) if (str[i]==' ') lug[k]++;
            if (lug[k] < m) m = lug[k];
        }
        c = 0;
        for (k = 0; k < p; k++)
            if (lug[k] == m) {
                if (c) putchar(' ');
                printf("%d", k+1); c = 1;
            }
        putchar('\n');
    }
    
    return 0;
}
