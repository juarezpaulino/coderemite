/* Carmichael Numbers */

#include <stdio.h>
#include <math.h>


int isPrime(int num) {
    
    int aux, root;
    
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

unsigned anmodn(unsigned a,  unsigned n) {
    
    unsigned num, pow, aux_pow, aux_num, aux_tmp, pow_tmp;
    
    aux_num = 1;
    
    aux_tmp = a;
    aux_pow = 1;
    while ((aux_tmp * a) <= n) {
        aux_tmp *= a;
        aux_pow++;
    }
    pow = 0;
    
    if (aux_pow == n)
        return (aux_tmp);
    
    while (pow < n) {
        
        if (aux_pow <= (n-pow)) {
            num = aux_tmp;
            pow_tmp = aux_pow;
            
            while ((pow_tmp + pow_tmp) <= (n - pow)) {
                pow_tmp += pow_tmp;
                num *= num;
                num = num % n;
            }   
            pow += pow_tmp;
        }
        else {
            num = a;
            for (aux_pow = 1; aux_pow < (n - pow); aux_pow++) {
                num *= a;
                num = num % n;
            }
            aux_num *= num;
            aux_num = aux_num % n;
            break;
        }
        
        aux_num *= num;
        aux_num = aux_num % n;
    }
    
    return (aux_num);
}


int main() {
    
    unsigned n, a;
    char normal;
    printf("%d\n", isPrime(853));
    while (scanf("%u", &n)) {
        
        if (n == 0)
            break;
     
        if (!(n % 2)) {
            printf("%u is normal.\n", n);
            continue;
        }
        
        normal = 1;
        if (!isPrime(n)) {
            normal = 0;
            for (a = 2; a <= n-1; a++)
                if (a != anmodn(a, n)) {
                    normal = 1;
                    break;
                }
            if (!normal)
                printf("The number %u is a Carmichael number.\n", n);
        }
        if (normal)
            printf("%u is normal.\n", n);
            
    }
    
    return 0;
}
