/* Optical Fiber */

#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct {
    int x, y;
    double d;
} point;

typedef struct {
    int n;
    point loc[50];
} city;

short degree[1000];
short input[2][1000];
char valid[1000];
char name[1000][16];
city c[1000];

double dist(point *a, point *b) {
    
    return (sqrt((a->x-b->x)*(a->x-b->x)+(a->y-b->y)*(a->y-b->y)));
}

void newl() {
    
    char ch;
    
    while (((ch = getchar()) != '\n') && (ch != EOF));
}


int main() {

    int n;
    int i, j, k;
    int v;
    double d, min;
    char a[16], b[16];
    int ia, ib;
    int x, y;

    while (scanf("%d", &n)) {
        
        if (n == 0) break;
        
        newl();
        for (i = 0; i < n; i++) {
            degree[i] = 0;
            c[i].n = 0;
            scanf("%s", name[i]);
            scanf("%d", &c[i].n);
            for (j = 0; j < c[i].n; j++) {
                scanf("%d %d", &c[i].loc[j].x, &c[i].loc[j].y);
                c[i].loc[j].d = 0.0;
            }
            newl();
        }
        
        if (n == 1) { printf("0.0\n"); continue; }
        
        for (i = 0; i < n-1; i++) {
            scanf("%s %s", a, b);
            newl();
            for (ia = 0; ia < n; ia++) if (!strcmp(a, name[ia])) break;
            for (ib = 0; ib < n; ib++) if (!strcmp(b, name[ib])) break;
            degree[ia]++; degree[ib]++;
            input[0][i] = ia; input[1][i] = ib;
            valid[i] = 1;
        }
        
        v = 0;
        while (v < n-1) {
            for (i = 0; i < n-1; i++) {
                if ((valid[i]) && ((degree[input[0][i]] == 1) || (degree[input[1][i]] == 1))) {
                    if (degree[input[0][i]] == 1) { x = input[0][i]; y = input[1][i]; }
                    else { x = input[1][i]; y = input[0][i]; }
                    for (j = 0; j < c[y].n; j++) {
                        min = 1E14;
                        for (k = 0; k < c[x].n; k++)
                            if ((d = (dist(&c[x].loc[k], &c[y].loc[j])+c[x].loc[k].d)) < min)
                                min = d;
                        c[y].loc[j].d += min;
                    }   
                    valid[i] = 0;
                    v++;
                    degree[x]--; degree[y]--;
                    ia = y;
                }
            }
        }
        
        d = 1E14;
        for (i = 0; i < c[ia].n; i++)
            if (c[ia].loc[i].d < d)
                d = c[ia].loc[i].d;
        
        printf("%.1lf\n", d);
    }    
    
    return 0;
}
