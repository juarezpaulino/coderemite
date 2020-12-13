#include <stdio.h>
#include <stdlib.h>

int n;
int num[100001], ind[100001];


int main() {
    
    int i, s;
    
    while (scanf("%d", &n)) {
        
        if (!n) break;
        
        for (i = 1; i <= n; i++) { scanf("%d", &num[i]); ind[num[i]] = i; }
        
        s = 0;
        for (i = 1; i <= n; i++)
            if (i != num[i]) {
                s += ((ind[i]-i)<<1) - 1;
                ind[num[i]] = ind[i];
                num[ind[i]] = num[i];
            }
        
        if (s&1) puts("Marcelo");
        else puts("Carlos");
    }
    
    return 0;
}
