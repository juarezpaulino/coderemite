/* Volei Marciano */

#include <stdio.h>

#define EPSILON 1E-10

typedef struct {
    double x, y;
} point;

typedef struct {
    point p[100];
    int n;
} poly;

typedef struct {
    int c[50];
    int nc;
} cross;

poly quad;
int ver[50], hor[50];       /* Guarda abscissas e ordenadas dos juizes */
int nv, nh;
cross c[50];                /* Guarda para cada juiz de abscissa os cruzamentos com ordenadas */
char used[50];              /* Testa se uma determinada horizontal já foi usada */    
int n;
int m;                      /* Numero final de juizes */


int in_poly(poly *p, point *a) {
    
    int i, j, h;
    int c = 0;
    double cy;
    double t;
    double x = a->x, y = a->y;

    for (i = 0; i < n; i++) {
        j = (i+1)%n;
        if (((p->p[i].x-x < -EPSILON) && (x-p->p[j].x < -EPSILON)) 
        || ((p->p[i].x-x > EPSILON) && (x-p->p[j].x > EPSILON))) {
            t = (x - p->p[j].x) / (p->p[i].x - p->p[j].x);
            cy = t*p->p[i].y + (1.0-t)*p->p[j].y;
            if (fabs(y-cy) < EPSILON) return (1);
            else if (y-cy > EPSILON) c++;
        }
        if (fabs(p->p[i].x-x) < EPSILON) {
            if (fabs(p->p[i].y-y) < EPSILON) return (1);
            if (fabs(p->p[j].x-x) < EPSILON) {
                if (((p->p[i].y-y < EPSILON) && (y-p->p[j].y < EPSILON)) || 
                ((p->p[i].y-y > -EPSILON) && (y-p->p[j].y > -EPSILON)))
                    return (1);
            }
            else {
                if (p->p[i].y-y < -EPSILON) {
                    for (h = (i+n-1)%n; ; h = (h+n-1)%n)
                        if (fabs(p->p[h].x-x) > EPSILON) break;
                    if (((p->p[h].x-x > EPSILON) && (x-p->p[j].x > EPSILON))||
                    ((p->p[h].x-x < -EPSILON) && (x-p->p[j].x < -EPSILON)))
                        c++;
                }
            }
        }
    }
    
    return (c&1);
}

int cmp(cross *a, cross *b) {

    return (a->nc-b->nc);    
}


int main() {
    
    int i, j;
    int k;          /* k = 0 -> vertical | k = 1 -> horizontal */
    int x1, y1, x2, y2;
    point aux;
    int cmp();
    
    while (scanf("%d", &n)) {
        
        if (!n) break;
        
        m = nv = nh = 0;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        quad.p[0].x = x1; quad.p[0].y = y1;
        quad.p[1].x = x2; quad.p[1].y = y2;
        quad.n = n;
        
        if (x1 == x2) { ver[nv++] = x1; m++; k = 1; }
        else { hor[nh++] = y1; m++; k = 0; }
        
        for (i = 2; i < n; i++) {
            scanf("%d %d", &x1, &y1);
            quad.p[i].x = x1; quad.p[i].y = y1;
            
            if (!k) {
                for (j = 0; j < nv; j++) if (ver[j] == x1) break;
                if (j == nv) { ver[nv++] = x1; m++; }
            }
            else {
                for (j = 0; j < nh; j++) if (hor[j] == y1) break;
                if (j == nh) { hor[nh++] = y1; m++; }
            }
            
            k ^= 1;
        }
        if (!k) {
            for (j = 0; j < nv; j++) if (ver[j] == x1) break;
            if (j == nv) { ver[nv++] = x1; m++; }
        }
        else {
            for (j = 0; j < nh; j++) if (hor[j] == y1) break;
            if (j == nh) { hor[nh++] = y1; m++; }
        }
        
        /* Computa cruzamentos */
        for (i = 0; i < nv; i++) {
            c[i].nc = 0;
            for (j = 0; j < nh; j++) {
                aux.x = ver[i]; aux.y = hor[j];
                if (!in_poly(&quad, &aux))
                    c[i].c[c[i].nc++] = j;
            }
        }
        qsort(c, nv, sizeof(cross), cmp);
        
        /* Reduz m */
        for (i = 0; i < nh; i++) used[i] = 0;
        
        for (i = 0; i < nv; i++)
            for (j = 0; j < c[i].nc; j++)
                if (!used[c[i].c[j]]) {
                    m--;
                    used[c[i].c[j]] = 1;
                    break;
                }
        
        printf("%d\n", m);
    }
    
    return 0;
}
