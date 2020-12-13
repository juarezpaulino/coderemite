#include <stdio.h>
#include <stdlib.h>

#define MAXDIGITS 1000010


char num[MAXDIGITS];
int fib[10000];
char disc[1001][1001];
int n, m, k;

int mod(char num[], int div) {
    
    int rem;
    int i;

    rem = 0;
    for (i = 0; i < k; i++) {
        rem *= 10;
        rem += num[i];
        while (rem >= div) rem = rem - div;
    }

    return (rem);
}


int main() {
 
    int i;
    int pos;
    char ch;
    
    fib[1] = fib[2] = 1; disc[1][1] = 1;
    for (i = 3; ; i++) {
        fib[i] = (fib[i-2] + fib[i-1]) % 1000;
        if (disc[fib[i-1]][fib[i]]) break;
        disc[fib[i-1]][fib[i]] = 1;
    }
    m = i-2;

    scanf("%d ", &n);
    for (i = 0; i < n; i++) {
        for (k = 0; (ch = getchar()) != '\n'; k++) num[k] = ch-'0';
        pos = mod(num, m);
        printf("%03d\n", fib[pos]);
    }
    
    return 0;
}
