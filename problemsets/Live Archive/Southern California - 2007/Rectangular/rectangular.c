#include <stdio.h>
#include <stdlib.h>

#define MAXV 1000


typedef struct {
    int x, y;
} point;

typedef struct {
    point p;
    int pos;
} lista;

int n;
char poly[MAXV][2];         /* Pos 0 - vertical; Pos 1 - Horizontal. */
int dir[MAXV][2];           /* Posicao vizinha no poligono. */
lista H[MAXV], V[MAXV];


int xcmp(lista *a, lista *b) {
    
    if (a->p.x != b->p.x) return (a->p.x - b->p.x);
    return (a->p.y - b->p.y);
}

int ycmp(lista *a, lista *b) {
    
    if (a->p.y != b->p.y) return (a->p.y - b->p.y);
    return (a->p.x - b->p.x);
}



int main() {
    
    int i;
    int x, y, v;
    int xcmp(), ycmp();
    char found, tap;
    
    while (scanf("%d", &n)) {
        
        if (!n) break;   

        for (i = 0; i < n; i++) {
            scanf("%d %d", &x, &y);
            V[i].pos = H[i].pos = i;
            V[i].p.x = H[i].p.x = x;
            V[i].p.y = H[i].p.y = y;
        }
        
        qsort(V, n, sizeof(lista), ycmp);
        qsort(H, n, sizeof(lista), xcmp);
        
        for (i = 0; i < n; i += 2) {
            poly[H[i].pos][0] = 'N';    dir[H[i].pos][0] = H[i+1].pos;
            poly[H[i+1].pos][0] = 'S';  dir[H[i+1].pos][0] = H[i].pos;
            poly[V[i].pos][1] = 'E';    dir[V[i].pos][1] = V[i+1].pos;
            poly[V[i+1].pos][1] = 'W';  dir[V[i+1].pos][1] = V[i].pos;
        }
        
        found = 0; 
        v = V[0].pos;
        tap = 0;
        while ((!found) || (v != 0)) {
            if (v == 0) found = 1;
            if (found) putchar(poly[v][tap]);
            v = dir[v][tap];
            tap ^= 1;
        }
        putchar('\n');
    }

    return 0;
}
