#include <stdio.h>
#include <stdlib.h>

int n, m;

#define abs(x) (((x) < 0) ? (-x) : (x))

int main() {
    
    int i, x, y;

    while (scanf("%d", &i)) {
     
        if (!i) break;
     
        scanf("%d %d", &m, &n);
        while (i--) {
            scanf("%d %d", &x, &y);
            
            if (!abs(x-m) || !abs(y-n)) { puts("divisa"); continue; }
            
            if ((x > m) && (y > n)) puts("NE");
            else if ((x > m) && (y < n)) puts("SE");
            else if ((x < m) && (y > n)) puts("NO");
            else puts("SO");
        }   
    }
    
    return 0;
}
