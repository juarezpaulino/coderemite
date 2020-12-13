#include <stdio.h>
#include <math.h>

typedef struct { double x, y; } point;

#define dist(a, b) (((a).x-(b).x)*((a).x-(b).x) + ((a).y-(b).y)*((a).y-(b).y))


int n;
point p[1000];
char in[1000000]; int pos;


int abscissa(point *x, point *y) {
    if (x->x < y->x) return (-1); return (1);
}

int get_int() {
    int ch, i, s;
    while ((in[pos] == ' ') || (in[pos] == '\n')) pos++;
    if (in[pos] == '-') { s = 1; pos++; } else s = 0;
    for (i = 0; in[pos]>='0' && in[pos]<='9'; pos++) i = 10*i + (in[pos]-'0');
    if (s) return -i; return i;
}


int main() {
    
    double min, m;
    double d;
    register int i, j;
    int abscissa();
    
    fread(in, sizeof(char), 1000000, stdin); pos = 0;
    n = get_int(); for (i = 0; i < n; i++) { p[i].x = get_int(); p[i].y = get_int(); }
    
    if (n < 2) { puts("0.000"); return; }
    
    qsort(p, n, sizeof(point), abscissa);
        
    min = m = 1E16;
    
    for (i = 0; i < n-1; i++)
        for (j = i+1; j < n; j++) {
            if (p[j].x - p[i].x >= min) break;
            if ((d = dist(p[i], p[j])) < m) {
                m = d;
                min = sqrt(m);
            }
        }
        
    printf("%.3lf", min);
    
    return 0;
}

