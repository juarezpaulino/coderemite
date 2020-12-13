#include <stdio.h>

char str[1001];


int main() {
    
    int s, i;
    while (gets(str)) {
        if (*str=='0' && !str[1]) break;
        s = 0; for (i = 0; str[i]; i++) if (i&1) s+=str[i]-'0'; else s-=str[i]-'0';
        if (s%11) printf("%s is not a multiple of 11.\n", str);
        else printf("%s is a multiple of 11.\n", str);
    }
     
    return 0;
}
