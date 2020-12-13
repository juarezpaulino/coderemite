/* Zing Zhu's Oyster Farm */

#include <stdio.h>

typedef char bool;
#define TRUE 1
#define FALSE 0

typedef struct {
     bool fill;
     bool wall[4];
} cell;

typedef struct {
    int x1, x2, y1, y2;
    int h;
} segment;

typedef struct {
    int x, y;
} point;

cell c[1004][1004];
segment s[2000];

int n;
int w;
int xmin, ymin, xmax, ymax;

#define MAXV 3000

typedef struct {
    point q[MAXV];
    int first;
    int last;
    int count;
} queue;

queue q;

void init_queue() {
    
    q.first = 0;
    q.last = MAXV-1;
    q.count = 0;
}

void enqueue(int x, int y) {
    
    q.last = (q.last + 1) % MAXV;
    q.q[q.last].x = x; q. q[q.last].y = y;
    q.count++;
}

void dequeue(int *x, int *y) {
    
    *x = q.q[q.first].x;
    *y = q.q[q.first].y;
    q.first = (q.first+1) % MAXV; 
    q.count--;
}

bool empty() {
    
    if (q. count <= 0) return TRUE;
    
    return FALSE;
}

void BFS(int x1, int y1) {

    int x, y;

    init_queue();
    c[x1][y1].fill = TRUE;
    enqueue(x1, y1);

    while (!empty()) {
        dequeue(&x, &y);
        if ((x-1 >= xmin-1) && (!c[x][y].wall[1]) && (!c[x-1][y].fill)) {
            enqueue(x-1, y);
            c[x-1][y].fill = TRUE;
        }
        if ((y-1 >= ymin-1) && (!c[x][y].wall[0]) && (!c[x][y-1].fill)) {
            enqueue(x, y-1);
            c[x][y-1].fill = TRUE;
        }
        if ((x+1 <= xmax) && (!c[x][y].wall[3]) && (!c[x+1][y].fill)) {
            enqueue(x+1, y);
            c[x+1][y].fill = TRUE;
        }
        if ((y+1 <= ymax) && (!c[x][y].wall[2]) && (!c[x][y+1].fill)) {
            enqueue(x, y+1);
            c[x][y+1].fill = TRUE;
        }
    }
}


int main() {
    
    int i, j, k;
    int x1, y1, x2, y2;
    int area;
    
    while (scanf("%d", &n)) {
        
        if (!n) break;    
        
        xmin = ymin = 100000;
        xmax = ymax = -1;
        for (i = 0; i < n; i++) {
            scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &s[i].h);
            x1 += 502; x2 += 502; y1 += 502; y2 += 502;
            if (x2 < x1) { k = x1; x1 = x2; x2 = k; }
            if (y2 < y1) { k = y1; y1 = y2; y2 = k; }
            s[i].x1 = x1; s[i].y1 = y1; s[i].x2 = x2; s[i].y2 = y2;
            if (x1 < xmin) xmin = x1; if (x2 > xmax) xmax = x2;
            if (y1 < ymin) ymin = y1; if (y2 > ymax) ymax = y2;
        }   
        scanf("%d", &w);
        
        for (i = xmin-1; i <= xmax; i++)
            for (j = ymin-1; j <= ymax; j++) {
                c[i][j].fill = FALSE;
                for (k = 0; k < 4; k++) c[i][j].wall[k] = FALSE;
            }

        for (i = 0; i < n; i++)
            if (s[i].h >= w) {
                if (s[i].x1 == s[i].x2) {
                    for (j = s[i].y1; j < s[i].y2; j++) {
                        c[s[i].x1][j].wall[1] = TRUE;
                        c[s[i].x1-1][j].wall[3] = TRUE;
                    }
                }
                else {
                    for (j = s[i].x1; j < s[i].x2; j++) {
                        c[j][s[i].y1].wall[0] = TRUE;
                        c[j][s[i].y1-1].wall[2] = TRUE;
                    }
                }   
            }
        BFS(xmax, ymax);

        area = 0;
        for (i = xmin; i <= xmax; i++)
            for (j = ymin; j <= ymax; j++)
                if (!c[i][j].fill) area++;
        
        printf("%d\n", area);
    }
    
    return 0;
}
