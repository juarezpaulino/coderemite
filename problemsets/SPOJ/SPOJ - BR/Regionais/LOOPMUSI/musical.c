#include <stdio.h>
#include <stdlib.h>


int main() {

    int i, n;
    int val[10000];
    int m;
    int s1, s2;
    
    while (scanf("%d", &n)) {
        
        if (!n) break;
        
        for (i = 0; i < n; i++) scanf("%d", &val[i]);
        
        m = 0;
        for (i = 0; i < n; i++) {
            s1 = (val[i] < val[(i+n-1)%n]) ? 0 : 1;
            s2 = (val[i] < val[(i+1)%n]) ? 0 : 1;
            if (!(s1^s2)) m++;
        }
        
        printf("%d\n", m);
    }
    
    return 0;
}
