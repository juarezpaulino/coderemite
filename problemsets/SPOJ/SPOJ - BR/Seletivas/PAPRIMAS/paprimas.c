#include <stdio.h>

char isPrime(int n) {
    int maxP, p;
    if (n < 0) return isPrime(-n);
    if (n < 5 || n%2 == 0 || n%3 == 0) return (n == 2 || n == 3);
    maxP = (int)sqrt(n)+2;
    for (p = 5; p < maxP; p += 6) if (n % p == 0 || n % (p+2) == 0) return 0;
    return 1;
}


int main() {
    
    char str[21];
    int i, s;
    
    while (gets(str)) {
        for (i = s = 0; str[i]; i++)
            if (str[i]>='A'&&str[i]<='Z') s += str[i]-'A'+27;
            else s += str[i]-'a'+1;
        if (s==1) puts("It is a prime word.");
        else if (isPrime(s)) puts("It is a prime word.");
        else puts("It is not a prime word.");
    }
    
    return 0;
}
