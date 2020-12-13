/* Factovisors */

#include <stdio.h>

int isPrime(int num) {
    
    int aux, root;
    
    if (num == 2)
        return 1;
    if (!(num % 2))
        return 0;
    
    aux = 3;
    root = sqrt(num);
    while (aux <= root+1)
        if (!(num % aux))
            return 0;
        else
            aux += 2;
                
    return 1;
}

int gcd(int a, int b) {
    
    if (b == 0)
        return a;
    
    return (gcd(b, a%b));
}

int main() {
    
    unsigned n, m, i, aux, d, count;
    
    while (scanf("%u %u", &n, &m) != EOF) {
    
        if ((m == 0) || ((n == 0) && (m > 1))) {
            printf("%u does not divide %u!\n", m, n);
            continue;
        }
        if ((n == 0) && (m == 1)) {
            printf("%u divides %u!\n", m, n);
            continue;
        }
        
        aux = m;
        for (i = n, count = 0; (i >= 1) && (aux != 1); i--) {
            if (aux <= i) {
                aux = 1;
                break;
            }
                
            d = gcd(i, aux);
            if (d == 1) {
                count++;
                if (count == 10) {
                    if (aux > i) {
                        if (isPrime(aux))
                            break;
                    }
                    else
                        count = 0;
                }
            }
            else {
                if (count)
                    count = 0;
                aux /= d;
            }
        }
        if (aux == 1)
            printf("%u divides %u!\n", m, n);
        else
            printf("%u does not divide %u!\n", m, n);
    }
    
    return 0;
}
