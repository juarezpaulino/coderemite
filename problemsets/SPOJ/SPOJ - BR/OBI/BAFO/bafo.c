#include <stdio.h>


int main() {
    int n, x, y;
    register int a, b, k = 1;
    while (scanf("%d", &n) && n) {
        a = b = 0;
        while (n--) { scanf("%d %d", &x, &y); a += x; b += y; }
        if (a > b) printf("Teste %d\nAldo\n\n", k++);
        else printf("Teste %d\nBeto\n\n", k++);
    }
    return 0;
}

