/* The Closest Pair Problem */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXH 10
#define MAXN 10000


#define dist(a, b) (((a.x)-(b.x))*((a.x)-(b.x))+((a.y)-(b.y))*((a.y)-(b.y)))
#define EPSILON 1E-7

typedef struct {
    double x; 
    double y;
} point;


int n;      /* Numero de pontos. */
point p[MAXN];


int abscissa(point *x, point *y) {
    
    if ((*x).x < (*y).x)
        return (-1);
    return (1);
}


int main() {
    
    double min, m;
    double d;
    int i, j;
    int abscissa();
    
    while (scanf("%d", &n)) {
        
        if (n == 0)
            break;
        
        for (i = 0; i < n; i++)
            scanf("%lf %lf", &p[i].x, &p[i].y);
            
        
        if (n == 1) { printf("INFINITY\n"); continue; }
        
        qsort(p, n, sizeof(point), abscissa);
        
        min = m = 1E15;
        
        for (i = 0; i < n-1; i++)
            for (j = i+1; j < n; j++) {
                if (p[j].x - p[i].x >= min) break;
                if ((d = dist(p[i], p[j])) < m) {
                    m = d;
                    min = sqrt(m);
                }
            }
        
        if (min >= (10000.0 - EPSILON))
            printf("INFINITY\n");
        else
            printf("%.4lf\n", min);
    }
    
    return 0;
}
