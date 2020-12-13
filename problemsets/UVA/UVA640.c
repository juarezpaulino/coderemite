/* 640 - Self Numbers */

#include <stdio.h>


char gen[1000001];


void d(int val) {
    
    int i;
    int x = val;
    
    for (i = val; i; i /= 10) x += i%10;
    
    if (x <= 1000000)
    gen[x] = 1;
}


int main() {
    
    int i;
    
    for (i = 1; i <= 1000000; i++) {
        d(i);
        if (!gen[i])
            printf("%d\n", i);
    }
    
    return 0;
}
