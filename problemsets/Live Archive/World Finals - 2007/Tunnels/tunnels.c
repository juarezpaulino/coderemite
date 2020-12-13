/* Tunnels */

#include <stdio.h>

#define MAXV 51
#define MAXE 1001 

typedef char bool;
#define TRUE 1
#define FALSE 0

typedef struct {
    short edges[MAXV][MAXE];
    short degree[MAXV];
} graph;

graph g;
bool disc[MAXV];
bool valid[MAXV];
short cap[MAXV][MAXV];
short p[MAXV];
short X[MAXV];
int r, t;

int min(int a, int b) {
    
    return((a<b)?a:b);
}

typedef struct {
    int q[MAXV];
    int first, last;
    int c;
} queue;

void init_queue(queue *q) {
    
    q->first = 0;
    q->last = MAXV-1;
    q->c = 0;
}

void enqueue(queue *q, int x) {

    q->last = (q->last+1)%MAXV;
    q->q[q->last] = x;
    q->c++;    
}

int dequeue(queue *q) {
    
    int x = q->q[q->first];
    q->first = (q->first+1)%MAXV;
    q->c--;
    
    return (x);
}

bool empty(queue *q) {
    
    return (q->c == 0);
}
        
int bfs(int st, int end, short c[][MAXV]) {

    int x, y;
    int i;
    queue q;
    int path;
    
    init_queue(&q);
    enqueue(&q, st);
    for (i = 0; i <= r; i++) {
        disc[i] = FALSE;
        p[i] = -1;
    }
    disc[st] = TRUE;
    
    while ((!empty(&q)) && (!disc[end])) {
        x = dequeue(&q);
        for (i = 0; i < g.degree[x]; i++) {
            y = g.edges[x][i];
            if ((c[x][y] > 0) && (!disc[y]) && (valid[y])) {
                disc[y] = TRUE;
                enqueue(&q, y);
                p[y] = x;
                if (y == end)
                    break;
            }
        }
    }
    
    path = 1000000000;
    y = end;
    while (p[y] > -1) {
        x = p[y];
        path = min(path, c[x][y]);
        y = x;
    }
    
    y = end;
    while (p[y] > -1) {
        x = p[y];
        c[x][y] -= path;
        c[y][x] += path;
        y = x;
    }
    
    if (path == 1000000000) return (0);
    return (path);
}

int maxflow(int st, int end, short c[][MAXV]) {
    
    int i, j;
    int max, f;
    
    max = 0;
    while ((f = bfs(st, end, c)) != 0) max += f;
    
    return(max);
}


int main() {

    int i, j, k;
    int m;
    int a, b;
    int c;
    short aux[MAXV][MAXV];
    
    c = 0;
    while (scanf("%d %d", &r, &t)) {
     
        if ((r == 0) && (t == 0))
            break;
        c++;
        
        for (i = 0; i <= r; i++)
            g.degree[i] = 0;
        
        for (j = 0; j <= r; j++) for (k = 0; k <= r; k++) cap[j][k] = 0;
        for (i = 0; i < t; i++) {
            scanf("%d %d", &a, &b);
            for (j = 0; j < g.degree[a]; j++) if (g.edges[a][j] == b) break;
            if (j == g.degree[a]) {
                cap[a][b] = cap[b][a] = 1;
                g.edges[a][g.degree[a]++] = b;
                g.edges[b][g.degree[b]++] = a;
            }
            else
                cap[a][b] = ++cap[b][a];
        }

        for (i = 0; i <= r; i++) valid[i] = TRUE;
        for (i = 1; i <= r; i++) {
            for (j = 0; j <= r; j++) for (k = 0; k <= r; k++) aux[j][k] = cap[j][k]; 
            X[i] = maxflow(i, 0, aux);
        }
        while (valid[1]) {
            for (m = 1000000000, i = 1; i <= r; i++) if ((valid[i])&&(X[i] < m)) m = X[i];
            for (i = 1; i <= r; i++) if (X[i] == m) valid[i] = FALSE;
            for (i = 1; i <= r; i++)
                if (valid[i]) { 
                    for (j = 0; j <= r; j++) for (k = 0; k <= r; k++) aux[j][k] = cap[j][k];
                    X[i] = min(X[i], m + maxflow(i, 0, aux));
                }
        }
        
        printf("Case %d: %d\n\n", c, X[1]);
    }
    
    return 0;
}
