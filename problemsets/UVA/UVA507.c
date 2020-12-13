/* 507 - Jill rides again */

#include <stdio.h>

#define MAXV 20000


int stop[MAXV];
int sum[MAXV];
int max, maxst, maxend;



int main() {
    
    int c;
    int n;
    int k, i, st;
    
    scanf("%d", &c);
    for (k = 1; k <= c; k++) {
        scanf("%d", &n);
        
        for (i = 0; i < n-1; i++) scanf("%d", &stop[i]);
        
        sum[0] = max = stop[0]; maxst = 1; maxend = 2; st = 1;
        for (i = 1; i < n-1; i++) {
            if (sum[i-1] >= 0) sum[i] = sum[i-1] + stop[i];
            else { sum[i] = stop[i]; st = i+1; }
            if ((sum[i] > max) || ((sum[i] == max) && (i+2-st > maxend-maxst))) {
                max = sum[i];
                maxst = st; maxend = i+2;
            }
        }
        
        if (max <= 0) printf("Route %d has no nice parts\n", k);
        else printf("The nicest part of route %d is between stops %d and %d\n", k, maxst, maxend);
    }   
    
    return 0;    
}
