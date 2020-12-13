#include <stdio.h>

char numero[] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};

int main() {
    
    char str[40];
    int i;
    
    while (gets(str)) {
       for (i = 0; str[i]; i++) if (str[i]>='A'&&str[i]<='Z') str[i]=numero[str[i]-'A']+'0';
       puts(str); 
    }
    return 0;
}
