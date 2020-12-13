/* The Problem with the problem setter */

#include <stdio.h>

typedef char bool;
#define TRUE 1
#define FALSE 0

#define MAXCATEGORIES 20
#define MAXPROBLEMS 1000
#define MAXGET 100
#define MAXV 1022
#define MAXDEGREE MAXPROBLEMS

typedef struct {
    int v;
    int capacity;
    int flow;
    int residual;
} edge;

typedef struct {
    edge edges[MAXV][MAXDEGREE];
    int degree[MAXV];
    int ncategories;
    int nproblems;
    int nvertices;
} graph;

/* Queue Definition */
typedef struct {
    int q[MAXV+1];
    int first;
    int last;
    int count;
} queue;

void init_queue(queue *q) {
    
    q -> first = 0;
    q -> last = MAXV-1;
    q -> count = 0;
}

void enqueue(queue *q, int x) {
    
    q -> last = (q->last + 1) % MAXV;
    q -> q[q -> last] = x;
    (q -> count)++;
}

int dequeue(queue *q) {
    
    int x;
    
    x = q -> q[q->first];
    q -> first = (q -> first+1) % MAXV; 
    (q -> count)--;

    return (x);
}

bool empty(queue *q) {
    
    if (q -> count <= 0) return TRUE;
    
    return FALSE;
}

int min(int a, int b) {

    if (a < b)
        return (a);
    else
        return (b);
}


bool discovered[MAXV];
int parent[MAXV];
graph g;
int c[MAXCATEGORIES];
int solution[MAXGET];

/* Graph Algorithms */
void initialize_search(graph *g);
bool valid_edge(edge e);
void bfs(graph *g, int start);
void netflow(graph *g, int source, int sink);
int path_volume(graph *g, int start, int end, int parents[]);
edge *find_edge(graph *g, int x, int y);
void augment_path(graph *g, int start, int end, int parents[], int volume);

void initialize_search(graph *g) {

    int i;
    for (i = 0; i < g->nvertices; i++) {
        discovered[i] = FALSE;
        parent[i] = -1;
    }
}

bool valid_edge(edge e) {
    
    if (e.residual > 0) return (TRUE);
    else return (FALSE);
}

/* Breadth-First Search */
void bfs(graph *g, int start) {

    queue q;
    int v;
    int i;
    
    init_queue(&q);
    enqueue(&q, start);
    discovered[start] = TRUE;
    while (empty(&q) == FALSE) {
        v = dequeue(&q);
        for (i = 0; i < g->degree[v]; i++)
            if (valid_edge(g->edges[v][i]) == TRUE)
                if (discovered[g->edges[v][i].v] == FALSE) {
                    enqueue(&q, g->edges[v][i].v);
                    discovered[g->edges[v][i].v] = TRUE;
                    parent[g->edges[v][i].v] = v;
                }
    }
}

void netflow(graph *g, int source, int sink) {

    int volume;
    
    initialize_search(g);
    bfs(g, source);
    
    volume = path_volume(g, source, sink, parent);
    
    while (volume > 0) {
        augment_path(g, source, sink, parent, volume);
        initialize_search(g);
        bfs(g, source);
        volume = path_volume(g, source, sink, parent);
    }
}

int path_volume(graph *g, int start, int end, int parents[]) {

    edge *e;
    
    if (parents[end] == -1) return (0);
    
    e = find_edge(g, parents[end], end);
    
    if (start == parents[end])
        return(e->residual);
    else
        return (min(path_volume(g, start, parents[end], parents), e->residual));
}

edge *find_edge(graph *g, int x, int y) {
    
    int i;
    
    for (i = 0; i < g->degree[x]; i++)
        if (g->edges[x][i].v == y)
            return(&g->edges[x][i]);
            
    return (NULL);
}

void augment_path(graph *g, int start, int end, int parents[], int volume) {

    edge *e;
    
    if (start == end) return;
    
    e = find_edge(g, parents[end], end);
    e->flow += volume;
    e->residual -= volume;
    
    e = find_edge(g, end, parents[end]);
    e->residual += volume;
    if ((e->v >= g->ncategories) && (e->v < g->ncategories+g->nproblems))
        e->flow -= volume;
    
    augment_path(g, start, parents[end], parents, volume);
}

void construct_graph(graph *g) {
    
    int i, j;
    int n;
    int cat;
    
    for (i = 0; i < g->nvertices; i++)
        g -> degree[i] = 0;
        
    for (i = 0; i < g->nproblems; i++) {
        scanf("%d", &n);
        for (j = 0; j < n; j++) {
            scanf("%d", &cat);
            g->edges[g->ncategories+i][g->degree[g->ncategories+i]].v = cat-1;
            g->edges[g->ncategories+i][g->degree[g->ncategories+i]].flow = 0;
            g->edges[g->ncategories+i][g->degree[g->ncategories+i]].residual = 0;
            g->edges[g->ncategories+i][g->degree[g->ncategories+i]].capacity = 1;
            g->degree[g->ncategories+i]++;
            g->edges[cat-1][g->degree[cat-1]].v = g->ncategories+i;
            g->edges[cat-1][g->degree[cat-1]].flow = 0;
            g->edges[cat-1][g->degree[cat-1]].capacity = 1;
            g->edges[cat-1][g->degree[cat-1]].residual = 1;
            g->degree[cat-1]++;
        }
    }
    for (i = 0; i < g->ncategories; i++) {
        g->edges[i][g->degree[i]].v = g->ncategories + g->nproblems;
        g->edges[i][g->degree[i]].flow = 0;
        g->edges[i][g->degree[i]].capacity = c[i];
        g->edges[i][g->degree[i]].residual = 0;
        g->degree[i]++;
        g->edges[g->ncategories+g->nproblems][g->degree[g->ncategories+g->nproblems]].v = i;
        g->edges[g->ncategories+g->nproblems][g->degree[g->ncategories+g->nproblems]].flow = 0;
        g->edges[g->ncategories+g->nproblems][g->degree[g->ncategories+g->nproblems]].capacity = c[i];
        g->edges[g->ncategories+g->nproblems][g->degree[g->ncategories+g->nproblems]].residual = c[i];
        g->degree[g->ncategories+g->nproblems]++;
    }
    for (i = g->ncategories; i < g->ncategories+g->nproblems; i++) {
        g->edges[i][g->degree[i]].v = g->ncategories + g->nproblems + 1;
        g->edges[i][g->degree[i]].flow = 0;
        g->edges[i][g->degree[i]].capacity = 1;
        g->edges[i][g->degree[i]].residual = 1;
        g->degree[i]++;
        g->edges[g->ncategories+g->nproblems+1][g->degree[g->ncategories+g->nproblems+1]].v = i;
        g->edges[g->ncategories+g->nproblems+1][g->degree[g->ncategories+g->nproblems+1]].flow = 0;
        g->edges[g->ncategories+g->nproblems+1][g->degree[g->ncategories+g->nproblems+1]].capacity = 1;
        g->edges[g->ncategories+g->nproblems+1][g->degree[g->ncategories+g->nproblems+1]].residual = 0;
        g->degree[g->ncategories+g->nproblems+1]++;
    }
}

bool get_solution(graph *g) {

    bool solved;
    int i, j;
    int n, cont;
    
    solved = TRUE;
    n = 0;
    for (i = 0; i < g->ncategories; i++) {
        cont = 0;
        for (j = 0; (j < g->degree[i]-1) && (cont < c[i]); j++)
            if (g->edges[i][j].flow) {
                solution[n] = g->edges[i][j].v-g->ncategories+1;
                n++;
                cont++;
            }
        if (cont < c[i])
            return (FALSE);
    }
    return (TRUE);
}


int main() {
    
    int nk, np;
    int i, j, n;
    
    while (scanf("%d %d", &nk, &np)) {
    
        if ((nk == 0) && (np == 0))
            break;
            
        g.ncategories = nk;
        g.nproblems = np;
        g.nvertices = np+nk+2;
        for (i = 0; i < nk; i++)
            scanf("%d", &c[i]);
        
        construct_graph(&g);
        netflow(&g, g.ncategories+g.nproblems, g.ncategories+g.nproblems+1);
        if (get_solution(&g) == FALSE) {
            putchar('0');
            putchar('\n');
        }
        else {
            putchar('1');
            putchar('\n');
            n = 0;
            for (i = 0; i < nk; i++) {
                for (j = 0; j < c[i]-1; j++)
                    printf("%d ", solution[n+j]);
                printf("%d\n", solution[n+j]);
                n+=c[i];
            }   
        }
    }
    
    return (0);
}
