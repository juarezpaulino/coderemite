/* Railroads */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char bool;
#define TRUE 1
#define FALSE 0

#define MAXINT 10000
#define MAXV 100
#define MAXDEGREE 1000
#define MAXCITIES 100
#define MAXNAME 50

typedef struct {
    int dept;
    int arrival;
} time;

typedef struct {
    int v;
    time t;
} edge;

typedef struct {
    edge edges[MAXV][MAXDEGREE];
    int degrees[MAXV];
    int nvertices;
} graph;


char city_names[MAXCITIES][MAXNAME];
time distance[MAXV];
int parent[MAXV];

int compare(const void *x, const void *y) {
    
    return (strcmp((char *)x, (char *)y));
}

int binary_search(char key[], int first, int last) {
    
    int pos, cmp;
    
    if (first > last)
        return (-1);
        
    pos = (first + last) / 2;
    cmp = strcmp(city_names[pos], key);
    if (!cmp)
        return (pos);
    else if (cmp > 0)
        return (binary_search(key, first, pos-1));
    else
        return (binary_search(key, pos+1, last));
}

void initialize_graph(graph *g) {
    
    int i;
    
    for (i = 0; i < g->nvertices; i++)
        g -> degrees[i] = 0;
}

void read_cities(int c) {

    int i;
    
    for (i = 0; i < c; i++)
        scanf("%s", city_names[i]);
}

void construct_graph(graph *g) {

    int t, ti, t_start, t_end, start, end;
    int i, j, pos;
    char name[MAXNAME];

    initialize_graph(g);
    
    scanf("%d", &t);
    for (i = 0; i < t; i++) {
        scanf("%d", &ti);
        
        scanf("%d %s", &t_start, name);
        start = binary_search(name, 0, g->nvertices-1);
        for (j = 1; j < ti; j++) {
            scanf("%d %s", &t_end, name);
            end = binary_search(name, 0, g->nvertices-1);
            g -> edges[start][g->degrees[start]].v = end;
            g -> edges[start][g->degrees[start]].t.dept = t_start;
            g -> edges[start][g->degrees[start]].t.arrival = t_end;
            g->degrees[start]++;
            start = end;
            t_start = t_end;
        }
    }
}

void dijkstra(graph *g, int start, int t) {

    int i, j;
    bool intree[MAXV];
    int v;
    int w;
    int arrival, dept, limit;
    int dist;
    
    for (i = 0; i < g->nvertices; i++) {
        intree[i] = FALSE;
        distance[i].arrival = MAXINT;
        distance[i].dept = -1;
        parent[i] = -1;
    }
    
    distance[start].arrival = 0;
    v = start;
    
    while (intree[v] == FALSE) {
        intree[v] = TRUE;
        for (i = 0; i < g->degrees[v]; i++) {
            if (v == start)
                limit = t;
            else
                limit = distance[v].arrival;
            if (g->edges[v][i].t.dept >= limit) {
                w = g -> edges[v][i].v;
                arrival = g -> edges[v][i].t.arrival;
                if (distance[w].arrival > arrival) {
                    distance[w].arrival = arrival;
                    parent[w] = v;
                    if (v == start)
                        distance[w].dept = g -> edges[v][i].t.dept;
                    else
                        distance[w].dept = distance[v].dept;
                }
                else if (distance[w].arrival == arrival)
                    if (g->edges[v][i].t.dept > distance[w].dept)
                        distance[w].dept = g->edges[v][i].t.dept;
            }
        }
        
        v = 0;
        dist = MAXINT;
        for (i = 0; i < g->nvertices; i++)
            if ((intree[i] == FALSE) && (dist > distance[i].arrival)) {
                dist = distance[i].arrival;
                v = i;
            }
    }
}

int get_dept(graph *g, int start, int end) {

    int i;
    int v;
    int max;
    
    v = parent[end];
    max = -1;
    if (v == start) {
        for (i = 0; i < g->degrees[v]; i++)
            if (g -> edges[v][i].v == end)
                if (g -> edges[v][i].t.arrival <= distance[end].arrival)
                    if (g -> edges[v][i].t.dept > max)
                        max = g -> edges[v][i].t.dept;
        return (max);
    }
    else {
        for (i = 0; i < g->degrees[v]; i++)
            if (g -> edges[v][i].v == end)
                if ((g -> edges[v][i].t.dept >= distance[v].arrival) && 
                ((g -> edges[v][i].t.dept <= distance[end].arrival)))
                    if (g -> edges[v][i].t.dept > max)
                        max = g -> edges[v][i].t.dept;
        distance[v].arrival = max;
        return (get_dept(g, start, v));
    }
                    
}

void print_graph(graph *g) {
    
    int i, j;
    
    for (i = 0; i < g -> nvertices; i++) {
        printf("%d: ", i);
        for (j = 0; j < g->degrees[i]; j++)
            printf(" %d-%d-%d", g -> edges[i][j].v, g -> edges[i][j].t.dept, g -> edges[i][j].t.arrival);
        putchar('\n');
    }
}


int main() {
    
    int cases, i;
    int c, start, end, t;
    char name[MAXNAME];
    graph g;
    
    scanf("%d", &cases);
    for (i = 1; i <= cases; i++) {
        
        scanf("%d", &c);
        getchar();
        read_cities(c);
        qsort(city_names, c, sizeof(char)*MAXNAME, compare);
        g.nvertices = c;
        construct_graph(&g);
        scanf("%d", &t);
        getchar();
        scanf("%s", name);
        start = binary_search(name, 0, c-1);
        scanf("%s", name);
        end = binary_search(name, 0, c-1);
        dijkstra(&g, start, t);
        
        printf("Scenario %d\n", i);
        if (distance[end].arrival == MAXINT)
            printf("No connection\n\n");
        else {
            distance[end].dept = get_dept(&g, start, end);
            printf("Departure %04d %s\n", distance[end].dept, city_names[start]);
            printf("Arrival   %04d %s\n\n", distance[end].arrival, city_names[end]);
        }
    }
    
    return 0;
}
