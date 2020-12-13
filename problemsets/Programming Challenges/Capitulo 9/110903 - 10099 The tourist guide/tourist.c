/* The tourist guide */

#include <stdio.h>

#define C

#ifdef C
typedef char bool;
#define TRUE 1
#define FALSE 0
#endif

#define MAXV 102
#define MAXDEGREE 102
#define  INFINITY 1000000000

typedef struct {
    int linked;
    int weight;
} connection;

typedef struct {
    connection edges[MAXV+1][MAXDEGREE];
    int degree[MAXV+1];
    int nvertices;
} graph;

/* Queue Definition */
typedef struct {
    int q[(MAXV*MAXV)+1];
    int first;
    int last;
    int count;
} queue;

void init_queue(queue *q) {
    
    q -> first = 0;
    q -> last = (MAXV*MAXV)-1;
    q -> count = 0;
}

void enqueue(queue *q, int x) {
    
    q -> last = (q->last + 1) % (MAXV*MAXV);
    q -> q[q -> last] = x;
    (q -> count)++;
}

int dequeue(queue *q) {
    
    int x;
    
    x = q -> q[q->first];
    q -> first = (q -> first+1) % (MAXV*MAXV); 
    (q -> count)--;
    return (x);
}

bool empty(queue *q) {
    
    if (q -> count <= 0) return TRUE;
    return FALSE;
}

void initialize_graph(graph *g) {
    
    int i;
    
    for (i=1; i<=MAXV; i++) g->degree[i] = 0;
}

void insert_edge(graph *g, int x, int y, int w, bool directed) {
    
    g -> edges[x][g->degree[x]].linked = y;
    g -> edges[x][g->degree[x]].weight = w;
    g -> degree[x]++;
    
    if (directed == FALSE)
        insert_edge(g, y, x, w, TRUE);
}

void read_graph(graph *g, int m, bool directed) {
    
    int i;
    int x, y, w;
    
    initialize_graph(g);
    for (i=1; i<=m; i++) {
        scanf("%d %d %d", &x, &y, &w);
        insert_edge(g, x, y, w, directed);
    }
}

int inpeople[MAXV+1];

/* Breadth-First Search */              
void bfs(graph *g, int start) {

    queue q;
    int v, min;
    int i;
    
    init_queue(&q);
    enqueue(&q, start);
    inpeople[start] = INFINITY;
    
    while (empty(&q) == FALSE) {
        v = dequeue(&q);
        for (i = 0; i < g->degree[v]; i++) {
            if (g->edges[v][i].weight < inpeople[v])
                min = g->edges[v][i].weight;
            else
                min = inpeople[v];
            if (min > inpeople[g->edges[v][i].linked]) {
                inpeople[g->edges[v][i].linked] = min;
                enqueue(&q, g->edges[v][i].linked);
            }
        }
    }
}

void initialize_search(graph *g) {
    
    int i;
    
    for (i = 1; i <= g->nvertices; i++)
        inpeople[i] = -1;
}


int main() {

    int N, R, start, end, ppl, min, trips, scenario, i;
    graph g;
    
    scenario = 1;
    while (scanf("%d %d", &N, &R)) {
    
        if ((N == 0) && (R == 0))
            break;
            
        g.nvertices = N;
        read_graph(&g, R, FALSE);
        scanf("%d %d %d", &start, &end, &ppl);
        
        if (start == end)
            trips = 0;
        else {
            initialize_search(&g);
            bfs(&g, start);
            min = inpeople[end];
            trips = (ppl/(min-1));
            if (ppl%(min-1))
                trips++;
        }
        
        printf("Scenario #%d\n", scenario);
        printf("Minimum Number of Trips = %d\n\n", trips);
        scenario++;
    }    
    
    return 0;
}

