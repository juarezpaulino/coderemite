/* 109 - SCUD Busters */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 1E-13
#define MAXPOLY 100
#define MAXG 501

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

typedef point triangle[3];

poly kingdom[20];
char map[MAXG][MAXG];

#define sqr_dist(a, b) (((a.x)-(b.x))*((a.x)-(b.x)) + ((a.y)-(b.y))*((a.y)-(b.y)))
#define min(a, b) ((a < b)?(a):(b))
#define min3(a, b, c) min(min((a),(b)), (c))
#define max(a, b) ((a > b)?(a):(b))
#define max3(a, b, c) max(max((a),(b)), (c))

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

bool point_triangle(point *p, triangle t) {
    
    int i;
    
    for (i = 0; i < 3; i++)
        if (signed_area(&t[i], &t[(i+1)%3], p) < -EPSILON)
            return (FALSE);
    return (TRUE);
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

    int i, j, l, h;
    int N, k;
    point s[100];
    triangle t;
    point aux;
    int x, y;
    double area;
    int leftlower();
    
    for (i = 0; i < MAXG; i++)
        for (j = 0; j < MAXG; j++)
            map[i][j] = -1;
    
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

        t[0] = kingdom[k].p[0];
        for (i = 1; i < kingdom[k].n-1; i++) {
            t[1] = kingdom[k].p[i];
            t[2] = kingdom[k].p[i+1];
            for (j = min3(t[0].y,t[1].y,t[2].y); j <= max3(t[0].y,t[1].y,t[2].y); j++)
                for (l = min3(t[0].x,t[1].x,t[2].x); l <= max3(t[0].x,t[1].x,t[2].x); l++) {
                    aux.y = j;
                    aux.x = l;
                    if (point_triangle(&aux, t))
                        map[l][j] = k;
                }
        }
        
        kingdom[k].elec = TRUE;
        k++;
    }
    
    while (scanf("%d %d", &x, &y) != EOF)
        if (map[x][y] >= 0)
            kingdom[(int)map[x][y]].elec = FALSE;
    
    area = 0.0;
    for (i = 0; i < k; i++)
        if (kingdom[i].elec == FALSE)
            area += point_area(&kingdom[i]);
    
    printf("%.2lf\n", area);
    
    return 0;
}
