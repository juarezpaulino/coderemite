/* Falling Ice */


#include <stdio.h>
#include <nath.h>

typedef struct {
    double x, y;
} point;

typedef struct {
    point c;
    double r;
} circle;


double xmax;
int n;
int w;
point ice[15];


double dist(point *a, point *b) {
    
    return (sqrt((a->x-b->x)*(a->x-b->x)+(a->y-b->y)*(a->y-b->y)));    
}


int main() {
    
    int i, j;
    int d;
    
    while (scanf("%d", &w)) {
        
        if (!w) break;
        
        scanf("%d", &n);
        scanf("%d", &d);
        ice[0].x = (double)(d)/2.0; ice[0].y = (double)(d)/2.0;
        xmax = d;
        for (i = 1; i < n; i++) {
            
        }
    }
    
    return 0;
}
