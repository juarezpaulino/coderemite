#include <stdio.h>
#include <stdlib.h>

int n, d;
char num[100000];
int top;

int main() {
    
    char ch;
    int i, m;
    
    while (scanf("%d %d ", &n, &d)) {
        
        if (!n && !d) break;
        
        top = -1;
        
        m = n-d;
        
        num[++top] = getchar();
        for (i = 1; (i < n) && (d); i++) {
            ch = getchar();
            while ((top >= 0) && (ch > num[top]) && d) { d--; top--; }
            num[++top] = ch;
        }
        
        for (; i < n; i++) {
            ch = getchar();
            if (i < n-d) num[++top] = ch;
        }
        
        for (i = 0; i < m; i++) putchar(num[i]);
        putchar('\n');
    }
    
    return 0;
}
