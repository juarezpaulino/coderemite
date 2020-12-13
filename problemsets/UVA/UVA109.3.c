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

poly kingdom[20];

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

bool in_poly(poly *p, point *a) {
    
    int i, j, h;
    int c = 0;
    double cy;
    double t;
    double x = a->x, y = a->y;

    for (i = 0; i < p->n; i++) {
        j = i+1;
        if (((p->p[i].x < x) && (x < p->p[j].x)) 
        || ((p->p[i].x > x) && (x > p->p[j].x))) {
            t = (double)(x - p->p[j].x) / (double)(p->p[i].x - p->p[j].x);
            cy = t*p->p[i].y + (1.0-t)*p->p[j].y;
            if (fabs(y-cy) < EPSILON) return (FALSE);
            else if (y-cy > EPSILON) c++;
        }
        if (p->p[i].x == x) {
            if (p->p[i].y == y) return (FALSE);
            if (p->p[j].x == x) {
                if (((p->p[i].y <= y) && (y <= p->p[j].y)) || 
                ((p->p[i].y >= y) && (y >= p->p[j].y)))
                    return (FALSE);
            }
            else {
                if (p->p[i].y < y) {
                    for (h = (i+p->n-1)%p->n; ; h = (h+p->n-1)%p->n)
                        if (p->p[h].x == x) break;
                    if (((p->p[h].x > x) && (x > p->p[j].x))||
                    ((p->p[h].x < x) && (x < p->p[j].x)))
                        c++;
                }
            }
        }
    } 
    return (c&1);
}

double point_area(poly *p) {

    double total;    
    int i;
    
    total = 0.0;
    for (i = 0; i < p->n-1; i++)
        total += (p->p[i].x*p->p[i+1].y) - (p->p[i+1].x*p->p[i].y);
    total += (p->p[i].x*p->p[0].y) - (p->p[0].x*p->p[i].y);
    
    return (total/2.0);
}


int main() {

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
                if (in_poly(&kingdom[i], &aux)) {
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
