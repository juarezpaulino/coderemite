#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define INF 0x7FFFFFFF


typedef struct {
    int a, b;
    int solved;
    int t;
} team;

team tm[100];
int t, p;
int min, max;


int cmp(team *a, team *b) {
    
    if (a->solved != b->solved) return b->solved - a->solved;
    return a->t - b->t; 
}


int main() {
    
    int i, j;
    int a, b;
    char ch;
    int cmp();
    double x;
    
    while (scanf("%d %d", &t, &p)) {
        
        if (!t && !p) break;
        
        for (i = 0; i < t; i++) {
            tm[i].a = tm[i].b = 0;
            tm[i].solved = 0;
            for (j = 0; j < p; j++) {
                scanf("%d/%c", &a, &ch);
                if (ch == '-') continue;
                ungetc(ch, stdin);
                scanf("%d", &b);
                tm[i].a += a-1;
                tm[i].b += b;
                tm[i].solved++;
            }
            tm[i].t = tm[i].a * 20 + tm[i].b;
        }
        
        qsort(tm, t, sizeof(team), cmp);
        
        min = 1; max = INF;
        for (i = 0; (i < t-1) && ((min != 20) || (max != 20)); i++)
            for (j = i+1; (j < t) && (tm[i].solved == tm[j].solved); j++) {
                /* Calcula inteseccao. */
                if (tm[i].a == tm[j].a) continue;
                x = (double)(tm[j].b - tm[i].b) / (double)(tm[i].a - tm[j].a);
                if ((x <= 20.0 + 1E-13) && (x >= 20.0 - 1E-13)) { min = 20; max = 20; break; }
                else if ((x < 20.0) && (x >= min)) min = (int)x + 1;
                else if ((x > 20.0) && (x <= max)) max = (int)(x + 1.0 - 1E-13) - 1;
            }
        
        if (max == INF) printf("%d *\n", min);
        else printf("%d %d\n", min, max);
    }
    
    return 0;    
}
