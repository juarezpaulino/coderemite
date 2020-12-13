/* Playing with wheels */

#include <stdio.h>
#include <stdlib.h>

#define C

#ifdef C
typedef char bool;
#define TRUE 1
#define FALSE 0
#undef C
#endif

#define MAXV 10000
#define MAXDEGREE 8

typedef struct {
    int edges[MAXV][MAXDEGREE];
    int degree[MAXV];
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

int compare(const void *x,  const void *y) {
    
    return(*(int *)x - *(int *)y);
}

bool binary_search(int f[], int key, int start, int end) {
    
    int pos;
    
    pos = (start + end)/2;
    if (start > end)
        return (FALSE);
    if (f[pos] == key)
        return TRUE;
    else if (f[pos] > key)
        return(binary_search(f, key, start, pos-1));
    else
        return(binary_search(f, key, pos+1, end));
}

void read_forbid(int f[], int n) {

    int i, j, aux;
    int v;
    
    for (i = 0; i < n; i++) {
        v = 0;
        for (j = MAXV/10; j >= 1; j /= 10) {
            scanf("%d%*c", &aux);
            v += (aux * j);
        }
        f[i] = v;
    }
}

void initialize_graph(graph *g) {
    
    int i;
    
    g -> nvertices = 0;
    
    for (i=0; i<MAXV; i++) g->degree[i] = 0;
}

void construct_graph(graph *g) {

    int v, y, z;
    int i, aux, num;

    initialize_graph(g);
    
    v = 0;
    while (v < MAXV) {
        for (i = 1, num = v; i < MAXV; i *= 10) {
            y = v;
            z = v;
            aux = num % 10;
            if (aux == 0)
                y += (9*i);
            else
                y -= (1*i);
            if (aux == 9)
                z -= (9*i);
            else
                z += (1*i);
                
            g -> edges[v][g->degree[v]] = y;
            g -> degree[v]++;
            g -> edges[v][g->degree[v]] = z;
            g -> degree[v]++;
            
            num /= 10;
        }
        v++;
    }
}


bool discovered[MAXV];
int parent[MAXV];

/* Breadth-First Search */              
void bfs(graph *g, int start, int target, int f[], int n) {

    queue q;
    int v;
    int i;
    
    init_queue(&q);
    enqueue(&q, start);
    discovered[start] = TRUE;
    
    while (empty(&q) == FALSE) {
        v = dequeue(&q);
        for (i = 0; i < g->degree[v]; i++)
            if (!binary_search(f, g->edges[v][i], 0, n))            
                if (discovered[g->edges[v][i]] == FALSE) {
                    enqueue(&q, g->edges[v][i]);
                    discovered[g->edges[v][i]] = TRUE;
                    parent[g->edges[v][i]] = v;
                    if (v == target)
                        return;
                }
    }
}

void initialize_search(graph *g) {
    
    int i;
    
    for (i = 0; i < g->nvertices; i++) {
        discovered[i] = FALSE;
        parent[i] = -1;
    }
}

void find_path(int start, int end, int parents[], int *count) {
    
    if ((start ==  end) || (end == -1))
        return;
    else {
        find_path(start, parents[end], parents, count);
        (*count)++;
    }
}


int main() {

    int N, n, count;
    int i, aux;
    int start, target;
    int forbid[MAXV];
    graph g;
    
    construct_graph(&g);
    g.nvertices = MAXV;
    
    scanf("%d", &N);
    getchar();
    getchar();
    while (N) {
        
        for (i = MAXV/10, start = 0; i >= 1; i /= 10) {
            scanf("%d%*c", &aux);
            start += (aux * i);
        }
        for (i = MAXV/10, target = 0; i >= 1; i /= 10) {
            scanf("%d%*c", &aux);
            target += (aux * i);
        }
        scanf("%d", &n);
        getchar();
        
        read_forbid(forbid, n);
        getchar();
        qsort(forbid, n, sizeof(int), compare);
        
        if (start == target) {
            if (!binary_search(forbid, start, 0, n))
            printf("0\n");
        }
        else {
            initialize_search(&g);
            bfs(&g, start, target, forbid, n);
            count = 0;
            if (parent[target] == -1)
                printf("-1\n");
            else {
                find_path(start, target, parent, &count);
                printf("%d\n", count);
            }
        }
        
        N--;
    }    
    
    return 0;
}
