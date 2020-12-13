#include <stdio.h>

int main() {
 
    int num, i, deg; char str[1001];
    
    while (gets(str)) {
        if (*str == '0') break;
        for (i = num = 0; str[i]; i++) num += str[i]-'0';
        if (num%9) { printf("%s is not a multiple of 9.\n", str); continue; }
        deg = 1;
        while (num != 9) {
            i = 0; while (num) { i += num%10; num/=10; } num = i; deg++;
        }
        printf("%s is a multiple of 9 and has 9-degree %d.\n", str, deg);
    }
    
    return 0;
}
