/* Collecting Luggage */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXP 105
#define MAXV MAXP

#define EPSILON 1E-12

#define CW -1
#define CCW 1
#define COL 0

typedef char bool;
#define TRUE 1
#define FALSE 0

#define min(a, b) (((a) < (b))? (a) : (b))
#define max(a, b) (((a) > (b))? (a) : (b))

typedef struct {
    double x, y;
} point;

typedef struct {
    point p[MAXP];
    int n;
} poly;

typedef struct {
    int v;
    double wg;
} edge;

typedef struct {
    edge edges[MAXV][MAXV];
    int degree[MAXV];
} graph;

poly conv;
int n;
point st;
point tmp;
double vl, vp;
graph g;                /* posicao n - st ... */
double dst[MAXV];


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
        j = i+1;
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

void get_point(double d, point *pt, int *seg) {

    int i, j;
    double m, c;
    double s;
    int aux;

    aux = d / dst[n];
    c = aux;
    d = d - (c*dst[n]);
    for (i = 1; i <= n; i++) if (dst[i]-d > EPSILON) break;
    j = i-1;
    *seg = j;
    s = d-dst[j];
    if (fabs(conv.p[i].x-conv.p[j].x) < EPSILON) {
        pt->x = conv.p[j].x;
        if (conv.p[j].y > conv.p[i].y) pt->y = conv.p[j].y-s;
        else pt->y = conv.p[j].y+s;
    }
    else if (fabs(conv.p[i].y-conv.p[j].y) < EPSILON) {
        pt->y = conv.p[j].y;
        if (conv.p[j].x > conv.p[i].x) pt->x = conv.p[j].x-s;
        else pt->x = conv.p[j].x+s;
    }
    else {
        m = (conv.p[i].y-conv.p[j].y) / (conv.p[i].x-conv.p[j].x);
        c = s / sqrt((m*m)+1.0);
        m = fabs(m);
        if (conv.p[j].x > conv.p[i].x) pt->x = conv.p[j].x - c;
        else pt->x = conv.p[j].x + c;
        if (conv.p[j].y > conv.p[i].y) pt->y = conv.p[j].y - m*c;
        else pt->y = conv.p[j].y + m*c;
    }
}

bool connect(point *a, point *b) {

    int i;
    point aux;

    for (i = 0; i < n; i++)
        if (cross_intersect(a, b, &conv.p[i], &conv.p[i+1]))
            return (FALSE);

    aux.x = (a->x + b->x)/2.0; aux.y = (a->y + b->y)/2.0;
    if (in_poly(&conv, &aux)) return (FALSE);

    return(TRUE);
}

bool con(point *a, point *b, int seg) {

    int i;
    point aux;

    for (i = 0; i < n; i++)
        if (i != seg)
            if (cross_intersect(a, b, &conv.p[i], &conv.p[i+1]))
                return (FALSE);

    aux.x = (a->x + b->x)/2.0; aux.y = (a->y + b->y)/2.0;
    if (in_poly(&conv, &aux)) return (FALSE);

    return(TRUE);
}


/* Dijkstra */
typedef struct {
    double d;
    int h;
} vertex;

#define LEFT(i) ((i)<<1)
#define RIGHT(i) (((i)<<1)|1)
#define PAI(i) ((i)>>1)

int H[MAXV];
int heapsize;
vertex vert[MAXV];

void insertUpdate(int *H, int v) {

    int i = vert[v].h;

    if (i == 0) i = ++heapsize;
    while ((i > 1) && (vert[H[PAI(i)]].d > vert[v].d)) {
        H[i] = H[PAI(i)];
        vert[H[PAI(i)]].h = i;
        i = PAI(i);
    }
    H[i] = v;
    vert[v].h = i;
}

void corrige(int *H, int i) {

    int min, aux;
    int l = LEFT(i), r = RIGHT(i);

    if ((l <= heapsize) && (vert[H[l]].d < vert[H[i]].d)) min = l;
    else min = i;
    if ((r <= heapsize) && (vert[H[r]].d < vert[H[min]].d)) min = r;

    if (min != i){
        aux = H[i];
        H[i] = H[min]; vert[H[min]].h = i;
        H[min] = aux; vert[aux].h = min;
        corrige(H, min);
    }
}

int minimum(int *H) {

    int l,r;
    int ret = H[1];

    H[1] = H[heapsize--];
    vert[H[1]].h = 1;
    corrige(H, 1);
    return ret;
}

void dijkstra(int s) {

    int i;
    int j;
    int v;

    heapsize = 0;
    for( i = 0; i < n+2; i++ ) {
        vert[i].d = 1E14;
        vert[i].h = 0;
    }

    vert[s].d = 0.0;
    insertUpdate(H, s);
    while ( heapsize > 0 ) {
        i = minimum(H);
        vert[i].h = -1;
        for (j = 0; j < g.degree[i]; j++) {
            v = g.edges[i][j].v;
            if (vert[v].h >= 0)
                if (vert[v].d > vert[i].d + g.edges[i][j].wg) {
                    vert[v].d = vert[i].d + g.edges[i][j].wg;
                    insertUpdate(H, v);
                }
        }
    }
}

int get_time(double min, double max) {

    int i;
    int seg;
    double t = (max+min)/2.0;
    double aux, m;
    int time;
    point tmp;

    get_point(t*vl, &tmp, &seg);
    m = 1E14;
    for (i = 0; i < n; i++)
        if (con(&conv.p[i], &tmp, seg)) {
            aux = dist(&conv.p[i], &tmp);
            aux = aux/vp;
            if (vert[i].d+aux < m) m = vert[i].d+aux;
        }
    if (con(&st, &tmp, seg)) {
        aux = dist(&st, &tmp);
        aux = aux/vp;
        if (aux < m) m = aux;
    }

    aux = t-m;
    if (fabs(aux) < 0.005) {
        time = floor(m+0.5);
        return(time);
    }
    else if (aux > EPSILON) return(get_time(m, t));
    else return(get_time(t, m));
}


int main() {

    int i, j;
    int x, y;
    double aux, max;           /* Limites para a busca binaria. */
    int mnt, sec;
    int c;
    point a;

    c = 0;
    while (scanf("%d", &n)) {

        if (n == 0) break;
        c++;

        for (i = 0; i < n; i++) {
            scanf("%d %d", &x, &y);
            conv.p[i].x = x; conv.p[i].y = y;
        }
        conv.p[n].x = conv.p[0].x; conv.p[n].y = conv.p[0].y;
        conv.n = n;

        scanf("%d %d", &x, &y);
        st.x = x; st.y = y;

        scanf("%d %d", &x, &y);
        vl = x; vp = y;
        vl = vl/60.0; vp = vp/60.0;

        dst[0] = 0.0;
        for (i = 1; i <= n; i++)
            dst[i] = dst[i-1] + dist(&conv.p[i], &conv.p[i-1]);

        max = (dist(&conv.p[0], &st)/vp) + (dst[n] / vp);
        for (i = 0; i <= n; i++) g.degree[i] = 0;
        for (i = 0; i < n; i++) {
            for (j = i+1; j < n; j++)
                if (connect(&conv.p[i], &conv.p[j])) {
                    aux = dist(&conv.p[i], &conv.p[j]);
                    aux = aux/vp;
                    g.edges[i][g.degree[i]].v = j;
                    g.edges[i][g.degree[i]++].wg = aux;
                    g.edges[j][g.degree[j]].v = i;
                    g.edges[j][g.degree[j]++].wg = aux;
                }
            if (connect(&conv.p[i], &st)) {
                aux = dist(&conv.p[i], &st);
                aux = aux/vp;
                g.edges[i][g.degree[i]].v = n;
                g.edges[i][g.degree[i]++].wg = aux;
                g.edges[n][g.degree[n]].v = i;
                g.edges[n][g.degree[n]++].wg = aux;
            }
        }

        dijkstra(n);

        sec = get_time(0.0, max);
        mnt = sec/60;
        sec = sec%60;
        printf("Case %d: Time = %d:%02d\n", c, mnt, sec);
    }

    return 0;
}
