#include <stdio.h>


int main() {
    
    int n;
    register int i, s, soma, k = 1;
    char str[50000], op;
    
    while (scanf("%d ", &n) && n) {
        gets(str);
        for (soma = i = 0; str[i] >= '0' && str[i] <= '9'; i++)
            soma = 10 * soma + (str[i] - '0');
        while (str[i]) {
            op = str[i++];
            for (s = 0; str[i] >= '0' && str[i] <= '9'; i++) 
                s = 10 * s + (str[i] - '0');
            if (op == '+') soma += s; else soma -= s;
        }
        printf("Teste %d\n%d\n\n", k++, soma);
    }
    
    return 0;
}

