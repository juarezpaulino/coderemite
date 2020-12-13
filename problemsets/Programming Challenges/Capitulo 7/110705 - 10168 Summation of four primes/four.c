/* Summation of four primes */

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


int main() {
    
    int n, i, sums[4], aux;
    
    while (scanf("%d", &n) != EOF) {
        
        if (n < 8) {
            printf("Impossible.\n");
            continue;
        }
        
        if (n == 8) {
            printf("2 2 2 2\n");
            continue;
        }
        if (n == 9) {
            printf("2 2 2 3\n");
            continue;
        }
        if (n == 10) {
            printf("2 2 3 3\n");
            continue;
        }
        
        aux = n;
        if (n % 2) {
            sums[0] = 2;
            aux -= 2;
        }
        else {
            sums[0] = 3;
            aux -= 3;
        }
        
        sums[1] = 3;
        aux -= 3;
        sums[2] = 0;
        
        for (i = aux - 3; i > (aux/2) - 1; i -= 2)
            if (isPrime(i))
                if (isPrime(aux - i)) {
                    sums[2] = i;
                    sums[3] = aux - i;
                    break;
                }
        
        if (sums[2]) {
            for (i = 0; i < 3; i++)
                printf("%d ", sums[i]);
            printf("%d\n", sums[i]);
        }
        else
            printf("Impossible.\n");
            
    }
       
    return 0;    
}
