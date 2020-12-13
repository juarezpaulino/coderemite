/* Japan */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} road;

road r[1000005];
int n, m, k;
int down[1005];


int road_cmp(road *a, road *b) {

    if (a->y != b->y) return (b->y-a->y);
    return (b->x-a->x);    
}


int main() {

    int i, j, u;
    int t;
    long long c;
    int road_cmp();
    
    scanf("%d", &t);
    for (i = 1; i <= t; i++) {
        scanf("%d %d %d", &n, &m, &k);
        
        /* Swap das variaveis pra otimizar */
        if (m < n) n^=m^=n^=m;
        
        for (j = 0; j < k; j++) scanf("%d %d", &r[j].x, &r[j].y);
        
        qsort(r, k, sizeof(road), road_cmp);
        
        for (j = 1; j <= n; j++) down[j] = 0;
        
        c = 0LL;
        for (j = 0; j < k; j++) {
            c = c + down[r[j].x];
            for (u = r[j].x+1; u <= n; u++) down[u]++;
        }
        
        printf("Test case %d: %lld\n", i, c);
    }
    
    return 0;
}
