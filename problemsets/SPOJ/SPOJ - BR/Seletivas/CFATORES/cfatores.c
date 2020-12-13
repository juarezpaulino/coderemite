#include <stdio.h>
#include <math.h>

int prime[168], np;

char isPrime(int n) {
    int maxP, p;
    if (n < 0) return isPrime(-n);
    if (n < 5 || n%2 == 0 || n%3 == 0) return (n == 2 || n == 3);
    maxP = (int)sqrt(n)+2;
    for (p = 5; p < maxP; p += 6) if (n % p == 0 || n % (p+2) == 0) return 0;
    return 1;
}


int main() {
    
    int n;
    int i, j;
    
    /* Encontra todos os primos ate 1000. */
    prime[0] = 2; prime[1] = 3; np = 2;
    for (i = 5; i <= 1000; i+=6) {
        if (isPrime(i)) prime[np++] = i;
        if (isPrime(i+2)) prime[np++] = i+2;
    }

    while (scanf("%d", &n) != EOF) {
        if (!n) break;
        if (n == 1) { puts("1 : 0\n"); continue; }
        printf("%d : ", n); j = i = 0;
        while (n > 1) {
            if (i >= np) { j++; break; }
            if (!(n%prime[i])) {
                j++; n/=prime[i]; while (!(n%prime[i])) n/=prime[i];
            }
            i++;
        }
        printf("%d\n", j);
    }
    return 0;
}
