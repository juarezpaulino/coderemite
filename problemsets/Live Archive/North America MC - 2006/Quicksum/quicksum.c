/* Quicksum */

#include <stdio.h>

char str[500];

int quicksum() {

    int i;
    int s;
        
    s = 0;
    for (i = 0; str[i] != '\0'; i++)
        if (str[i] != ' ')
            s += (str[i]-'A'+1) * (i+1);
    return (s);
}


int main() {

    int sum;

    while (gets(str)) {
        
        if (str[0] == '#') break;
        
        sum = quicksum();
        
        printf("%d\n", sum);
    }
    
    return 0;
}
