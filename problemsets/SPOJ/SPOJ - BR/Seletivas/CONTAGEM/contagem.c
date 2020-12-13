#include <stdio.h>
#include <string.h>

int main() {
 
    char str[100];
    int i, k;
    unsigned long long soma, c = 1;
    
    while (gets(str)) {
        k = strlen(str)-1;
        soma = 0;
        for (i = k; i >= 0; i--)
            if (str[i] == 'b') soma += (1llu<<(k-i));
        printf("Palavra %d\n", c++);
        printf("%llu\n\n", soma);
    }
    
    return 0;
}
