/* The Necklace */

#include <stdio.h>

#define MAXV 51
#define MAXBEADS 1000

typedef char bool;
#define TRUE 1
#define FALSE 0

typedef struct {
    int adj[MAXV][MAXV];
    int degrees[MAXV];
    int edges;
} graph;

typedef struct {
    int x;
    int y;
} bead;

/* Queue Definition */
typedef struct {
    bead q[MAXBEADS];
    int first;
    int last;
    int count;
} queue;

void init_queue(queue *q) {
    
    q -> first = 0;
    q -> last = MAXBEADS-1;
    q -> count = 0;
}

void enqueue(queue *q, bead x) {
    
    q -> last = (q->last + 1) % MAXBEADS;
    q -> q[q -> last] = x;
    (q -> count)++;
}

bead dequeue(queue *q) {
    
    bead x;
    
    x = q -> q[q->first];
    q -> first = (q -> first+1) % MAXBEADS; 
    (q -> count)--;

    return (x);
}

bool empty(queue *q) {
    
    if (q -> count <= 0) return TRUE;
    
    return FALSE;
}

bead see_back(queue *q) {
    
    bead x;
    x = q -> q[q->last];   
    return(x);
}

bead see_front(queue *q) {
    
    bead x;
    x = q -> q[q->first];
    return(x);
}

void turn_queue(queue *q) {
    
    q -> first = (q -> first + MAXBEADS - 1) % MAXBEADS;
    q -> q[q->first] = q -> q[q->last];
    q -> last = (q -> last + MAXBEADS - 1) % MAXBEADS;
}

void print_queue(queue *q) {
    
    bead b;
    
    while (!empty(q)) {
        b = dequeue(q);
        printf("%d %d\n",  b.x, b.y);
    }
}


void read_graph(graph *g, bead *start) {
    
    int i, j, x, y;
    
    for (i = 1; i < MAXV; i++) {
        g -> degrees[i] = 0;
        for (j = 1; j < MAXV; j++)
            g -> adj[i][j] = 0;
    }
    
    scanf("%d", &(g -> edges));
    scanf("%d %d", &x, &y);
    g -> adj[x][y]++;
    g -> adj[y][x]++;
    g -> degrees[x]++;
    g -> degrees[y]++;
    start -> x = x;
    start -> y = y;
    for (i = 1; i < g->edges; i++) {
        scanf("%d %d", &x, &y);
        g -> adj[x][y]++;
        g -> adj[y][x]++;
        g -> degrees[x]++;
        g -> degrees[y]++;
    }
}

bool check_parity(graph *g) {
    
    int i;
    
    for (i = 1; i < MAXV; i++)
        if (g -> degrees[i] % 2)
            return FALSE;
    return TRUE;
}

int search_edge(graph *g, int x) {
    
    int i;
    
    for (i = 1; i < MAXV; i++)
        if (g -> adj[x][i] != 0)
            return (i);
    return (-1);
}

bool discovered[MAXV];

bool euler_cycle(graph *g, bead *start, queue *q) {

    int i, c;
    bead aux, front;

    for (i = 1; i < MAXV; i++)
        discovered[i] = FALSE;
        
    init_queue(q);
    
    enqueue(q, *start);
    discovered[start -> x] = TRUE;
    discovered[start -> y] = TRUE;
    g -> adj[start->x][start->y]--;
    g -> adj[start->y][start->x]--;
    g -> degrees[start->x]--;
    g -> degrees[start->y]--;
    g -> edges--;    
    while (g -> edges) {
        aux = see_back(q);
        aux.x = aux.y;
        if ((aux.y = search_edge(g, aux.x)) == -1)
           return (FALSE);
        enqueue(q, aux);
        g -> adj[aux.x][aux.y]--;
        g -> adj[aux.y][aux.x]--;
        g -> degrees[aux.x]--;
        g -> degrees[aux.y]--;
        g -> edges--;
        if (!g -> edges)
            break;
        if (discovered[aux.y]) {
            c = 0;
            while (!(g -> degrees[aux.y])) {
                if (c == q -> count - 1)
                    return (FALSE);
                c++;
                turn_queue(q);
                aux = see_back(q);
            }
        }
        else
            discovered[aux.y] = TRUE;
    }
    front = see_front(q);
    if (front.x != aux.y)
        return (FALSE);
    else
        return (TRUE);
}


int main() {

    int cases, i;
    graph g;
    bead start;
    bool cycle;
    queue q;
    
    scanf("%d", &cases);
    for (i = 1; i <= cases; i++) {
        
        read_graph(&g, &start);
        cycle = check_parity(&g);
        if (cycle)
            cycle = euler_cycle(&g, &start, &q);
        
        printf("Case #%d\n", i);
        if (!cycle)
            printf("some beads may be lost\n");
        else
            print_queue(&q);
        
        if (i < cases)
            putchar('\n');    
    }
    
    return 0;
}
