/* Invert and add */

#include <stdio.h>
#include <string.h>

unsigned int reverse(unsigned int num) {

    char number[15], aux[15];
    int size, i, j;
    unsigned int aux_number;
    
    sprintf(number, "%u%n", num, &size);
    for (i = size - 1, j = 0; i >= 0; i--, j++)
        aux[j] = number[i];
    aux[j] = '\0';
    
    sscanf(aux, "%u", &aux_number);
    
    return (aux_number);
}
    
int ispalindrome(int num) {
    
    char number[15];
    int size, i;
    
    sprintf(number, "%u%n", num, &size);
    for (i = 0; i < size/2; i++)
        if (number[i] != number[size - 1 - i])
            return -1;
    return 1;
}
    
   
int main() {

    int cases;
    unsigned int num, rev, add;
    
    scanf("%d", &cases);
    while (cases) {
    
        scanf("%u", &num);
        add = 0;
        while (ispalindrome(num) == -1) {
            rev = reverse(num);
            num += rev;
            add++;
        }
        
        printf("%u %u\n", add, num);
                
        cases--;
    }   
    
    return 0;
}
