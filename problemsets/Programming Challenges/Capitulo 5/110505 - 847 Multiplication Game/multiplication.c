/* Multiplication Game */

#include <stdio.h>

unsigned int n;

int main() {

    while (scanf("%u", &n) != EOF) {
        
        if (n > 612220032)
            printf("Stan wins.");
        else if (n > 306110016)
            printf("Ollie wins.");
        else if (n > 34012224)
            printf("Stan wins.");
        else if (n > 17006112)
            printf("Ollie wins.");
        else if (n > 1889568)
            printf("Stan wins.");
        else if (n > 944784)
            printf("Ollie wins.");
        else if (n > 104976)
            printf("Stan wins.");
        else if (n > 52488)
            printf("Ollie wins.");
        else if (n > 5832)
            printf("Stan wins.");
        else if (n > 2916)
            printf("Ollie wins.");
        else if (n > 324)
            printf("Stan wins.");
        else if (n > 162)
            printf("Ollie wins.");
        else if (n > 18)
            printf("Stan wins.");
        else if (n > 9)
            printf("Ollie wins.");
        else
            printf("Stan wins.");
        putchar('\n');
    }
    
    return 0;
}
