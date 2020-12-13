/* Mission Impossible */

////////////////////////////////////////////////////////////////////////////////
// Steps:
//          1 - Eliminate all circles inside circles.
//          2 - Eliminate all informers inside circles.
//          3 - Compute the insider coefficient for each of the remaining informers.
//              3.1 - Check minimun distance to each segment border.
//          4 - Sort informers by coefficient in decreasing order.
//          5 - Build a graph connecting each radar that touches each other.
//              5.1 - For each cycle in this graph, you can get a polygon with
//                    radar center points. Save these polygon on memory.
//          6 - Find the first informer reachable on the previous computed order:
//              6.1 - It is reachable if is not inside of any of the pre-computed
//                    polygons.
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 1E-14
#define INF 1E14

typedef char bool;
#define TRUE 1
#define FALSE 0

typedef struct {
    double x, y;
} point;

typedef struct {
    point p;
    double coef;
    int pos;
    bool v;
} spy;

typedef struct {
    point c;
    double r;
} circle;

typedef struct {
    double a, b, c;
} line;

typedef struct {
    int edges[30][30];
    int degree[30];
} graph;

typedef struct {
    point p[30];
    int np;
} poly;


int b, n, m;
point enemy[1000];
spy inf[1000];
int cinf;
circle rad[30];
bool vrad[30];
graph g;
bool disc[30];
int parent[30];
bool process[30][30];
poly p[300];
int npoly;


#define min(a, b) (((a) < (b))? (a) : (b))
#define max(a, b) (((a) > (b))? (a) : (b))

double dist(point *a, point *b) {
    
    return (sqrt((a->x-b->x)*(a->x-b->x)+(a->y-b->y)*(a->y-b->y)));
}

void eliminate() {
    
    int i, j;
    
    for (i = 0; i < m; i++)
        for (j = 0; j < m; j++)
            if ((i != j) && (vrad[j]))
                if (rad[j].r - (dist(&rad[i].c, &rad[j].c) + rad[i].r) > -EPSILON) {
                    vrad[i] = FALSE;
                    break;
                }
    
    cinf = n;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (vrad[j])
                if (rad[j].r - dist(&inf[i].p, &rad[j].c) > -EPSILON) {
                    inf[i].v = FALSE;
                    cinf--;
                    break;
                }
}

bool point_in_box(point *p, point *b1, point *b2) {
    
    return( (p->x >= min(b1->x,b2->x)) && (p->x <= max(b1->x,b2->x))
            && (p->y >= min(b1->y,b2->y)) && (p->y <= max(b1->y,b2->y)) );
}

double collinear(point *a, point *b, point *c) {
 
    return (fabs(((a->x*b->y) - (a->y*b->x) + (a->y*c->x) - 
    (a->x*c->y) + (b->x*c->y) - (b->y*c->x))/2.0) < EPSILON);
}

void points_line(point *p1, point *p2, line *l) {
    if (fabs(p1->x-p2->x) < EPSILON) {
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

void intersection_point(line *l1, line *l2, point *p) {
    
    p->x = (l2->b*l1->c - l1->b*l2->c) / (l2->a*l1->b - l1->a*l2->b);
    if (fabs(l1->b) > EPSILON)
        p->y = - (l1->a * (p->x) + l1->c) / l1->b;
    else
        p->y = - (l2->a * (p->x) + l2->c) / l2->b;
}

void closest_point(point *pin, line *l, point *pc) {

    line perp; 
    if (fabs(l->b) <= EPSILON) { 
        pc->x = -(l->c);
        pc->y = pin->y;
        return;
    }
    if (fabs(l->a) <= EPSILON) {
        pc->x = pin->x;
        pc->y = -(l->c);
        return;
    }
    slope_line(pin, 1/l->a, &perp);
    intersection_point(l, &perp, pc);
}

void compute_coef() {
    
    int i, j;
    point *p, *b1, *b2;
    double d, d1, d2, m;
    line l;
    point pc;
    
    for (i = 0; i < n; i++) {
        if (inf[i].v == FALSE) continue;
        m = INF;
        for (j = 0; j < b; j++) {
            p = &inf[i].p; b1 = &enemy[j]; b2 = &enemy[(j+1)%b];
            if (collinear(p, b1, b2)) {
                if (point_in_box(p, b1, b2)) {
                    m = EPSILON;
                    break;
                }
                else {
                    d1 = dist(p, b1);
                    d2 = dist(p, b2);
                    d = min(d1, d2);
                }
            }
            else {
                points_line(b1, b2, &l);
                closest_point(p, &l, &pc);
                if (point_in_box(&pc, b1, b2))
                    d = dist(p, &pc);
                else {
                    d1 = dist(p, b1);
                    d2 = dist(p, b2);
                    d = min(d1, d2);
                }
            }
            if (d < m) m = d;
        }
        inf[i].coef = m;
    }
            
}

int cmp_spy(spy *a, spy *b) {
    
    if (a->v == FALSE) return (1);
    if (b->v == FALSE) return (-1);
    
    if (fabs(a->coef-b->coef) > EPSILON) {
        if (a->coef > b->coef) return (-1);
        else return (1);
    }
    else return (a->pos-b->pos);
}

void connect() {

    int i, j;
    
    for (i = 0; i < m; i++) {
        if (vrad[i] == FALSE) continue;
        for (j = i+1; j < m; j++) {
            if (vrad[j] == FALSE) continue;
            if (rad[i].r+rad[j].r-dist(&rad[i].c, &rad[j].c) > -EPSILON) {
                g.edges[i][g.degree[i]++] = j;
                g.edges[j][g.degree[j]++] = i;
            }
        }    
    }
}

void find_path(int st, int end) {
    
    if ((st == end) || (end == -1))
        p[npoly].p[p[npoly].np++] = rad[st].c;
    else {
        find_path(st, parent[end]);
        p[npoly].p[p[npoly].np++] = rad[end].c;
    }
}

void DFS(int v) {

    int i;
    int y;    
    
    disc[v] = TRUE;
    for (i = 0; i < g.degree[v]; i++) {
        y = g.edges[v][i];
        if (disc[y] == FALSE) {
            process[v][y] = process[y][v] = TRUE;
            parent[y] = v;
            DFS(y);
        }
        else if (process[v][y] == FALSE) {
            process[v][y] = process[y][v] = TRUE;
            p[npoly].np = 0;
            find_path(y, v);
            npoly++;
        }
    }
}

bool in_poly(poly *p, point *a) {
    
    int i, j, h;
    int c = 0;
    double cy;
    double t;
    double x = a->x, y = a->y;

    for (i = 0; i < p->np; i++) {
        j = (i+1)%p->np;
        if (((p->p[i].x-x < -EPSILON) && (x-p->p[j].x < -EPSILON)) 
        || ((p->p[i].x-x > EPSILON) && (x-p->p[j].x > EPSILON))) {
            t = (x - p->p[j].x) / (p->p[i].x - p->p[j].x);
            cy = t*p->p[i].y + (1.0-t)*p->p[j].y;
            if (fabs(y-cy) < EPSILON) return (TRUE);
            else if (y-cy > EPSILON) c++;
        }
        if (fabs(p->p[i].x-x) < EPSILON) {
            if (fabs(p->p[i].y-y) < EPSILON) return (TRUE);
            if (fabs(p->p[j].x-x) < EPSILON) {
                if (((p->p[i].y-y < EPSILON) && (y-p->p[j].y < EPSILON)) || 
                ((p->p[i].y-y > -EPSILON) && (y-p->p[j].y > -EPSILON)))
                    return (TRUE);
            }
            else {
                if (p->p[i].y-y < -EPSILON) {
                    for (h = (i+p->np-1)%p->np; ; h = (h+p->np-1)%p->np)
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

bool reach(int v) {
    
    int i;
    
    for (i = 0; i < npoly; i++) if (in_poly(&p[i], &inf[v].p)) return (FALSE);
    
    return (TRUE);    
}


int main() {
    
    int i, j;
    int x, y, r;
    int cmp_spy();
    
    while (1) {
        
        scanf("%d", &b);
        for (i = 0; i < b; i++) {
            scanf("%d %d", &x, &y);
            enemy[i].x = x; enemy[i].y = y;
        }
        
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%d %d", &x, &y);
            inf[i].p.x = x; inf[i].p.y = y; 
            inf[i].pos = i+1; inf[i].v = TRUE;
        }
        
        scanf("%d", &m);
        for (i = 0; i < m; i++) {
            scanf("%d %d %d", &x, &y, &r);
            rad[i].c.x = x; rad[i].c.y = y; rad[i].r = r;
            vrad[i] = TRUE;
        }
        
        if ((!b) && (!n) && (!m)) break;
        
        eliminate();

        compute_coef();
        qsort(inf, n, sizeof(spy), cmp_spy);
        
        for (i = 0; i < m; i++) g.degree[i] = 0;
        connect();
        
        for (i = 0; i < m; i++) {
            disc[i] = FALSE;
            parent[i] = -1;
            for (j = 0; j < m; j++) process[i][j] = FALSE;
        }
        npoly = 0;
        for (i = 0; i < m; i++) if ((vrad[i]) && (disc[i]==FALSE)) DFS(i);

        for (i = 0; i < cinf; i++) if (reach(i)) break;
        
        if (i < cinf) printf("Contact informer %d\n", inf[i].pos);
        else printf("Mission impossible\n");
    }
    
    return 0;
}
