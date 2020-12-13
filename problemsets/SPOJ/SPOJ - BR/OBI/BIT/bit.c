#include <stdio.h>


int main() {

    int n, c = 1;
    
    while (scanf("%d", &n)) {
        if (!n) break;
        printf("Teste %d\n", c++);
        printf("%d ", n/50); n%=50;
        printf("%d ", n/10); n%=10;
        printf("%d ", n/5); n%=5;
        printf("%d\n\n", n);
    }
    
    return 0;
}
