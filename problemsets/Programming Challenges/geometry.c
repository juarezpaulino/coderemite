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
    double a, b, c;
} line;

typedef struct {
    point p[MAXPOLY];
    int n;
} poly;

typedef point triangle[3];

/* Distancia quadrada. */
#define sqr_dist(a, b) (((a.x)-(b.x))*((a.x)-(b.x)) + ((a.y)-(b.y))*((a.y)-(b.y)))

/* Distancia real. */
#define dist(a, b) (sqrt(sqr_dist((a), (b))))

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

void slope_line(point *p, double m, line *l) {
    l->a = -m;
    l->b = 1;
    l->c = -((l->a*p->x) + (l->b*p->y));
}

void intersection_point(line l1, line l2, point *p) {
    
    p->x = (l2.b*l1.c - l1.b*l2.c) / (l2.a*l1.b - l1.a*l2.b);
    if (fabs(l1.b) > EPSILON) /* test for vertical line */
        p->y = - (l1.a * (p->x) + l1.c) / l1.b;
    else
        p->y = - (l2.a * (p->x) + l2.c) / l2.b;
}

void closest_point(point *pin, line l, point *pc) {

    line perp; 
    if (fabs(l.b) <= EPSILON) { 
        pc->x = -(l.c);
        pc->y = pin->y;
        return;
    }
    if (fabs(l.a) <= EPSILON) {
        pc->x = pin->x;
        pc->y = -(l.c);
        return;
    }
    slope_line(pin, 1/l.a, &perp);
    intersection_point(l, perp, pc);
}

/* point_in_box
 * Retorna se o ponto se encontra na caixa b1 e b2. */
bool point_in_box(point *p, point *b1, point *b2) {
    
    return( (p->x >= min(b1->x,b2->x)) && (p->x <= max(b1->x,b2->x))
            && (p->y >= min(b1->y,b2->y)) && (p->y <= max(b1->y,b2->y)) );
}

/* signed_area
 * Retorna a area sinalada do triangula abc. */
double signed_area(point *a, point *b, point *c) {
 
    return ((double)((a->x*b->y) - (a->y*b->x) + (a->y*c->x) - 
                    (a->x*c->y) + (b->x*c->y) - (b->y*c->x))/2.0);
}

/* ccw
 * Retorna TRUE se o conjunto de pontos abc estao em sentido anti-horario.
 * Outra interpretacao: retorna TRUE se c esta a esquerda do segmento ab. */
bool ccw(point *a, point *b, point *c) {
    
    return (signed_area(a, b, c) > EPSILON);
}

/* cw
 * Retorna TRUE se o conjunto de pontos abc estao em sentido horario.
 * Outra interpretacao: retorna TRUE se c esta a direita do segmento ab. */
bool cw(point *a, point *b, point *c) {
    
    return (signed_area(a, b, c) < -EPSILON);
}

/* collinear
 * Retorna TRUE se os pontos abc sao colineares. */
bool collinear(point *a, point *b, point *c) {
    
    return (fabs(signed_area(a, b, c)) < EPSILON);
}

/* leftlower
 * Retorna um valor negativo se o primeiro ponto for "leftlower" */
int leftlower(point *p1, point *p2) {

    return ((p1->y != p2->y)? p1->y - p2->y : p1->x - p2->x);
}

/* Jarvi's March
 *
 * Input: 
 * Set - Conjunto de pontos.
 * m - numero de pontos em set.
 * s - indice do ponto leftlower (mais em baixo e mais a esquerda em empate).
 * Output:
 * poly - poligono convexo em sentido anti-horario.
 */
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


/* point_triangle
 * Retorna TRUE se o ponto p esta dentro do triangulo t. */
bool point_triangle(point *p, triangle t) {
    
    int i;
    
    for (i = 0; i < 3; i++)
        if (cw(&t[i], &t[(i+1)%3], p))
            return (FALSE);
    return (TRUE);
}

/* point_area
 * Retorna a area do poligono. */
double point_area(poly *p) {

    double total;    
    int i;
    
    total = 0.0;
    for (i = 0; i < p->n-1; i++)
        total += (p->p[i].x*p->p[i+1].y) - (p->p[i+1].x*p->p[i].y);
    total += (p->p[i].x*p->p[0].y) - (p->p[0].x*p->p[i].y);
    
    return (total/2.0);
}

/* smaller_angle
 * Permite a ordenacao angular em torno do ponto de origem. */
int smaller_angle(point *a, point *b) {
    
    double area;
    
    area = signed_area(&origin, a, b);
    if (fabs(area) < EPSILON) {
        if (sqr_dist(origin, *a) <= sqr_dist(origin, *b)) return (-1);
        else return (1);
    }
    if (area > EPSILON) return (-1);
    return(1);
}

/* graham
 * */








#define CW -1
#define CCW 1
#define COL 0

#define min(a, b) (((a) < (b))? (a) : (b))
#define max(a, b) (((a) > (b))? (a) : (b))

typedef struct {
    double x, y;
} point;

typedef struct {
    point p[MAXP];
    int n;
} poly;

double dist(point *a, point *b) {
    
    return (sqrt((a->x-b->x)*(a->x-b->x) + (a->y-b->y)*(a->y-b->y)));
}

char direction(point *a, point *b, point *c) {
 
    double area = (double)((a->x*b->y) - (a->y*b->x) + (a->y*c->x) - 
                    (a->x*c->y) + (b->x*c->y) - (b->y*c->x))/2.0;
    
    if (area < -EPSILON) return (CW);
    else if (area > EPSILON) return (CCW);
    return (COL);
}

bool in_poly(poly *p, point *a) {
    
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
            if (fabs(y-cy) < EPSILON) return (FALSE);
            else if (y-cy > EPSILON) c++;
        }
        if (fabs(p->p[i].x-x) < EPSILON) {
            if (fabs(p->p[i].y-y) < EPSILON) return (FALSE);
            if (fabs(p->p[j].x-x) < EPSILON) {
                if (((p->p[i].y-y < EPSILON) && (y-p->p[j].y < EPSILON)) || 
                ((p->p[i].y-y > -EPSILON) && (y-p->p[j].y > -EPSILON)))
                    return (FALSE);
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

bool point_in_box(point *p, point *b1, point *b2) {
    
    if ( ((fabs(p->x-b1->x) < EPSILON) && (fabs(p->y-b1->y) < EPSILON)) ||
         ((fabs(p->x-b2->x) < EPSILON) && (fabs(p->y-b2->y) < EPSILON))  )
        return(FALSE);
    
    return( (p->x >= min(b1->x,b2->x)-EPSILON) && (p->x <= max(b1->x,b2->x)+EPSILON)
    && (p->y >= min(b1->y,b2->y)-EPSILON) && (p->y <= max(b1->y,b2->y)+EPSILON) );
}

bool cross_intersect(point *p1, point *p2, point *p3, point *p4) {
    
    char d1 = direction(p3, p4, p1);
    char d2 = direction(p3, p4, p2);
    char d3 = direction(p1, p2, p3);
    char d4 = direction(p1, p2, p4);

    if ((d1*d2 < 0) && (d3*d4 < 0)) return (TRUE);
        
    if ( (!d1) && (point_in_box(p1, p3, p4)) ) return (TRUE);
    if ( (!d2) && (point_in_box(p2, p3, p4)) ) return (TRUE);
    if ( (!d3) && (point_in_box(p3, p1, p2)) ) return (TRUE);
    if ( (!d4) && (point_in_box(p4, p1, p2)) ) return (TRUE);
    
    return (FALSE);
}
