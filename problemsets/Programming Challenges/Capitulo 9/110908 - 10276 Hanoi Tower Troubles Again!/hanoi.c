/* Hanoi Tower Troubles Again */

#include <stdio.h>
#include <math.h>

#define C

#ifdef C
typedef char bool;
#define TRUE 1
#define FALSE 0
#undef C
#endif

#define MAXV 2400
#define MAXDEGREE 70
#define MAXPEGS 50

typedef struct {
    int edges[MAXV+1][MAXDEGREE];
    int degree[MAXV+1];
    int nvertices;
} graph;

typedef struct {
    int balls[100];
    int top;
} peg;

graph g;
peg p[MAXPEGS];


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

bool possible(int a, int b) {
    
    int r;
    
    r = sqrt(a+b);
    if ((a+b) == (r*r))
        return (TRUE);
    else
        return (FALSE);
}

void construct_graph(graph *g) {

    int i;
    int r, k, p;
    
    for (i=1; i<=MAXV; i++) g->degree[i] = 0;
    
    for (r = 2; r < 70; r++) {
        p = r*r;
        for (k = p-1; k+k > p; k--) {
            g->edges[p-k][g->degree[p-k]] = k;
            g->degree[p-k]++;
        }
    }
}

void compute_indegrees(graph *g, int in[]) {

    int i,j;
    
    for (i=1; i<=g->nvertices; i++) in[i] = 0;
    
    for (i=1; i<=g->nvertices; i++)
        for (j=0; j<g->degree[i]; j++) 
            if (g->edges[i][j] <= g->nvertices) 
                in[g->edges[i][j]]++; 
            else 
                break;
}

bool topsort(graph *g, int n) {
    
    int indegree[MAXV];
    queue zeroin;
    int x, y;
    int i;
    int index;
    int maxin;

    compute_indegrees(g,indegree);
    init_queue(&zeroin);

    /*printf("Topsort:\nvertices:%d\nIndegrees:\n", g->nvertices);
    for (i = 1; i <= g->nvertices; i++)
        printf("%d: %d\n",i, indegree[i]);
    putchar('\n');*/
    for (i=1; i<=g->nvertices; i++)
        if (indegree[i] == 0) enqueue(&zeroin,i);
    
    while (empty(&zeroin) == FALSE) {
        if (zeroin.count > n)
            return (FALSE);
        x = dequeue(&zeroin);
        maxin = -1;
        for (i = 0; i < n; i++) {
            if (p[i].top == -1) {
                p[i].top = p[i].top + 1;
                p[i].balls[p[i].top] = x;
                index = -1;
                break;
            }
            else {
                if (possible(p[i].balls[p[i].top], x) && (x > p[i].balls[p[i].top])) {
                    if (indegree[p[i].balls[p[i].top]] > maxin) {
                        maxin = indegree[p[i].balls[p[i].top]];
                        index = i;
                    }
                }
            }
        }
        if (index != -1) {
            p[index].top = p[index].top + 1;
            p[index].balls[p[index].top] = x;
        }
                        
        for (i=0; (i<g->degree[x]) && (g->edges[x][i] <= g->nvertices); i++) {
            y = g->edges[x][i];
            indegree[y]--;
            if (indegree[y] == 0) enqueue(&zeroin,y);
        }
    }
    
    return (TRUE);
}

int maxballs(graph *g, int n) {
    
    int k, i, j;
    bool v;
    for (k = 1; k <= MAXV; k++) {
        
        g->nvertices = k;
        
        for (i = 0; i < n; i++) p[i].top = -1;
        v = topsort(g, n);
        /*for (i = 0; i < n; i++) {
            printf("%d: ", i);
            for (j = 0; j <= p[i].top; j++)
                printf("%d ", p[i].balls[j]);
            putchar('\n');
        }
        getchar();*/
        if (v == FALSE)
            break; 
    }
    
    return (k-1);
}

void print_graph(graph *g) {
    
    int i, j;
    
    for (i = 0; i < 3001; i++) {
        printf("%d: ", i);
        for (j = 0; j < g->degree[i]; j++)
            printf(" %d", g -> edges[i][j]);
        putchar('\n');
    }
}


int main() {
    
    int t, n;
    
    //scanf("%d", &t);

    construct_graph(&g);
    //print_graph(&g);
       
        
        
        for (n = 1; n < 51; n++)
            printf("f[%d] = %d;\n", n, maxballs(&g, n));
       
    
    return 0;
}
