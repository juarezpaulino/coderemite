#include <stdio.h>

int main() {

    int n, c = 1, i;
    int x, y, u, v;
    int mx, my, mu, mv;
    
    while (scanf("%d", &n)) {
        if (!n) break;
        scanf("%d %d %d %d", &mx, &my, &mu, &mv);
        for (i = 1; i < n; i++) {
            scanf("%d %d %d %d", &x, &y, &u, &v);
            if (x > mx) mx = x; if (y < my) my = y;
            if (u < mu) mu = u; if (v > mv) mv = v;
        }
        printf("Teste %d\n", c++);
        if (mx>=mu || my<=mv) puts("nenhum\n\n");
        else printf("%d %d %d %d\n\n", mx, my, mu, mv);
    } 
    
    return 0;
}
