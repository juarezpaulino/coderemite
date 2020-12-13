#include <stdio.h>
#include <math.h>

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n') || (ch == '-'));
    for (i = 0; ch>='0' && ch<='9'; ch = getchar()) i = 10 * i + (ch - '0');
    return i;
}

char isPrime(int n) {
    int maxP, p;
    if (n < 5 || n%2 == 0 || n%3 == 0) return (n == 2 || n == 3);
    maxP = (int)sqrt(n)+2;
    for (p = 5; p < maxP; p += 6) if (n % p == 0 || n % (p+2) == 0) return 0;
    return 1;
}


int main() {

    register int n;
    
    n = get_int(); if (isPrime(n)) puts("sim"); else puts("nao");
    
    return 0;
}

