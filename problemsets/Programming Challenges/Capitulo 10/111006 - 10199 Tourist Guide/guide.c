/* Tourist Guide */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char bool;
#define TRUE 1
#define FALSE 0

#define MAXNAME 32
#define MAXCITIES 100
#define MAXV MAXCITIES
#define MAXDEGREE MAXV

typedef struct {
    int edges[MAXV][MAXDEGREE];
    int degree[MAXV];
    int vertices[MAXV];
    int part[MAXV];
    int nvertices;
} graph;


char city_names[MAXCITIES][MAXNAME];
bool cameras[MAXV];
int total;

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

void construct_graph(graph *g) {
    
    int i;
    int r;
    int pos1, pos2;
    char city1[MAXNAME], city2[MAXNAME];
    
    for (i = 0; i < g->nvertices; i++)
        g -> degree[i] = 0;
    
    scanf("%d", &r);
    getchar();
    for (i = 0; i < r; i++) {
        scanf("%s %s", city1, city2);
        pos1 = binary_search(city1, 0, g->nvertices-1);
        pos2 = binary_search(city2, 0, g->nvertices-1);
        g -> edges[pos1][g->degree[pos1]] = pos2;
        g -> degree[pos1]++;
        g -> edges[pos2][g->degree[pos2]] = pos1;
        g -> degree[pos2]++;
    }
}

void compute_trivial(graph *g) {
 
    int i;
    
    for (i = 0; i < g->nvertices; i++)
        if ((g->degree[i] == 1) && (g -> degree[g->edges[i][0]] > 1) && (cameras[g->edges[i][0]] == FALSE)) {
            total++;
            cameras[g->edges[i][0]] = TRUE;
        }
}

void dfs_comp(graph *g, int v, int *pieces, bool discovered[], int comp[]) {

    int i;
    int y;
    
    discovered[v] = TRUE;
    comp[*pieces] = v;
    (*pieces)++;
    
    for (i = 0; i < g->degree[v]; i++) {
        y = g->edges[v][i];
        if (discovered[y] == FALSE)
            dfs_comp(g, y, pieces, discovered, comp);
    }
}

void connected_components(graph *g) {

    int pieces;
    int i, j, aux;
    bool discovered[MAXV];
    int comp[MAXV];
    
    for (i = 0; i < g->nvertices; i++)
        discovered[i] = FALSE;
    
    for (i = 0; i < g->nvertices; i++)
        if (discovered[i] == FALSE) {
            pieces = 0;
            dfs_comp(g, i, &pieces, discovered, comp);
            for (j = 0; j < pieces; j++) {
                g -> vertices[comp[j]] = pieces;
                g -> part[comp[j]] = comp[(j+1)%pieces];
            }
        }
    
}

void dfs(graph *g, int exclude,  int v, bool discovered[], int *connected) {

    int i;
    int y;
    
    discovered[v] = TRUE;
    (*connected)++;
    
    for (i = 0; i < g->degree[v]; i++) {
        y = g->edges[v][i];
        if ((y != exclude) && (discovered[y] == FALSE))
            dfs(g, exclude, y, discovered, connected);
    }
}


int main() {

    int n;
    int i, j, scenario;
    int connected;
    graph g;
    bool discovered[MAXV];
    
    scenario = 1;
    while (scanf("%d", &n)) {
        getchar();
        
        if (n == 0)
            break;
            
        if (scenario > 1)
            putchar('\n');
        
        g.nvertices = n;
        for (i = 0; i < n; i++)
            scanf("%s", city_names[i]);
        qsort(city_names, n, sizeof(char)*MAXNAME, compare);
        
        construct_graph(&g);
        
        for (i = 0; i < g.nvertices; i++)
            cameras[i] = FALSE;
        total = 0;
        compute_trivial(&g);
        connected_components(&g);
        
        for (i = 0; i < g.nvertices; i++)
            if ((cameras[i] == FALSE) && (g.degree[i] > 1)) {
                for (j = 0; j < g.nvertices; j++)
                    discovered[j] = FALSE;
                connected = 0;
                dfs(&g, i, g.part[i], discovered, &connected);
                if (connected < g.vertices[i]-1) {
                    cameras[i] = TRUE;
                    total++;
                }
            }
        
        printf("City map #%d: %d camera(s) found\n", scenario, total);
        for (i = 0; i < g.nvertices; i++)
            if (cameras[i] == TRUE)
                printf("%s\n", city_names[i]);
        scenario++;
    }   
    
    return 0;
}
