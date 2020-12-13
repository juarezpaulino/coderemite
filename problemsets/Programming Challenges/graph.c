/* Graph algorithms */

typedef char bool;
#define TRUE 1
#define FALSE 0

#define MAXV 100                        /* maximum number of vertices */
#define MAXDEGREE 50                    /* maximum vertex outdegree */

typedef struct {
    int edges[MAXV+1][MAXDEGREE];       /* adjacency info */
    int degree[MAXV+1];                 /* outdegree of each vertex */
    int nvertices;                      /* number of vertices in graph */
    int nedges;                         /* number of edges in graph */
} graph;

void read_graph(graph *g, bool directed);
void initialize_graph(graph *g);
void insert_edge(graph *g, int x, int y, bool directed);

void read_graph(graph *g, bool directed) {
    int i;              /* counter */
    int m;              /* number of edges */
    int x, y;           /* vertices in edge (x,y) */
    initialize_graph(g);
    scanf("%d %d", &(g->nvertices), &m);
    for (i=1; i<=m; i++) {
        scanf("%d %d", &x, &y);
        insert_edge(g, x, y, directed);
    }
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

void print_graph(graph *g) {
    int i, j;
    for (i = 0; i < g -> nvertices; i++) {
        printf("%d: ", i);
        for (j = 0; j < g->degree[i]; j++)
            printf(" %d", g -> edges[i][j]);
        putchar('\n');
    }
}

/* Global Variables */
bool processed[MAXV];           /* which vertices have been processed */
bool discovered[MAXV];          /* which vertices have been found */
int parent[MAXV];               /* discovery relation */
bool finished;                  /* allow termination in dfs */

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

/* Traversal algorithms */
bool valid_edge(int edge);
void process_vertex(int v);
void process_edge(int x, int y);

/* Breadth-First Search */
void bfs(graph *g, int start) {
    queue q;                    /* queue of vertices to visit */
    int v;                      /* current vertex */
    int i;                      /* counter */
    init_queue(&q);
    enqueue(&q, start);
    discovered[start] = TRUE;
    while (empty(&q) == FALSE) {
        v = dequeue(&q);
        process_vertex(v);
        processed[v] = TRUE;
        for (i = 0; i < g->degree[v]; i++)
            if (valid_edge(g->edges[v][i]) == TRUE) {
                if (discovered[g->edges[v][i]] == FALSE) {
                    enqueue(&q, g->edges[v][i]);
                    discovered[g->edges[v][i]] = TRUE;
                    parent[g->edges[v][i]] = v;
                }
                if (processed[g->edges[v][i]] == FALSE)
                    process_edge(v, g->edges[v][i]);
            }
    }
}

/* Depth_First Search */
void dfs(graph *g, int v) {
    int i;                          /* counter */
    int y;                          /* successor vertex */
    if (finished) return;           /* allow for search termination */
    discovered[v] = TRUE;
    process_vertex(v);
    for (i = 0; i < g->degree[v]; i++) {
        y = g->edges[v][i];
        if (valid_edge(g->edges[v][i]) == TRUE) {
            if (discovered[y] == FALSE) {
                parent[y] = v;
                dfs(g, y);
            }
            else if (processed[y] == FALSE)
                process_edge(v, y);
        }
        if (finished) return;
    }
    processed[v] = TRUE;
}

bool valid_edge(int edge) {
    return TRUE;
}

void initialize_search(graph *g) {
    int i;
    for (i = 0; i < g->nvertices; i++) {
        processed[i] = discovered[i] = FALSE;
        parent[i] = -1;
    }
}

void find_path(int start, int end, int parents[]) {
    if ((start ==  end) || (end == -1))
        printf("\n%d", start);
    else {
        find_path(start, parents[end], parents);
        printf(" %d", end);
    }
}

void connected_components(graph *g) {
    int c;
    int i;
    initialize_search(g);
    c = 0;
    for (i = 1; i <= g->nvertices; i++)
        if (discovered[i] == FALSE) {
            c++;
            printf("Component %d:", c);
            dfs(g, i);
            printf("\n");
        }
}

/*       Network Flow       */
short cap[MAXV][MAXV];
short p[MAXV];

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

/*      Dijkstra        */
typedef struct {
    double d;
    int h;
} vertex;

#define LEFT(i) ((i)<<1)
#define RIGHT(i) (((i)<<1)|1)
#define PAI(i) ((i)>>1)

int H[MAXV];
int heapsize;
vertex vert[MAXV];

void insertUpdate(int *H, int v) {
    int i = vert[v].h;
    if (i == 0) i = ++heapsize;
    while ((i > 1) && (vert[H[PAI(i)]].d > vert[v].d)) {
        H[i] = H[PAI(i)];
        vert[H[PAI(i)]].h = i;
        i = PAI(i);
    }
    H[i] = v;
    vert[v].h = i;
}

void corrige(int *H, int i) {
    int min, aux;
    int l = LEFT(i), r = RIGHT(i);
    if ((l <= heapsize) && (vert[H[l]].d < vert[H[i]].d)) min = l; 
    else min = i;
    if ((r <= heapsize) && (vert[H[r]].d < vert[H[min]].d)) min = r;
    if (min != i){
        aux = H[i];
        H[i] = H[min]; vert[H[min]].h = i;
        H[min] = aux; vert[aux].h = min;
        corrige(H, min);
    }
}

int minimum(int *H) {
    int l,r;
    int ret = H[1];
    H[1] = H[heapsize--];
    vert[H[1]].h = 1;
    corrige(H, 1);
    return ret;
}

void dijkstra(int s) {
    int i;
    int j;
    int v;
    heapsize = 0;
    for( i = 0; i < n+2; i++ ) {
        vert[i].d = 1E14; 
        vert[i].h = 0;
    }
    vert[s].d = 0.0;
    insertUpdate(H, s);
    while ( heapsize > 0 ) {
        i = minimum(H);
        vert[i].h = -1;
        for (j = 0; j < g.degree[i]; j++) {
            v = g.edges[i][j].v;
            if (vert[v].h >= 0)
                if (vert[v].d > vert[i].d + g.edges[i][j].wg) {
                    vert[v].d = vert[i].d + g.edges[i][j].wg;
                    insertUpdate(H, v);
                }
        }
    }
