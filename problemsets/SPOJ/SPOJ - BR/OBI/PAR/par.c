#include <stdio.h>


int main() {
    int n, x, y;
    char nome[2][11];
    register int i, k = 1;
    while (scanf("%d ", &n) && n) {
        gets(nome[0]), gets(nome[1]);
        printf("Teste %d\n", k++);
        for (i = 0; i < n; i++) scanf("%d %d", &x, &y), printf("%s\n", nome[(x+y)&1]);
        putchar('\n');
    }    
    
    return 0;
}

