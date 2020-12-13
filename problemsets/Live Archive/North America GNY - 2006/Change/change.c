/* Quick change */

#include <stdio.h>


typedef struct {
    int v;
    int n;
    int p;
} coin;


coin change[501];
int n;
int c;
int type[4];
int count[4];


void build(int c) {
    
    if (change[c].p == -1) return;
    
    count[change[c].v]++;
    build(change[c].p);
}


int main() {
    
    int i, j;    

    type[0] = 1; type[1] = 5; type[2] = 10; type[3] = 25;
    change[0].n = 0; change[0].p = -1;
    for (i = 1; i <= 500; i++) {
        change[i].n = 1000000000;
        for (j = 0; j < 4; j++) {
            if (((i-type[j]) >= 0) && (change[i-type[j]].n+1 < change[i].n)) {
                change[i].n = change[i-type[j]].n+1;
                change[i].v = j;
                change[i].p = i-type[j];
            }
        }
    }

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &c);
        for (j = 0; j < 4; j++) count[j] = 0;
        build(c);
        printf("%d ", i);
        printf("%d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n",
        count[3], count[2], count[1], count[0]);
    }
    
}
