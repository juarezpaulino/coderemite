/* Fire Station */

#include <stdio.h>
#include <string.h>

typedef char bool;
#define TRUE 1
#define FALSE 0

#define MAXV 501
#define MAXSTATION 100
#define MAXINT 1000000

typedef struct {
    int v;
    int weight;
} edge;

typedef struct {
    edge edges[MAXV][MAXV];
    int degree[MAXV];
    int nvertices;
} graph;

bool location[MAXV];

void read_stations(int station[], int f, int n) {

    int i;
    
    for (i = 1; i <= n; i++)
        location[i] = FALSE;
    for (i = 0; i < f; i++) {
        scanf("%d", &station[i]);
        location[station[i]] = TRUE;
    }
    
    getchar();    
}

void read_graph(graph *g) {

    char str[20];
    int i;
    int x, y, w;
    
    for (i = 1; i <= g->nvertices; i++)
        g -> degree[i] = 0;
    
    if (gets(str) == NULL)
        return;
    while (*str != '\0') {
        sscanf(str, "%d %d %d", &x, &y, &w);
        g -> edges[x][g->degree[x]].v = y;
        g -> edges[x][g->degree[x]].weight = w;
        g->degree[x]++;
        g -> edges[y][g->degree[y]].v = x;
        g -> edges[y][g->degree[y]].weight = w;
        g->degree[y]++;
        if (gets(str) == NULL)
            break;
    }
}

void initialize_nearest(int nearest[], int n) {
    
    int i;
    
    for (i = 1; i <= n; i++)
        nearest[i] = MAXINT;
}

void dijkstra(graph *g, int start, int nearest[]) {

    int i, j, k;
    bool intree[MAXV];
    int distance[MAXV];
    int v;
    int w;
    int weight;
    int dist;
        
    for (i = 1; i <= g->nvertices; i++) {
        intree[i] = FALSE;
        distance[i] = MAXINT;
    }

    distance[start] = 0;
    v = start;

    while(intree[v] == FALSE){
        intree[v] = TRUE;
        for (i = 0; i < g->degree[v]; i++) {
            w = g->edges[v][i].v;
            weight = g->edges[v][i].weight;
            if (distance[w] > (distance[v]+weight))
                distance[w] = distance[v]+weight;
        }
        
        v = 1;
        dist = MAXINT;
        for (i = 1; i <= g->nvertices; i++)
            if ((intree[i] == FALSE) && (dist > distance[i])) {
                dist = distance[i];
                v = i;
            }
    }

    for (i = 1; i <= g->nvertices; i++)
        if (nearest[i] > distance[i])
            nearest[i] = distance[i];
}

int get_max(int nearest[], int n) {

    int i;
    int dist;
    
    dist = -1;
    for (i = 1; i <= n; i++)
        if (dist < nearest[i])
            dist = nearest[i];
    
    return (dist);
}


int main() {

    int cases, n, f, pos;
    int i, dist, max;
    int station[MAXSTATION];
    int nearest[MAXV], copy[MAXV];
    graph g;
    
    scanf("%d", &cases);
    while (cases) {
        
        scanf("%d %d", &f, &n);
        g.nvertices = n;
        read_stations(station, f, n);
        read_graph(&g);
        initialize_nearest(nearest, n);
        for (i = 0; i < f; i++)
            dijkstra(&g, station[i], nearest);
        pos = 1;
        max = MAXINT;
        for (i = 1; i <= n; i++)
            if (location[i] == FALSE) {
                memcpy(copy, nearest, sizeof(int) * MAXV);
                dijkstra(&g, i, copy);
                dist = get_max(copy, n);
                if (dist < max) {
                    max = dist;
                    pos = i;
                }
            }
        
        printf("%d\n", pos);
        
        cases--;
        if (cases)
            putchar('\n');    
    }
    
    return 0;
}
