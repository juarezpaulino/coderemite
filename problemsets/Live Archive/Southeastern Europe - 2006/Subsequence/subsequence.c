/* Subsequence */

#include <stdio.h>


int n, s;
int num[100010];

int getint() {

    int ch, i, sign = 1;
    while (((ch = getchar()) == ' ') || (ch == '\n'));

    if (ch == EOF) return (EOF);

    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');

    return i;
}


int main() {
    
    int i;
    int sum;
    int st;
    int min;
    
    while ((n = getint()) != EOF) {
   
        s = getint();
        for (i = 0; i < n; i++) num[i] = getint();
        
        sum = 0; st = 0; min = 1000000000;
        for (i = 0; i < n; i++) {
            sum = sum + num[i];
            while ((sum >= s) && (st <= i)) {
                if (min > i-st+1) min = i-st+1;
                sum = sum - num[st];
                st++;
            }
        }
        
        if (min == 1000000000) printf("0\n");
        else printf("%d\n", min);
    }
    
    return 0;    
}
