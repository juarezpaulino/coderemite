#include <stdio.h>

int main() {

    int f[51], i, n;
    
    f[1] = 1;
    
    for (i = 2; i < 51; i++)
        f[i] = f[i-1] + 2*(((i-1)/2)+1);
        
    scanf("%d", &i);
    while (i) {
        
        scanf("%d", &n);
        
        printf("%d\n", f[n]);
        
        i--;
    }
    
    return 0;
}
