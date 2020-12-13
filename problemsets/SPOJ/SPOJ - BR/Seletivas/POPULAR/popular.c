#include <stdio.h>

int n;

int main() {
 
    int i, j, k, s, vote[100];
    char str[300], ch;
 
    while (scanf("%d ", &n)) {
        if (!n) break;
        for (i = 0; i < n; i++) vote[i] = 0;
        for (k = 0; k < n; k++){
            gets(str);
            for (i = j = 0; str[i]; i++) {
                ch = str[i]-'0';
                if (ch==0 || ch==1) { if (ch) vote[j]++; j++; }
            }
        }
        s = 0; for (i = 0; i < n; i++) if (vote[i] > s) s = vote[i];
        printf("%d\n", s);
    }   
    
    return 0;
}
