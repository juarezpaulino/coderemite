/* Bicoloring */

#include <stdio.h>

#define C

#ifdef C
typedef char bool;
#define TRUE 1
#define FALSE 0
#undef C
#endif

#define MAXV 200
#define MAXDEGREE 200

typedef struct {
    int edges[MAXV][MAXDEGREE];
    int degree[MAXV];
    int nvertices;
    int nedges;
} graph;


int read_graph(graph *g, int m, bool directed);
void initialize_graph(graph *g);
void insert_edge(graph *g, int x, int y, bool directed);

int read_graph(graph *g, int m, bool directed) {
    
    int i, v;
    int x, y;
    
    scanf("%d %d", &x, &y);
    insert_edge(g, x, y, directed);
    v = x;
    for (i=1; i<m; i++) {
        scanf("%d %d", &x, &y);
        insert_edge(g, x, y, directed);
    }
    
    return (v);
}

void initialize_graph(graph *g) {
    
    int i;
    
    g -> nvertices = 0;
    g -> nedges = 0;
    
    for (i=0; i<MAXV; i++) g->degree[i] = 0;
}

void insert_edge(graph *g, int x, int y, bool directed) {
    
    g -> edges[x][g->degree[x]] = y;
    g -> degree[x]++;
    
    if (directed == FALSE)
        insert_edge(g, y, x, TRUE);
    else
        g -> nedges++;
}

bool processed[MAXV];
bool discovered[MAXV];
bool color[MAXV];
bool finished;
bool bicolor;

void process_vertex(int v, bool last) {

    if (last == FALSE)
        color[v] = TRUE;
    else
        color[v] = FALSE;
}

void initialize_search(graph *g) {
    
    int i;
    
    for (i = 0; i < g->nvertices; i++) {
        processed[i] = discovered[i] = FALSE;
        color[i] = -1;
    }
}

/* Depth_First Search */
void dfs(graph *g, int v, bool last) {
    
    int i;                          /* counter */
    int y;                          /* successor vertex */
    
    if (finished) return;           /* allow for search termination */
    
    discovered[v] = TRUE;
    process_vertex(v, last);
    
    for (i = 0; i < g->degree[v]; i++) {
        y = g->edges[v][i];
        if (discovered[y] == FALSE)
            dfs(g, y, !last);
        else
            if (color[y] == color[v]) {
                finished = TRUE;
                bicolor = FALSE;
            }
        if (finished) return;
    }
    
    processed[v] = TRUE;
}

int main() {

    graph g;
    int n, m, v, i;
    
    while (scanf("%d", &n)) {
        
        if (n == 0)
            break;
        
        initialize_graph(&g);
        g.nvertices = n;
        scanf("%d", &m);
        v = read_graph(&g, m, FALSE);
        
        initialize_search(&g);
        finished = FALSE;
        bicolor = TRUE;
        dfs(&g, v, FALSE);
        
        if (bicolor)
            printf("BICOLORABLE.\n");
        else
            printf("NOT BICOLORABLE.\n");
    }
    
    return 0;
}
