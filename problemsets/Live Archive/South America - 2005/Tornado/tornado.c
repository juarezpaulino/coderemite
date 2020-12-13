/* Tornado! */

#include <stdio.h>


char post[5000];
int n;
int p;

int main() {
    
    int i;
    int init;
    int c;
    
    while (scanf("%d", &n)) {
        if (n == 0) break;
        
        for (i = 0; i < n; i++) scanf("%d", &post[i]);
        
        for (i = 0; (post[i] != 1) && (i < n); i++);
        if (i == n) { init = 2; p = 1; }
        else { init = i; p = 0; }
        
        c = 0;
        for (i = init+1; i != init; i = (i+1)%n) {
            if (post[i] == 0) c++;
            else c = 0;
            if (c == 2) { p++; c = 0; }
        }
        
        printf("%d\n", p);
    }

    return 0;
}
