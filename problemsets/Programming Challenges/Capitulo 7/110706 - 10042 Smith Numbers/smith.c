/* Smith Numbers */

#include <stdio.h>
#include <math.h>

typedef long unsigned uint;

uint int_sum(uint num) {
    
    uint sum = 0;
    while (num) {
        sum += num % 10;
        num /= 10;
    }
    
    return (sum);
}

char isSmith(uint num) {

    uint sum, root, i, aux;
    
    if (num == 2)
        return 0;
    
    aux = num;
    
    sum = 0;
    while (!(aux % 2)) {

        sum += 2;
        aux /= 2;
    }
    
    root = sqrt(aux);
    for (i = 3; i <= (root + 1); ) {
        if (aux % i)
            i += 2;
        else {    
            sum += int_sum(i);
            aux /= i;
            root = sqrt(aux);
        }
    }
    
    if (aux == num)
        return 0;
    
    if (aux > 1)
        sum += int_sum(aux);
    
    if (int_sum(num) == sum)
        return 1;
    
    return 0;
}


int main() {
    
    uint cases, n, i, sum, aux;
    
    scanf("%u", &cases);
    while (cases) {
    
        scanf("%u", &n);
        for (i = n + 1; ; i++)
            if (isSmith(i)) {
                printf("%u\n", i);
                break;
            }
         
    
        cases--;    
    }
    
    return 0;
}
