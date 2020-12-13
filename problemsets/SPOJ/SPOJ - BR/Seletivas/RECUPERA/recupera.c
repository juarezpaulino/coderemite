#include <stdio.h>

#define INF 0x3F3F3F3F

int main() {
    int n;
    int s, x, v;
    int c = 1;
    int i;
    
    while (scanf("%d", &n) != EOF) {
        s = 0;
        v = INF;
        for (i = 0; i < n; i++) {
            scanf("%d", &x);
            if (v == INF) {
                if (x == s) v = x;
                s += x;   
            }
        }
        printf("Instancia %d\n", c++);
        if (v != INF) printf("%d\n\n", v);
        else puts("nao achei\n");
    }
    
    return 0;
}
