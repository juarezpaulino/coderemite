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

int getint() {

    int ch, i, sign = 1;
    while (((ch = getchar()) == ' ') || (ch == '\n'));

    if (ch == EOF) return (EOF);

    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');

    return i;
}


int main() {

    int i, j, u;
    int t;
    long long c;
    int road_cmp();
    
    t = getint();
    for (i = 1; i <= t; i++) {
        n = getint(); m = getint(); k = getint();
        if (m < n) n^=m^=n^=m;
        for (j = 0; j < k; j++) { r[j].x = getint(); r[j].y = getint(); }
        
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
