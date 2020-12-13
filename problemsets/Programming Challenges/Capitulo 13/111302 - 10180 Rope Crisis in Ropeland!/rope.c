/* Rope Crisis in Ropeland! */

#include <stdio.h>
#include <math.h>

#define EPSILON 0.0000001

typedef double point[2];
#define X 0
#define Y 1

typedef struct {
    double a;
    double b;
    double c;
} line;

typedef struct {
    point c;
    double r;
} circle;

int point_in_box(point p, point a, point b) {
    
    if (a[X] > b[X]) {
        if ((p[X] - b[X] < -EPSILON) || (p[X] - a[X] > EPSILON))
            return (0);
    }
    else {
        if ((p[X] - a[X] < -EPSILON) || (p[X] - b[X] > EPSILON))
            return (0);
    }
    
    if (a[Y] > b[Y]) {
        if ((p[Y] - b[Y] < -EPSILON) || (p[Y] - a[Y] > EPSILON))
            return (0);
    }
    else {
        if ((p[Y] - a[Y] < -EPSILON) || (p[Y] - b[Y] > EPSILON))
            return (0);
    }
    
    return (1);
}

double distance(point a, point b) {
    
    return (sqrt(((a[Y] - b[Y])*(a[Y] - b[Y])) + ((a[X] - b[X])*(a[X] - b[X]))));
}

void points_to_line(point p1, point p2, line *l) {
    
    if (p1[X] == p2[X]) {
        l->a = 1;
        l->b = 0;
        l->c = -p1[X];
    }
    else {
        l->b = 1;
        l->a = -(p1[Y]-p2[Y])/(p1[X]-p2[X]);
        l->c = -(l->a * p1[X]) - (l->b * p1[Y]);
    }
}

void pointslope_to_line(point p, double m, line *l) {
    
    l->a = -m;
    l->b = 1;
    l->c = -((l->a*p[X]) + (l->b*p[Y]));
}

double slope(point p1, point p2) {
    
    return ((p1[Y]-p2[Y])/(p1[X]-p2[X]));
}

void intersection_point(line l1, line l2, point p) {
    
    p[X] = (l2.b*l1.c - l1.b*l2.c) / (l2.a*l1.b - l1.a*l2.b);
    
    if (fabs(l1.b) > EPSILON)
        p[Y] = -(l1.a * (p[X]) + l1.c) / l1.b;
    else
        p[Y] = -(l2.a * (p[X]) + l2.c) / l2.b;
}

void closest_point(point p_in, line l, point p_c) {
    
    line perp;
    
    if (fabs(l.b) <= EPSILON) {
        p_c[X] = -(l.c);
        p_c[Y] = p_in[Y];
        return;
    }
    if (fabs(l.a) <= EPSILON) {
        p_c[X] = p_in[X];
        p_c[Y] = -(l.c);
        return;
    }
    
    pointslope_to_line(p_in, 1/l.a, &perp);
    intersection_point(l, perp, p_c);
}

void war(point a, point b, circle c) {

    line l;
    line s, t;
    point close;
    double rope;
    double h;
    double d, e;
    double x, y;
    double alpha, theta;        /* angles */
    double w, z;                /* angles */
    
    points_to_line(a, b, &l);
    closest_point(c.c, l, close);
    h = distance(c.c, close);
    if ((h >= 0) && (h < c.r) && (point_in_box(close, a, b))) {
        d = distance(a, c.c);
        e = distance(b, c.c);
        x = sqrt((d*d)-(c.r*c.r));
        y = sqrt((e*e)-(c.r*c.r));
        
        w = fabs(atan2(x, c.r));
        z = fabs(atan2(y, c.r));
        points_to_line(a, c.c, &s);
        points_to_line(b, c.c, &t);
        if ((fabs(s.a-t.a) <= EPSILON) && (fabs(s.b-t.b) <= EPSILON))
            alpha = 2*acos(0.0);
        else {
            alpha = fabs(atan2((s.a*t.b - t.a*s.b),(s.a*t.a + s.b*t.b)));
            if (((s.a > -EPSILON) && (t.a < EPSILON)) || ((t.a > -EPSILON) && (s.a < EPSILON)))
                if ((s.a != 1) && (t.a != 1))
                    alpha = 2*acos(0.0) - alpha;
        }
        theta = alpha-w-z;
        rope = x+y+(theta*c.r);
    }
    else
        rope = distance(a, b);
    
    printf("%.3lf\n", rope);
}


int main() {
    
    int cases;
    circle c;
    point a, b;
    
    c.c[X] = 0.0;
    c.c[Y] = 0.0;
    scanf("%d", &cases);
    while (cases) {
    
        scanf("%lf %lf %lf %lf %lf", &a[X], &a[Y], &b[X], &b[Y], &c.r);       
        war(a, b, c);
        cases--;
    }

    return 0;    
}
