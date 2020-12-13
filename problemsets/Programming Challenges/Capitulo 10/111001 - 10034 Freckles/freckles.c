/* Freckles */

#include <stdio.h>
#include <stdlib.h>

#define C

#ifdef C
typedef char bool;
#define TRUE 1
#define FALSE 0
#else
#define TRUE true
#define FALSE false
#endif

#define MAXV 100
#define MAXDEGREE MAXV
#define MAXFLOAT 1048577.0


typedef struct {
    int v;
    float weight;
} edge;

typedef struct {
    edge edges[MAXV][MAXDEGREE];
    int degree[MAXV];
    int nvertices;
} graph;

typedef struct {
    float x;
    float y;
} point;


float distance[MAXV];


void prim(graph *g, int start) {
    
    int i, j;
    bool intree[MAXV];
    int v;
    int w;
    float weight;
    float dist;
    
    for (i = 0; i < g->nvertices; i++) {
        intree[i] = FALSE;
        distance[i] = MAXFLOAT;
    }
    
    distance[start] = 0.0;
    v = start;
    
    while (intree[v] == FALSE) {
        intree[v] = TRUE;
        for (i = 0; i < g->degree[v]; i++) {
            w = g->edges[v][i].v;
            weight = g->edges[v][i].weight;
            if ((distance[w] > weight) && (intree[w] == FALSE))
                distance[w] = weight;
        }
        
        v = 0;
        dist = MAXFLOAT;
        for (i = 1; i < g->nvertices; i++)
            if ((intree[i] == FALSE) && (dist > distance[i])) {
                dist = distance[i];
                v = i;
            }
    }
}

void read_graph(graph *g) {

    int i, j;
    point *p;
    float x, y, dist;

    scanf("%d", &(g->nvertices));
    
    p = (point *) malloc (sizeof(point) * g->nvertices);
    for (i = 0; i < g->nvertices; i++)
        g->degree[i] = 0;
    for (i = 0; i < g->nvertices; i++) {
        scanf("%f %f", &x, &y);
        p[i].x = x;
        p[i].y = y;
        for (j = i-1; j >= 0; j--) {
            dist = sqrt(((p[j].x - x)*(p[j].x - x)) + ((p[j].y - y)*(p[j].y - y)));
            g->edges[i][g->degree[i]].v = j;
            g->edges[i][g->degree[i]].weight = dist;
            (g->degree[i])++;
            g->edges[j][g->degree[j]].v = i;
            g->edges[j][g->degree[j]].weight = dist;
            (g->degree[j])++;
        }
    }
    free(p);
}


int main() {
    
    int cases, i;
    float length;
    graph g;
    
    scanf("%d", &cases);
    while (cases) {
        
        read_graph(&g);
        prim(&g, 0);
        length = 0.0;
        for(i = 0; i < g.nvertices; i++)
            if (distance[i] != MAXFLOAT)
                length += distance[i];
        printf("%.2f\n", length);
        
        cases--;
        if (cases)
            putchar('\n');
    }
    
    return 0;
}
