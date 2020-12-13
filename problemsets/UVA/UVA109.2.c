/* 109 - SCUD Busters */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 1E-13
#define MAXPOLY 100

typedef char bool;
#define TRUE 1
#define FALSE 0

typedef struct {
    int x, y;
} point;

typedef struct {
    point p[MAXPOLY];
    int n;
    bool elec;
} poly;


#define sqr_dist(a, b) (((a.x)-(b.x))*((a.x)-(b.x)) + ((a.y)-(b.y))*((a.y)-(b.y)))

double signed_area(point *a, point *b, point *c) {
 
    return ((double)((a->x*b->y) - (a->y*b->x) + (a->y*c->x) - 
                    (a->x*c->y) + (b->x*c->y) - (b->y*c->x))/2.0);
}

int leftlower(point *p1, point *p2) {

    return ((p1->y != p2->y)? p1->y - p2->y : p1->x - p2->x);
}

void jarvis(point set[], int m, int s, poly *p) {
    
    int i;
    int x, y;
    double area;
    bool inhull[MAXPOLY];
    
    for (i = 0; i < m; i++)
        inhull[i] = FALSE;
    p->n = 0;
    
    x = s;
    y = (s+1)%m;
    do {
        for (i = 0; i < m; i++)
            if ((!inhull[i]) && (i != y) && (i != x)) {
                area = signed_area(&set[x], &set[y], &set[i]);
                /* Inclui apenas vertices. */
                if ((area < -EPSILON) || 
                ( (fabs(area) < EPSILON) && 
                (sqr_dist(set[x], set[i]) > sqr_dist(set[x], set[y])) )) 
                    y = i;
            }
        x = y;
        inhull[x] = TRUE;
        p->p[p->n++] = set[x];
        y = s;
    } while (x != s);
}

double point_area(poly *p) {

    double total;    
    int i;
    
    total = 0.0;
    for (i = 0; i < p->n-1; i++) {
        total += (double)(p->p[i].x*p->p[i+1].y) - (double)(p->p[i+1].x*p->p[i].y);
        printf("%d %d %.2lf\n", p->p[i].x, p->p[i].y, (double)(p->p[i].x*p->p[i+1].y) - (double)(p->p[i+1].x*p->p[i].y));
    }
    printf("%d %d %.2lf\n", p->p[i].x, p->p[i].y, (double)(p->p[i].x*p->p[0].y) - (double)(p->p[0].x*p->p[i].y));
    total += (p->p[i].x*p->p[0].y) - (p->p[0].x*p->p[i].y);
    
    return (total/2.0);
}


int main() {

    poly kingdom[20];
    int i, j, h;
    int N, k;
    point s[100];
    point aux;
    int x, y;
    double area;
    int leftlower();
    
    k = 0;
    while (scanf("%d", &N)) {

        if (N == -1)
            break;
        
        for (i = 0; i < N; i++)
            scanf("%d %d", &s[i].x, &s[i].y);
        
        qsort(s, N, sizeof(point), leftlower);
        
        h = 1;
        for (i = 0; i < N-1; i++)
            if (leftlower(&s[i], &s[i+1]) != 0)
                s[h++] = s[i+1];
        N = h;
        
        jarvis(s, N, 0, &kingdom[k]);
        
        kingdom[k].elec = TRUE;
        k++;
    }
    
    while (scanf("%d %d", &x, &y) != EOF) {
        aux.x = x;
        aux.y = y;
        for (i = 0; i < k; i++)
            if (kingdom[i].elec) {
                for (j = 0; j < kingdom[i].n; j++)
                    if (signed_area(&kingdom[i].p[j], &kingdom[i].p[(j+1)%kingdom[i].n], &aux) < -EPSILON)
                        break;
                if (j == kingdom[i].n) {
                    kingdom[i].elec = FALSE;
                    break;
                }
            }
    }
    
    area = 0.0;
    for (i = 0; i < k; i++)
        if (kingdom[i].elec == FALSE)
            area += point_area(&kingdom[i]);
    
    printf("%.2lf\n", area);
    
    return 0;
}
