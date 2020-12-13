/* Common Permutation */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *x, const void *y) {
    
    return (*(char *)x - *(char *)y);
}

int main() {
    
    char string1[1002], string2[1002];
    char x[1002], valid[1002];
    int i, j, k, size1, size2;
    int pos;
    
    while (gets(string1)) {
        gets(string2);
        size1 = strlen(string1);
        size2 = strlen(string2);

        qsort(string1, size1, sizeof(char), compare);
        qsort(string2, size2, sizeof(char), compare);
        
        for (i = 0; i < size2; i++)
            valid[i] = 1;
            
        for (i = 0, k = 0, pos = 0; i < size1; i++)
            for (j = pos; j < size2; j++)
                if (valid[j])
                    if (string1[i] == string2[j]) {
                        valid[j] = 0;
                        x[k] = string1[i];
                        k++;
                        break;
                    }
        x[k] = '\0';
        
        qsort(x, k, sizeof(char), compare);
        
        printf("%s\n", x);
    }                
    return 0;
}
