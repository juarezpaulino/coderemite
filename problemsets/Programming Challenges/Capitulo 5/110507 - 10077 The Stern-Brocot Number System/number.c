/* The Stern-Brocot Number System */

#include <stdio.h>

#define ERROR 0.000000001

typedef struct {
    unsigned numerator;
    unsigned denominator;
} rational;


int main() {
    
    rational left, right, pos, num;
    double aux, target;
    
    while (1) {
        
        scanf("%u %u", &num.numerator, &num.denominator);
        
        if ((num.numerator == 1) && (num.denominator == 1))
            break;
            
        target = (double) num.numerator / (double) num.denominator;
        pos.numerator = 1;
        pos.denominator = 1;
        left.numerator = 0;
        left.denominator = 1;
        right.numerator = 1;
        right.denominator = 0;
        
        while (1) {
            if ((pos.numerator == num.numerator) && (pos.denominator == num.denominator))
                break;
            aux = (double) pos.numerator / (double) pos.denominator;
            if ((target > aux - ERROR) && (target < aux + ERROR))
                break;
            if (target < aux) {
                putchar('L');
                right.numerator = pos.numerator;
                right.denominator = pos.denominator;
                pos.numerator += left.numerator;
                pos.denominator += left.denominator;
            }
            else {
                putchar('R');
                left.numerator = pos.numerator;
                left.denominator = pos.denominator;
                pos.numerator += right.numerator;
                pos.denominator += right.denominator;
            }
        }
        putchar('\n');
    }
    
    return 0;
}
