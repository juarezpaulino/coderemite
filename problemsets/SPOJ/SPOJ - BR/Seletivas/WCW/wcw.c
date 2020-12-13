#include <stdio.h>
#include <stdlib.h>


#define MAXC 10000

char disc[MAXC];
int num[MAXC];
int t, n;
int min;


int main() {
    
    int i;
    int pos, s;
    
    scanf("%d", &t);
    
    while (t--) {
     
        scanf("%d", &n);
        for (i = 0; i < n; i++) { 
            scanf("%d", &s);
            num[i] = s-1;
            disc[i] = 0;
        }
        
        min = pos = s = 0;
        while (pos != n) {
            if (disc[pos]) {
                if (s > 0) { min += s-1; s = 0; }
                pos++;
            }
            else {
                disc[pos] = 1;
                pos = num[pos];
                s++;
            }
        }
        
        printf("%d\n", min);
    }
    
    return 0;
}
