/* Petanque */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 1E-10

#define dist(a, b) sqrt(((a).x-(b).x)*((a).x-(b).x)+((a).y-(b).y)*((a).y-(b).y))
#define min(a, b) (((a) < (b))? (a) : (b))
#define max(a, b) (((a) > (b))? (a) : (b))

typedef struct {
    double x, y;
    double d;
    int p;
} b;

char player[2][21];
int npb[2];
b boule[7];
int n;
double Pi;


int on_segment(b *a, double x0, double y0, double x1, double y1) {
    
    double area = ((a->x*y0) - (a->y*x0) + (a->y*x1) - 
                   (a->x*y1) + (x0*y1) - (y0*x1))/2.0;
    
    if (fabs(area) > EPSILON) return(0);
    
    return( (a->x >= min(x0,x1)-EPSILON) && (a->x <= max(x0,x1)+EPSILON)
    && (a->y >= min(y0,y1)-EPSILON) && (a->y <= max(y0,y1)+EPSILON) );
}

int boule_cmp(b *a, b *b) {
    
    if (a->d < b->d) return (-1);
    else return (1);
}

void move(int x0, int y0, int teta, int d) {
    
    int i;
    int p;
    b aux[8];
    double x1, y1, m, c;
    char x_sign, y_sign;
    int boule_cmp();
    
    aux[0].x = x0; aux[0].y = y0; aux[0].p = n;
    for (i = 1; i <= n; i++) { 
        aux[i] = boule[i-1]; aux[i].p = i-1; aux[i].d = dist(aux[i], aux[0]);
    }
    qsort(&aux[1], n, sizeof(b), boule_cmp);
    
    if ((0 <= teta) && (teta <= 90)) { x_sign = 1; y_sign = 1; }
    else if ((90 < teta) && (teta <= 180)) { x_sign = -1; y_sign = 1; }
    else if ((180 < teta) && (teta < 270)) { x_sign = -1; y_sign = -1; }
    else { x_sign = 1; y_sign = -1; }
    if ((teta == 90) || (teta == 270)) {
        x1 = x0; y1 = y0+y_sign*d;
    }
    else {
        m = fabs(tan((teta*Pi) / 180.0));
        c = (double)d / sqrt((m*m) + 1.0);
        x1 = x0 + x_sign*c;
        y1 = y0 + y_sign*m*c;
    }

    p = 0;
    for (i = 1; i <= n; i++)
        if (on_segment(&aux[i], x0, y0, x1, y1)) {
            boule[aux[p].p].x = aux[i].x;
            boule[aux[p].p].y = aux[i].y;
            p = i;
        }
    boule[aux[p].p].x = x1;
    boule[aux[p].p].y = y1;
}


int main() {

    int c;
    int i;
    int x, y, teta, d;
    double ds, min;
    int turn;
    int points;
    int boule_cmp();
    
    Pi = 2.0*acos(0.0);
    scanf("%d", &c);
    while (c) {
        
        scanf(" %s %s ", player[0], player[1]);
        npb[0] = npb[1] = 0;
        
        n = 0;
        scanf("%d %d %d %d", &x, &y, &teta, &d);
        move(x, y, teta, d);
        boule[0].d = 0.0; boule[0].p = -1;
        
        turn = 0;
        for (n = 1; n < 7; n++) {
            scanf("%d %d %d %d", &x, &y, &teta, &d);
            move(x, y, teta, d);
            boule[n].p = turn;
            npb[turn]++;
            if (npb[0] == 3) turn = 1;
            else if (npb[1] == 3) turn = 0;
            else {
                turn = -1; min = 1E14;
                for (i = 1; i <= n; i++) 
                    if ((ds = dist(boule[i], boule[0])) < min) {
                        min = ds;
                        turn = boule[i].p^1;
                    }
            }
        }
        for (i = 1; i < n; i++) boule[i].d = dist(boule[0], boule[i]);
        qsort(&boule[1], 6, sizeof(b), boule_cmp);
        turn = boule[1].p;
        
        for (i = 1, points = 0; (i < 7) && (boule[i].p == turn); points++, i++);
        
        printf("%s %d\n", player[turn], points);
        
        c--;
    }
    
    return 0;
}
