#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXC 1000

#define EPSILON 1E-14

typedef struct Dark {
    double st, end;
    struct Dark *next;
} dark;

typedef struct {
    double x, y;
} point;

typedef struct {
    double a, b, c;
} line;

typedef struct {
    point c;
    double rad;
} circle;


point bulbs[MAXC];
circle column[MAXC];
int l, c, w, h;


#define sqr_dist(a, b) (((a)->x-(b)->x)*((a)->x-(b)->x) + ((a)->y-(b)->y)*((a)->y-(b)->y))
#define dist(a, b) (sqrt(sqr_dist((a),(b))))


void tangency_points(point *bulb, circle *col, point *p1, point *p2) {
    
    double a, dx, dy, d, h, rx, ry, r0;
    double x1 = col->c.x, y1 = col->c.y;
    double r1 = col->rad;
    double x0 = bulb->x, y0 = bulb->y;
    double x2, y2;
  
    dx = x1 - x0;
    dy = y1 - y0;

    d = sqrt((dy*dy) + (dx*dx));
  
    r0 = sqrt((d*d) - (r1*r1));

    a = ((r0*r0) - (r1*r1) + (d*d)) / (2.0 * d) ;

    x2 = x0 + (dx * a/d);
    y2 = y0 + (dy * a/d);

    h = sqrt((r0*r0) - (a*a));

    rx = -dy * (h/d);
    ry = dx * (h/d);

    p1->x = x2 + rx;
    p2->x = x2 - rx;
    p1->y = y2 + ry;
    p2->y = y2 - ry;
}

void points_line(point *p1, point *p2, line *l) {
    if (p1->x == p2->x) {
        l->a = 1;
        l->b = 0;
        l->c = -p1->x;
    } else {
        l->b = 1;
        l->a = -(p1->y-p2->y)/(p1->x-p2->x);
        l->c = -(l->a * p1->x) - (l->b * p1->y);
    }
}

double linnearize(point *p) {
    
    if (p->x < EPSILON) return (p->y);
    else if (fabs(p->y - h) < EPSILON) return (h + p->x);
    else if (fabs(p->x - w) < EPSILON) return (h + w + (h - p->y));
    return (h + w + h + (w - p->x));
}

double signed_area(point *a, point *b, point *c) {
 
    return ((double)((a->x*b->y) - (a->y*b->x) + (a->y*c->x) - 
                    (a->x*c->y) + (b->x*c->y) - (b->y*c->x))/2.0);
}

void add_part(dark **area, dark *d) {
    
    dark *pt, *ptaux, *ptant;
    
    
    pt = *area; ptant = NULL;
    while (pt) {
        if ((d->st-pt->st > -EPSILON) && (pt->end-d->st > -EPSILON)) {
            if (d->end-pt->end > -EPSILON) {
                ptaux = pt->next;
                while (ptaux && (d->end-ptaux->st > -EPSILON)) {
                    if (ptaux->end > d->end) d->end = ptaux->end;
                    d->next = ptaux->next;
                    free(ptaux);
                    ptaux = d->next;
                }
                pt->end = d->end;
                pt->next = ptaux;
            }
            free(d);
            break;
        }
        if ((pt->st-d->st > -EPSILON) && (d->end-pt->st > -EPSILON)) {
            pt->st = d->st;
            if (d->end-pt->end > EPSILON) {
                ptaux = pt->next;
                while (ptaux && (d->end-ptaux->st > -EPSILON)) {
                    if (ptaux->end > d->end) d->end = ptaux->end;
                    d->next = ptaux->next;
                    free(ptaux);
                    ptaux = d->next;
                }
                pt->end = d->end;
                pt->next = ptaux;
            }
            free(d);
            break;
        }
        if (pt->st-d->st > -EPSILON) {
            d->next = pt;
            if (ptant == NULL) *area = d;
            else ptant->next = d;
            break;
        }
        ptant = pt;
        pt = pt->next;
    }
    if (pt == NULL)
        ptant->next = d;
}

void append_dark(dark **area, point *pc, circle *col, point *t1, point *t2, line *l1, line *l2) {
    
    point p1, p2;
    double m1, m2, maux;
    point aux;
    dark *d;
    char found;
    
    /* Get point for first line. */
    found = 0;
    if (fabs(l1->b) > EPSILON) {
        aux.x = 0.0; aux.y = -l1->c/l1->b;
        if ((aux.y > EPSILON) && (aux.y < h+EPSILON)
            && (dist(&aux, pc) > dist(&aux, t1))) {
                found = 1;
                p1 = aux;
        }
        aux.x = w; aux.y = -(l1->a*w + l1->c) / l1->b;
        if (!found && (aux.y > EPSILON) && (aux.y < h+EPSILON)
            && (dist(&aux, pc) > dist(&aux, t1))) {
                found = 1;
                p1 = aux;
        }
    }
    if (fabs(l1->a) > EPSILON) {
        aux.y = 0.0; aux.x = -l1->c/l1->a;
        if (!found && (aux.x > EPSILON) && (aux.x < w+EPSILON)
            && (dist(&aux, pc) > dist(&aux, t1))) {
                found = 1;
                p1 = aux;
        }
        aux.y = h; aux.x = -(l1->b*h + l1->c) / l1->a;
        if (!found && (aux.x > EPSILON) && (aux.x < w+EPSILON)
            && (dist(&aux, pc) > dist(&aux, t1))) {
                found = 1;
                p1 = aux;
        }
    }
    m1 = linnearize(&p1);
    
    /* Get point for second line. */
    found = 0;
    if (fabs(l2->b) > EPSILON) {
        aux.x = 0.0; aux.y = -l2->c/l2->b;
        if ((aux.y > EPSILON) && (aux.y < h+EPSILON)
            && (dist(&aux, pc) > dist(&aux, t2))) {
                found = 1;
                p2 = aux;
        }
        aux.x = w; aux.y = -(l2->a*w + l2->c) / l2->b;
        if (!found && (aux.y > EPSILON) && (aux.y < h+EPSILON)
            && (dist(&aux, pc) > dist(&aux, t2))) {
                found = 1;
                p2 = aux;
        }
    }
    if (fabs(l2->a) > EPSILON) {
        aux.y = 0.0; aux.x = -l2->c/l2->a;
        if (!found && (aux.x > EPSILON) && (aux.x < w+EPSILON)
            && (dist(&aux, pc) > dist(&aux, t2))) {
                found = 1;
                p2 = aux;
        }
        aux.y = h; aux.x = -(l2->b*h + l2->c) / l2->a;
        if (!found && (aux.x > EPSILON) && (aux.x < w+EPSILON)
            && (dist(&aux, pc) > dist(&aux, t2))) {
                found = 1;
                p2 = aux;
        }
    }
    m2 = linnearize(&p2);
    
    if (signed_area(pc, &col->c, &p1) < -EPSILON) {
        maux = m1;
        m1 = m2;
        m2 = maux;
    }

    if (m1 > m2) {
        d = (dark *) malloc(sizeof(dark));
        d->st = 0.0;
        d->end = m2;
        d->next = NULL;
        if (*area == NULL) *area = d;
        else add_part(area, d);
        d = (dark *) malloc(sizeof(dark));
        d->st = m1;
        d->end = 2.0*h+2.0*w;
        d->next = NULL;
        add_part(area, d);
    }
    else {
        d = (dark *) malloc(sizeof(dark));
        d->st = m1;
        d->end = m2;
        d->next = NULL;
        if (*area == NULL) *area = d;
        else add_part(area, d);
    }
}

dark *merge(dark *total, dark *area) {
    
    dark *pt1, *pt2, *pt, *d, *ret;
    
    pt = NULL; ret = NULL;
    pt1 = total; pt2 = area;
    while (pt1 && pt2) {
        if ((pt2->st-pt1->st > -EPSILON) && (pt1->end-pt2->st > -EPSILON)) {
            if (pt1->end-pt2->end > -EPSILON) {
                d = (dark *) malloc(sizeof(dark));
                d->st = pt2->st; d->end = pt2->end; d->next = NULL;
                if (pt) pt->next = d;
                else ret = d;
                pt = d;
                pt2 = pt2->next;
                continue;
            }
            else {
                d = (dark *) malloc(sizeof(dark));
                d->st = pt2->st; d->end = pt1->end; d->next = NULL;
                if (pt) pt->next = d;
                else ret = d;
                pt = d;
                pt1 = pt1->next;
                continue;
            }
        }
        if ((pt1->st-pt2->st > -EPSILON) && (pt2->end-pt1->st > -EPSILON)) {
            if (pt2->end-pt1->end > -EPSILON) {
                d = (dark *) malloc(sizeof(dark));
                d->st = pt1->st; d->end = pt1->end; d->next = NULL;
                if (pt) pt->next = d;
                else ret = d;
                pt = d;
                pt1 = pt1->next;
                continue;
            }
            else {
                d = (dark *) malloc(sizeof(dark));
                d->st = pt1->st; d->end = pt2->end; d->next = NULL;
                if (pt) pt->next = d;
                else ret = d;
                pt = d;
                pt2 = pt2->next;
                continue;
            }
        }
        if (pt2->st-pt1->end > -EPSILON) pt1 = pt1->next;
        else pt2 = pt2->next;
    }
    
    return ret;
}

double sum_dark(dark *total) {
    
    double sum = 0.0;
    dark *pt = total, *ptaux;
    
    ptaux = NULL;
    while (pt) {
        sum += pt->end-pt->st;
        ptaux = pt;
        pt = pt->next;
        free(ptaux);
    }
    
    return sum;
}


int main() {

    int i, j;
    dark *total, *cur;
    int x, y, r;
    point p1, p2;
    line l1, l2;
    double sum;

    while (scanf("%d %d %d %d", &l, &c, &w, &h)) {
        
        if (!l && !c && !w && !h) break;
        
        for (i = 0; i < l; i++) {
            scanf("%d %d", &x, &y);
            bulbs[i].x = x;
            bulbs[i].y = y;
        }
        
        for (i = 0; i < c; i++) {
            scanf("%d %d %d", &x, &y, &r);
            column[i].c.x = x;
            column[i].c.y = y;
            column[i].rad = r;
        }
        
        total = NULL;
        
        for (i = 0; i < l; i++) {
            cur = NULL;
            for (j = 0; j < c; j++) {
                tangency_points(&bulbs[i], &column[j], &p1, &p2);
                points_line(&bulbs[i], &p1, &l1);
                points_line(&bulbs[i], &p2, &l2);
                append_dark(&cur, &bulbs[i], &column[j], &p1, &p2, &l1, &l2);
            }
            if (total == NULL) total = cur;
            else total = merge(total, cur);
        }
        sum = sum_dark(total);
        sum = 2.0*h+2.0*w-sum;
        printf("%.4lf\n", sum);
    }   
    
    return 0;
}
