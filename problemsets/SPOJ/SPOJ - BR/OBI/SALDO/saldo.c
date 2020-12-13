#include <stdio.h>

int main() {

    int n, x, y, c = 1, val, i;
    int s, a, b, m;
    
    while (scanf("%d", &n)) {
        if (!n) break;
        b = -1; m = -1; s = 1; val = 0;
        for (i = 1; i <= n; i++) {
            scanf("%d %d", &x, &y);
            val += x-y;
            if (val >= m) { m = val; a = s; b = i; }
            if (val < 0) { val = 0; s = i+1; }
        }
        printf("Teste %d\n", c++);
        if (m > 0) printf("%d %d\n\n", a, b);
        else puts("nenhum\n");
    }       
    
    return 0;
}
