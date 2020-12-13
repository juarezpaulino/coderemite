/* Jogo de Varetas */

#include <stdio.h>

int n;


int main() {

    int i;
    int m;
    int c;

    while (scanf("%d", &n)) {
        
        if (!n) break;
        
        c = 0;
        for (i = 0; i < n; i++) {
            scanf("%*d %d", &m);
            if (m&1) m--;
            c = c+m;
        }
        
        printf("%d\n", c/4);
    }    
    
    return 0;
}
