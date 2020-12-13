/* Cutting Edge */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x1, y1, x2, y2;
} frame;

typedef struct {
    frame rect;
    int index[2];
    int n;
} item;

typedef struct {
    frame rect;
    int st, end;
} rect;


int n;
frame f[2000];
rect r[2000];
int nr;
int cont;

#define LEFT(i) ((i)<<1)
#define RIGHT(i) (((i)<<1)|1)
#define PAI(i) ((i)>>1)

item HE[2000];
int heapedge;

int item_cmp(item *a, item *b) {

    if (a->rect.x1 != b->rect.x1) return (a->rect.x1 - b->rect.x1);
    else return (a->rect.y1 - b->rect.y1);
}

void insertUpdate(item *H, int *n, item v) {

    int i = ++(*n);
    while ((i > 1) && (item_cmp(&v , &H[PAI(i)]) < 0)) {
        H[i] = H[PAI(i)];
        i = PAI(i);
    }
    H[i] = v;
}

void corrige(item *H, int *n, int i) {

    int min;
    item aux;
    int l = LEFT(i), r = RIGHT(i);

    if ((l <= *n) && (item_cmp(&H[l], &H[i]) < 0)) min = l; 
    else min = i;
    if ((r <= *n) && (item_cmp(&H[r], &H[min]) < 0)) min = r;
    
    if (min != i){
        aux = H[i];
        H[i] = H[min];
        H[min] = aux;
        corrige(H, n, min);
    }
}

item minimun(item *H, int *n) {
    
    int l,r;
    item ret = H[1];

    H[1] = H[(*n)--];
    corrige(H, n, 1);
    return ret;
}

int hor_cmp(frame *a, frame *b) {

    if (a->y2 != b->y2) return (a->y2 - b->y2);
    return (a->x2 - b->x2);    
}

int ver_cmp(frame *a, frame *b) {

    if (a->x2 != b->x2) return (a->x2 - b->x2);
    return (a->y2 - b->y2);    
}


int main() {

    int i, j;
    int x1, y1, x2, y2;
    int xmin, ymin, xmax, ymax;
    item e0, e;
    rect curr, c;
    char cut;
    int hor_cmp();
    int ver_cmp();
    
    while (scanf("%d", &n)) {
        
        if (!n) break;
        
        xmin = ymin = 10000;
        xmax = ymax = -10000;
        for (i = 0; i < n; i++) {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            if (x1 < xmin) xmin = x1; if (y1 < ymin) ymin = y1;
            if (x2 > xmax) xmax = x2; if (y2 > ymax) ymax = y2;
            f[i].x1 = x1; f[i].y1 = y1; f[i].x2 = x2; f[i].y2 = y2;
        }
        
        r[0].rect.x1 = xmin; r[0].rect.y1 = ymin;
        r[0].rect.x2 = xmax; r[0].rect.y2 = ymax;
        r[0].st = 0; r[0].end = n-1;
        curr = r[0];
        nr = 1;
        e0.index[0] = 0; e0.n = 1;
        cont = 0;
        heapedge = 0;
        while (cont < nr) {
            for (j = 0; j < e0.n; j++, cont++) {
                curr = r[e0.index[j]];
            
                /* Search for horizontal cut. */
                qsort(&f[curr.st], curr.end-curr.st+1, sizeof(frame), hor_cmp);
                cut = 0;
                for (i = curr.st; i <= curr.end; i++) {
                    if ((f[i].x1 == curr.rect.x1) && (f[i].y2 < curr.rect.y2)) {
                        while ((i<curr.end) && (f[i].y2==f[i+1].y2) && (f[i].x2==f[i+1].x1)) i++;
                        if (f[i].x2 == curr.rect.x2) { cut = 1; break; }
                    }
                }
                if (cut) {
                    e.rect.x1 = curr.rect.x1; e.rect.y1 = f[i].y2;
                    e.rect.x2 = curr.rect.x2; e.rect.y2 = f[i].y2;
                    e.n = 0;
                    if (curr.st < i) {
                        c.rect.x1 = curr.rect.x1; c.rect.x2 = curr.rect.x2;
                        c.rect.y1 = curr.rect.y1; c.rect.y2 = f[i].y2;
                        c.st = curr.st; c.end = i;
                        r[nr] = c;
                        e.index[e.n++] = nr;
                        nr++;
                    }
                    if (curr.end > i+1) {
                        c.rect.x1 = curr.rect.x1; c.rect.x2 = curr.rect.x2;
                        c.rect.y1 = f[i].y2; c.rect.y2 = curr.rect.y2;
                        c.st = i+1; c.end = curr.end;
                        r[nr] = c;
                        e.index[e.n++] = nr;
                        nr++;
                    }
                    insertUpdate(HE, &heapedge, e);
                    continue;
                }
                
                /* Search for vertical cut. */
                qsort(&f[curr.st], curr.end-curr.st+1, sizeof(frame), ver_cmp);
                for (i = curr.st; i <= curr.end; i++) {
                    if ((f[i].y1 == curr.rect.y1) && (f[i].x2 < curr.rect.x2)) {
                        while ((i<curr.end) && (f[i].x2==f[i+1].x2) && (f[i].y2==f[i+1].y1)) i++;
                        if (f[i].y2 == curr.rect.y2) { cut = 1; break; }
                    }
                }
                if (cut) {
                    e.rect.x1 = f[i].x2; e.rect.y1 = curr.rect.y1; 
                    e.rect.x2 = f[i].x2; e.rect.y2 = curr.rect.y2;
                    e.n = 0;
                    if (curr.st < i) {
                        c.rect.x1 = curr.rect.x1; c.rect.x2 = f[i].x2;
                        c.rect.y1 = curr.rect.y1; c.rect.y2 = curr.rect.y2;
                        c.st = curr.st; c.end = i;
                        r[nr] = c;
                        e.index[e.n++] = nr;
                        nr++;
                    }
                    if (curr.end > i+1) {
                        c.rect.x1 = f[i].x2; c.rect.x2 = curr.rect.x2;
                        c.rect.y1 = curr.rect.y1; c.rect.y2 = curr.rect.y2;
                        c.st = i+1; c.end = curr.end;
                        r[nr] = c;
                        e.index[e.n++] = nr;
                        nr++;
                    }
                    insertUpdate(HE, &heapedge, e);
                }
            }
            
            e0 = minimun(HE, &heapedge);
            printf("%d %d %d %d\n", e0.rect.x1, e0.rect.y1, e0.rect.x2, e0.rect.y2);
        }
        while (heapedge > 0) {
            e = minimun(HE, &heapedge);
            printf("%d %d %d %d\n", e.rect.x1, e.rect.y1, e.rect.x2, e.rect.y2);
        }
        putchar('\n');
    }
    
    return 0;
}
