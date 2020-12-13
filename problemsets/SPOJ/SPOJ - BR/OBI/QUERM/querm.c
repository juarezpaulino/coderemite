#include <stdio.h>


int main() {

    int n;
    int x, c = 1, i;
    
    while (scanf("%d", &n)) {
        if (!n) break;
        printf("Teste %d\n", c++);
        for (i = 1; i <= n; i++) {
            scanf("%d", &x);
            if (x == i) { printf("%d\n\n", i); break; }
        }
        for (i++; i <= n; i++) scanf("%*d");
    }
    
    return 0;
}
