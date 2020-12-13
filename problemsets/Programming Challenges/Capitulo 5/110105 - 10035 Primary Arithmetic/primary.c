/* Primary Arithmetic */

#include <stdio.h>
#include <string.h>

int main() {

    char num1[15], num2[15];
    unsigned int n1, n2;
    int i, j, carry, s1, s2, sum;
    char aux;
    
    while (1) {
        
        scanf("%u %u", &n1, &n2);
        if ((n1 == 0) && (n2 == 0))
            break;
        
        for (i = 0; i < 15; i++) {
            num1[i] = 0;
            num2[i] = 0;
        }
        num1[i] = '\0';
        num2[i] = '\0';
        
        j = n1;
        i = -1;
        while (j > 0) {
            i++;
            num1[i] = (j % 10);
            j /= 10;
        }
        if (i == -1)
            s1 = 1;
        else
            s1 = i+1;
        
        j = n2;
        i = -1;
        while (j > 0) {
            i++;
            num2[i] = (j % 10);
            j /= 10;
        }
        if (i == -1)
            s2 = 1;
        else
            s2 = i+1;
        
        carry = aux = 0;
        
        sum = -1;
        for (i = 0; i < 14; i++) {
            sum = 0;
            
            if (i < s1)
                sum += num1[i];
            if (i < s2)
                sum += num2[i];
            sum += aux;
            if (sum / 10) {
                carry++;
                aux = 1;
            }
            else
                aux = 0;
        }
        
        if (carry > 1)
            printf("%d carry operations.\n", carry);
        else if (carry == 1)
            printf("1 carry operation.\n");
        else
            printf("No carry operation.\n");
    }
    
    return 0;
}
