/* Tower of Cubes */

#include <stdio.h>

typedef char bool;
#define TRUE 1
#define FALSE 0

#define MAXV 500
#define MAXDEGREE MAXV*6
#define MAXCUBES 500

char opposite[] = {'1'-'0', '0'-'0', '3'-'0', '2'-'0', '5'-'0', '4'-'0'};

typedef struct {
    char colors[6];
} cube;

typedef struct {
    int out;
    char top;
} edge;

typedef struct {
    edge edges[MAXV][MAXDEGREE];
    int degree[MAXV];
    int nvertices;
} graph

cube cubes[MAXCUBES];
graph g;


void initialize_graph(graph *g) {
    
    int i;
    
    for (i = 0; i < g.nvertices; i++)
        g -> degree[i] = 0;
    
}

void make_connection(int m, int N) {

    int i, j, k;
    
    for (j = 0; j < 6; j++)
        for (i = m+1; i < N; i++)
            for (k = 0; k < 6; k++)
                if (cubes[m].color[j] == cubes[i].color[k]) {
                    g.edges[m][g.degree[m]].out = i;
                    g.edges[m][g.degree[m]].top = j;
                    g.degree[m]++;
                }
}

void read_cubes(int N) {
    
    int i, j;

    initialize_graph(&g);
    for (i = N-1; i >= 0; i--) {
        for (j = 0; j < 6; j++)
            scanf("%d", &cubes[i].colors[j]);
        make_connection(i, N);
    }
}

void dfs(int start, graph *g) {

    int i;
    
    for (i = 0; i < )
}


int main() {

    int N;
    
    while (scanf("%d", &N)) {
    
        if (N == 0)
            break;
       
        g.nvertices = N;
        read_cubes(N);
    }
    
    return 0;
}
