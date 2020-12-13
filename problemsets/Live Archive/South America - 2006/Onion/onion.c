/* Onion Layers */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXP 2001

typedef char bool;
#define TRUE 1
#define FALSE 0

#define distance(a, b) (((a.x)-(b.x))*((a.x)-(b.x)) + ((a.y)-(b.y))*((a.y)-(b.y)))

#define EPSILON 0.00000001

typedef struct {
    int x;
    int y;
} point;

int n;
point set[MAXP];
int layers;

int leftlower(point *p1, point *p2) {

    return (((*p1).y != (*p2).y)?(*p1).y-(*p2).y:(*p1).x-(*p2).x);
}

double signed_triangle_area(point a, point b, point c) {

    return (((double)((a.x*b.y) - (a.y*b.x) + (a.y*c.x) - (a.x*c.y) + (b.x*c.y) - (b.y*c.x)))/2.0);
}

void onion(int n) {

    register int i, ia, ib, aux;
    point a, b;
    int pin;
    int start;
    double area;
    bool inhull[MAXP];
    bool collinear;

    if (n == 3) {
        layers = 1;
        return;
    }

    for (i = 0; i < n; i++)
        inhull[i] = FALSE;

    a = set[0];
    ia = 0;
    b = set[1];
    ib = 1;
    start = 0;
    pin = 0;
    collinear = TRUE;
    while (pin < n) {
        for (i = ib+1; i < n; i++) {
            if ((!inhull[i]) && (i != ia) && (i != ib)) {
                area = signed_triangle_area(a, b, set[i]);
                if (fabs(area) < EPSILON) {
                    if (distance(a, set[i]) < distance(a, b)) {
                        b = set[i];
                        ib = i;
                    }
                }
                else {
                    if (area < EPSILON) {
                        b = set[i];
                        ib = i;
                    }
                }
            }
        }
        if (start == ib) {
            inhull[start] = TRUE;
            layers++;
            start = -1;
        }
        else {
            if (start < 0) {
                start = ib;
                pin--;
                collinear = TRUE;
            }
            else {
                inhull[ib] = TRUE;
                if (collinear)
                    if (fabs(signed_triangle_area(a, b, set[start])) > EPSILON) {
                        collinear = FALSE;
                    }
            }
            a = b;
            ia = ib;
        }
        aux = ib;
        for (i = 0; i < n; i++)
            if ((!inhull[i]) && (i != aux))  {
                if (i == start && collinear)
                    continue;
                b = set[i];
                ib = i;
                break;
            }
        pin++;
    }
}



int main() {
 
    register int i, hole;
    int leftlower();
 
    while (scanf("%d", &n)) {

        if (n == 0)
            break;

        for (i = 0; i < n; i++)
            scanf("%d %d", &(set[i].x), &(set[i].y));

        /* Sort and Remove */
        qsort(set, n, sizeof(point), leftlower);
        hole = 1;
        for (i = 1; i < n; i++) {
            if ((set[i].x == set[i-1].x) && (set[i].y == set[i-1].y))
                n--;
            else
                set[hole++] = set[i];
        }
        layers = 0;

        onion(n);
       
        if (layers & 1)
            printf("Take this onion to the lab!\n");
        else
            printf("Do not take this onion to the lab!\n");
    }

    return 0;
}
